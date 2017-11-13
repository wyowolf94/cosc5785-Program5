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
    SymbolTable(SymbolTable * p) {
      parent = p;
      level = p->level + 1;
    }
    
    SymbolTable() {
      parent = 0;
      level = 0;
    }

    // Destructor
    virtual ~SymbolTable() {
      vars.clear();
      methods.clear();
      
      for(unsigned int i = 0; i < children.size(); i++) {
        delete children[i]; 
      }
      
      delete parent;
    }

    // Functions
    // Returns true if the symbol table was created
    bool exists() {
      return (level >= 0);
    }
    
    // Adds a child to the vector of pointers to symbol tables
    void addChild(SymbolTable * st) {
      if(st != 0) {
        children.push_back(st);
      }
      return;
    }
    
    // Looks up a variable in this symbol table and all of it's ancestors
    // If it exists, return it's type, if not, return INVALIDVAR
    string lookupAllVar(string iden) {
      // Search the current symbol table and return if found
      string type = lookupCurrentVar(iden);
      if(type != INVALIDVAR) { 
        return type;
      } 
      
      // If it's not in the current symbol table and this table is the root
      if(level == 0) {
        return INVALIDVAR;
      }
      
      // If it's not in the current symbol table and this table has a parent
      return parent->lookupAllVar(iden);
    }
    
    // Look up a method in this symbol table and all of it's ancestors
    // If it exists, return it's returnType, if not, return INVALIDMETHOD
    string lookupAllMethod(string iden) {
      // Search the current symbol table and return if found
      string type = lookupCurrentMethod(iden);
      if(type != INVALIDMETHOD) { 
        return type;
      } 
      
      // If it's not in the current symbol table and this table is the root
      if(level == 0) {
        return INVALIDMETHOD;
      }
      
      // If it's not in the current symbol table and this table has a parent
      return parent->lookupAllMethod(iden);
    }
    
    // Look up a symbol in this symbol table and all of it's ancestors
    // If it exists, return it's type/returnType, if not, return INVALIDSYM
    string lookupAll(string iden) {
      string type1 = "";
      string type2 = "";
      
      type1 = lookupAllVar(iden);
      type2 = lookupAllMethod(iden);
      
      if(type1 == INVALIDVAR && type2 == INVALIDMETHOD) {
        return INVALIDSYM;
      } else if (type1 == INVALIDVAR) {
        return type2;
      } else if (type2 == INVALIDMETHOD) {
        return type1;
      } else {
        return INVALIDSYM;
      }
    }
    
    // Looks up a variable in the vars map of this symbol table. 
    // If it exists, return it's type, if not, return INVALIDVAR
    string lookupCurrentVar(string iden) {
      unordered_map<string,Variable*>::const_iterator var = vars.find(iden);
      if(var == vars.end()) {
        return INVALIDVAR;
      } else {
        return var->second->type;
      }
    }
    
    // Looks up a methods in the methods map of this symbol table. 
    // If it exists, return it's return type, if not, return INVALIDMETHOD
    string lookupCurrentMethod(string iden) {
      unordered_map<string,Method*>::const_iterator method = methods.find(iden);
      if(method == methods.end()) {
        return INVALIDMETHOD;
      } 
      
      return method->second->returnType;
    }
    
    // Looks up a symbol in this symbol table
    // If it exists, return it's type/returnType, if not, return INVALIDSYM
    string lookupCurrent(string iden) {
      string type1 = "";
      string type2 = "";
      
      type1 = lookupCurrentVar(iden);
      type2 = lookupCurrentMethod(iden);
      
      if(type1 == INVALIDVAR && type2 == INVALIDMETHOD) {
        return INVALIDSYM;
      } else if (type1 == INVALIDVAR) {
        return type2;
      } else if (type2 == INVALIDMETHOD) {
        return type1;
      } else {
        return INVALIDSYM;
      }
    }

    // Look up variable in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(Variable * var) {
      if(lookupCurrent(var->iden) != INVALIDSYM) {
        return false;
      }
      
      pair<string,Variable*> newVar (var->iden, var);
      vars.insert(newVar);
      return true;
    }
    
    // Look up method in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(Method * method) {
      if(lookupCurrent(method->iden) != INVALIDSYM) {
        return false;    // OR CHECK PARAMLIST AND RETURN TYPE
      }
      
      pair<string,Method*> newMethod (method->iden, method);
      methods.insert(newMethod);
      return true;
    }
    
    // Print SymbolTable and all of it's decendents
    void printTable() {
      cout << "------------------------------------" << endl;
      cout << "Level: " << level << endl;

      cout << endl;
      cout << "Name\tValid\tType\tIdentifier" << endl;
      cout << "----\t-----\t----\t----------" << endl;
      
      for(auto it = vars.begin(); it != vars.end(); ++it) {
        cout << it->first 
             << "\t" << ((it->second->valid) ? "True" : "False")
             << "\t" << it->second->type 
             << "\t" << it->second->iden 
             << endl;
      }
      
      cout << endl;
      
      for(auto it = methods.begin(); it != methods.end(); ++it) {
        cout << it->first 
             << "\t" << ((it->second->valid) ? "True" : "False") 
             << "\t" << it->second->returnType 
             << "\t" << it->second->iden
             << endl << "    Parameters:\t";
        printParams(it->second->params);
        cout << endl;
      }
        
      
      for(unsigned int i = 0; i < children.size(); i++) {
        children[i]->printTable();
      }
      
    }
  
  protected:
    SymbolTable* parent;
    vector<SymbolTable*> children;
    int level;
    
    unordered_map<string,Variable*> vars;
    unordered_map<string,Method*> methods;
};

#endif