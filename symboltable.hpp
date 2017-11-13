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
#define CONSTRUCTOR "Constructor"
#define METHODTYPE "Method"
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
    SymbolTable(SymbolTable * p) {
      type = BLOCKTYPE;
    }

    // Destructor
    virtual ~SymbolTable() {

    }

    // Look up variable in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(Variable * var) {

    }
    
    // Look up method in current symbol table
    // If it already exists, return false, if not, add it and return true
    bool insert(Method * method) {

    }
    
    
    // Print SymbolTable and all of it's decendents in-order
    void printTable() {

    }
  
  protected:
    string iden;
    vector<Varialbe*> vardecs;
    SymbolTable * parent;
    vector<SymbolTable*> children;
    string type;
};

class MethodDec : public SymbolTable
{
  public:
    MethodDec(SymbolTable * p) : SymbolTable (/*SymbolTable * p*/) {
      type = METHODTYPE;
    } 

    
  private:
    string returnType;
    vector<Varialbe*> params;    
};

class ConstrDec : public SymbolTable
{
  public:
    ConstrDec(SymbolTable * p) : SymbolTable (/*SymbolTable * p*/) {
      type = CONSTRUCTOR;
    } 

    
  private:
    vector<Varialbe*> params;    
};

#endif