// Shaya Wolf
// Program 5
// cosc5785 - Compilers
// 11/16/2017

#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;


class SymbolTable 
{
  public:
    
  // Constructor
  SymbolTable(SymbolTable * p) {
    parent = p;
  }

  // Destructor
  virtual ~SymbolTable() {
    for(unsigned int i = 0; i < vars.size(); i++) {
      delete vars[i]; 
    }
    
    for(unsigned int i = 0; i < methods.size(); i++) {
      delete methods[i]; 
    }
    
    delete parent;
  }

  // Functions
  

  protected:
    SymbolTable* parent;
    
    vector<Variable*> vars;
    vector<Method*> methods;
};

#endif