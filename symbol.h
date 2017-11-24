// Shaya Wolf
// COSC5785 - Compilers 
// Program 5
// symbol.h
// 11/16/2017

#ifndef SYMBOL_H
#define SYMBOL_H

#include<iostream>
#include<string.h>
#include<tuple>
#include<vector>

#define INVALIDSYM "invalid symbol"
#define INVALIDTYPE "invalid type"

using std::string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;
using std::tuple;
using std::vector;

struct Variable{
  string type;
  string iden;
  bool valid;
};

void printParams(vector<Variable*> params);

string lookupParams(vector<Variable*> params, Variable* var);

#endif