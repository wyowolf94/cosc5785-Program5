// Shaya Wolf
// Program 5
// cosc5785 - Compilers
// 11/16/2017

#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

#include "symbol.h"

//#define INVALIDSYM "invalid symbol"
#define CONSTRTYPE "Constructor"
#define METHODTYPE "Method"
#define CLASSTYPE "Class"
#define BLOCKTYPE "Block"

using std::string;
using std::to_string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;
using std::unordered_map;
using std::pair;


class SymbolTable 
{
  public:
    // Constructor
    SymbolTable(SymbolTable * p, string id) {
      parent = p;
      iden = id;
      level = parent->level + 1;
    } 
    
    SymbolTable() {
      parent = 0;
      iden = "root";
      level = 0;
    }

    // Destructor
    virtual ~SymbolTable() {
      delete parent;
      
      vardecs.clear();
      order.clear();       
      children.clear(); 
    }
    
    string getIden() {
      return iden;
    }
    
    void setIden(string id) {
      iden = id;
    }
    
    unordered_map<string, SymbolTable*> getChildren() {
      return children;
    }
    
    string lookup_children(Variable* var) {
      string name = mangle(var->iden);
      unordered_map<string,Variable*>::const_iterator newvar
        = vardecs.find(name);
      if(newvar != vardecs.end()) {
        return newvar->second->type;
      }
      
      return INVALIDSYM;
    }
    
    string lookup_children(SymbolTable* st) {
      string name = st->mangle();
      unordered_map<string,SymbolTable*>::const_iterator child
        = children.find(name);
      if(child != children.end()) {
        return child->second->return_type();
      }
      return INVALIDSYM;
    }
    
    string lookup_siblings(Variable* var) {
      if(parent != 0) {
        return parent->lookup_children(var);
      } else {
        return INVALIDSYM;
      }
    }    
    
    string lookup_siblings(SymbolTable* st) {
      if(parent != 0) {
        return parent->lookup_children(st);
      } else {
        return INVALIDSYM;
      }
    }
    
    string lookup_ancestors(Variable* var) {
      //string name = mangle(var->iden);
      string type = lookup_siblings(var);
      
      if(type != INVALIDSYM) {
        return type;
      }
      
      if(parent == 0){
        return INVALIDSYM;
      }

      return parent->lookup_ancestors(var);
    }
    
    string lookup_ancestors(SymbolTable* st) {
      //string name = st->mangle(st->iden);
      string type = lookup_siblings(st);
      
      if(type != INVALIDSYM) {
        return type;
      }

      if(parent == 0) {
        return INVALIDSYM;
      } 
    
      return parent->lookup_ancestors(st);
    }
    
    // Mangles the identifier of a child being added
    virtual string mangle(string name) {
      return '$' + name + '$';
    }

    virtual string mangle() {
      return "root";
    }
    
    // Unmangles the identifier by taking the iden out
    // from the mangled name
    string unmangle(string name) {
      size_t pos = name.find("$");
      return name.substr(1, pos);
    }
    
    virtual string return_type() {
      return "";
    }
    
    // Adds a symbol table child
    bool addChild(SymbolTable* st) {
      if(st != 0) {
        string new_iden = st->mangle();
        pair<string, SymbolTable*> newChild (new_iden, st);
        pair<unordered_map<string,SymbolTable*>::const_iterator,bool> 
          ok = children.insert(newChild);
        if(ok.second) {
          order.push_back(new_iden);
          return true;
        } 
      }
      return false;
    }

    // Look up variable in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(Variable * var) {
      //string mangled = mangle(var->iden);
      if(lookup_children(var) != INVALIDSYM) {
        return false;
      } 
      
      /*string name = mangle(var->iden);   
      unordered_map<string,SymbolTable*>::const_iterator child
        = children.find(name);
      if(child != children.end()) {
        return false;
      }*/
      
      pair<string, Variable*> newVar (mangle(var->iden), var);
      vardecs.insert(newVar);
      return true;
    }
    
    // Look up method in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(SymbolTable * method) {
      //string mangled = method->mangle(method->iden);
      if(lookup_children(method) != INVALIDSYM) {
        return false;
      }
      
      
      
      return addChild(method);
    }
     
    // Print SymbolTable and all of it's decendents in-order
    virtual void printTable() {
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      }
    }
  
  protected:
    string type;
    string iden;
    int level;
    
    SymbolTable * parent;
    
    unordered_map<string, Variable*> vardecs;
    unordered_map<string, SymbolTable*> children;
    vector<string> order;
};

class ClassDec : public SymbolTable
{
  public:
    ClassDec(SymbolTable * p, string id) : SymbolTable (p, id) {
      type = CLASSTYPE;
      iden = id;
    } 
    
    string mangle() {
      return '$' + iden + '$';
    }

    string return_type() {
      return iden;
    }
    
    void printTable() {
      cout << type << " -> " << iden << endl;
      
      for(auto it = vardecs.begin(); it != vardecs.end(); ++it) {
        cout << "  " << it->second->type 
             << "  " << it->second->iden 
             << endl;
      }
      
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      }
    }

};

class MethodDec : public SymbolTable
{
  public:
    MethodDec(SymbolTable * p, string id) : SymbolTable (p, id) {
      type = METHODTYPE;
      iden = id;
    } 

    bool add_param (Variable* param) {
      if(param != 0) {
        params.push_back(param);
        return true;
      }
      return false;
    }
    
    void setParams(vector<Variable*> new_params) {
      params = new_params;
    }
    
    vector<Variable*> getParams() {
      return params;
    }
    
    string mangle() {
      string temp = '$' + iden + '$';
      for(unsigned int i = 0; i < params.size(); i++) {
        temp = temp + params[i]->type + '$';
      }
      return temp;
    }
    
    void set_returnType (string new_type) {
      returnType = new_type;
    }
    
    string return_type() {
      return returnType;
    }
   
    void set_return_type(string type) {
      returnType = type;
    }
 
    void printTable() {
      cout << "  "
           << type << " -> " 
           << "  " << returnType 
           << "  " << iden;
           
      printParams(params);
      
      for(auto it = vardecs.begin(); it != vardecs.end(); ++it) {
        cout << "  " 
             << "  " << it->second->type 
             << "  " << it->second->iden
             << endl;
      }
      
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      }
    }
    
  private:
    string returnType;
    vector<Variable*> params;    
};

class ConstrDec : public SymbolTable
{
  public:
    ConstrDec(SymbolTable * p, string id) : SymbolTable (p, id) {
      type = CONSTRTYPE;
      iden = id;
    } 

    bool add_param (Variable* param) {
      if(param != 0) {
        params.push_back(param);
        return true;
      }
      return false;
    }
    
    string mangle() {
      string temp = '$' + iden + '$';
      for(unsigned int i = 0; i < params.size(); i++) {
        temp = temp + params[i]->type + '$';
      }
      return temp;
    }
    
    void setParams(vector<Variable*> new_params) {
      params = new_params;
    }
    
    vector<Variable*> getParams() {
      return params;
    }
    
    string return_type() {
      return iden;
    }
    
    void printTable() {        
      cout << "  " << type << " -> " 
           << "  " << iden;
           
      printParams(params);
      
      for(auto it = vardecs.begin(); it != vardecs.end(); ++it) {
        cout << "  " 
             << "  "   << it->second->type 
             << "  "   << it->second->iden 
             << endl;
      }
      
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      }
    }
    
  private:
    vector<Variable*> params;    
};

class BlockDec : public SymbolTable
{
  public:
    BlockDec(SymbolTable * p, string id) : SymbolTable (p, id) {
      type = BLOCKTYPE;
      iden = id;
    } 
    
    string return_type() {
      return BLOCKTYPE;
    }

    string mangle() {
      return '$' + iden + '$';
    }
    
    string getNewName() {
      int randNum = 0;
      string possible = "";
      string possibleMangled = "";
      while(1) {
        randNum = rand() % 10000000;
        
        possible = iden + to_string(randNum);
        possibleMangled = '$' + possible + '$';
        
        if(parent != 0) {
          unordered_map<string,SymbolTable*>::const_iterator found
            = parent->getChildren().find(possibleMangled);
          if(found == parent->getChildren().end()) {
            return possible;
          }
        } else { // parent == 0 so this is the root and has no parent/siblings
          return INVALIDSYM;
        }
      }
    }
    
    void printTable() {
      string indent = "";
      for(int i = 1; i < level-1; i++) {
        indent = indent + "  ";
      } 
          
      if(iden.find("class_") != 0) {
        cout << indent << type << " -> " << endl;
      } 
      
      for(auto it = vardecs.begin(); it != vardecs.end(); ++it) {
        if(iden.find("class_") == 0) {
          cout << "  ";
        }
        cout << indent 
             << it->second->type 
             << "  " << it->second->iden
             << endl;
      }
        
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      } 
    } // end printTable()
};

#endif
