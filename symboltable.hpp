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

#define INVALIDVAR "invalid variable"
#define INVALIDMETHOD "invalid method"
#define INVALIDSYM "invalid symbol"
#define CONSTRTYPE "Constructor"
#define METHODTYPE "Method"
#define CLASSTYPE "Class"
#define BLOCKTYPE "Block"

using std::string;
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
    
    string lookup_here(Variable* var) {
        string name = mangle(var->iden);
        unordered_map<string,Variable*>::const_iterator newvar
          = vardecs.find(name);
        if(newvar != vardecs.end()) {
          return newvar->second->type;
        }
        return INVALIDSYM;
    }
    
    string lookup_here(SymbolTable* st) {
        string name = st->mangle(st->iden);
        unordered_map<string,SymbolTable*>::const_iterator child
          = children.find(name);
        if(child != children.end()) {
          return child->second->return_type();
        }
        return INVALIDSYM;
    }
    
    // Looks up mangled name and return INVALIDSYM if it isn't here
    /*string lookup_here(string iden) {
      // Check the vars
      unordered_map<string,Variable*>::const_iterator var 
        = vardecs.find(iden);
      if(var != vardecs.end()) {
        return var->second->type;
      } 
      
      // Check the children, but not all decendents
      unordered_map<string,SymbolTable*>::const_iterator child 
        = children.find(iden);
      if(child != children.end()) {
        child->second->return_type();
      }
      
      return INVALIDSYM;
    }*/
    
    string lookup_all(Variable* var) {
      //string name = mangle(var->iden);
      string type = lookup_here(var);
      if(type != INVALIDSYM) {
        return type;
      }
      
      if(parent == 0){
        return INVALIDSYM;
      }

      return parent->lookup_all(var);
    }
    
    string lookup_all(SymbolTable* st) {
      //string name = st->mangle(st->iden);
      string type = lookup_here(st);
      if(type != INVALIDSYM) {
        return type;
      }

      if(parent == 0) {
        return INVALIDSYM;
      } 
    
      return parent->lookup_all(st);
    }
    
    // Looks up a variable in this symbol table and all of it's ancestors
    // If it exists, return it's type, if not, return INVALIDSYM
    /*string lookup_all(string iden) {
      // Check current local symbol table
      string type = lookup_here(iden);
      if(type != INVALIDSYM) {
        return type;
      }
      
      // Check to see if it is the root
      if(parent == 0) {
        return INVALIDSYM;
      } 
      
      // Check parent 
      return parent->lookup_all(iden);
    }*/
    
    // Mangles the identifier of a child being added
    virtual string mangle(string name) {
      return '$' + name + '$';
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
            string new_iden = st->mangle(st->iden);
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
      if(lookup_here(var) != INVALIDSYM) {
        return false;
      } 
      
      pair<string, Variable*> newVar (mangle(var->iden), var);
      vardecs.insert(newVar);
      return true;
    }
    
    // Look up method in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(SymbolTable * method) {
      //string mangled = method->mangle(method->iden);
      if(lookup_here(method) != INVALIDSYM) {
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
    
    string mangle(string name) {
      return '$' + name + '$';
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
    
    string mangle(string name) {
      string temp = '$' + name + '$';
      for(unsigned int i = 0; i < params.size(); i++) {
        temp = temp + params[i]->iden + '$';
      }
      return temp;
    }
    
    string return_type() {
      return returnType;
    }
    
    void printTable() {
      cout << "  "
           << type << " -> " 
           << "  " << returnType 
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
    
    string mangle(string name) {
      string temp = '$' + name + '$';
      for(unsigned int i = 0; i < params.size(); i++) {
        temp = temp + params[i]->iden + '$';
      }
      return temp;
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
    
    void printTable() {
      string indent = "";
      for(int i = 1; i < level; i++) {
        indent = indent + "  ";
      }      
        
      cout << indent << type << " -> " << endl;
                 
      for(auto it = vardecs.begin(); it != vardecs.end(); ++it) {
        cout << indent 
             << "  "   << it->second->type 
             << "  "   << it->second->iden 
             << endl;
      }
      
      for(unsigned int i = 0; i < order.size(); i++) {
        children.find(order[i])->second->printTable();
      }
    }
};

#endif
