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
#define INVALIMETHOD "invalid method"
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
    void addChild(SymbolTable *st) {
      if(st != 0) {
        children.push_back(st);
      }
      return;
    }
    
    // Looks up a variable in the vars map
    string lookupVar(string iden) {
      unordered_map<string,Variable*>::const_iterator var = vars.find(iden);
      if(var == vars.end()) {
        return INVALIDVAR;
      } else {
        return var->second->type;
      }
    }
    
    // Looks up a method in the methods map
    string lookupMethod(string iden) {
      unordered_map<string,Method*>::const_iterator method = methods.find(iden);
      if(method == methods.end()) {
        return INVALIMETHOD;
      } 
      
      return method->second->returnType;
    }
    
    // Looks up a symbol in the symbol table
    string lookup(string iden) {
      string type1 = "";
      string type2 = "";
      
      type1 = lookupVar(iden);
      type2 = lookupMethod(iden);
      
      if(type1 == INVALIDVAR && type2 == INVALIMETHOD) {
        return INVALIDSYM;
      } else if (type1 == INVALIDVAR) {
        return type2;
      } else if (type2 == INVALIMETHOD) {
        return type1;
      } else {
        return INVALIDSYM;
      }
    }

    bool insert(Variable * var) {
      if(lookup(var->iden) != INVALIDSYM) {
        return false;
      }
      
      pair<string,Variable*> newVar (var->iden, var);
      vars.insert(newVar);
      return true;
    }
    
    bool insert(Method * method) {
      if(lookup(method->iden) != INVALIDSYM) {
        return false;    // OR CHECK PARAMLIST AND RETURN TYPE
      }
      
      pair<string,Method*> newMethod (method->iden, method);
      methods.insert(newMethod);
      return true;
    }
  
  protected:
    SymbolTable* parent;
    vector<SymbolTable*> children;
    int level;
    
    unordered_map<string,Variable*> vars;
    unordered_map<string,Method*> methods;
};

#endif