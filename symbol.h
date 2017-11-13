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

struct Method{
  string returnType;
  string iden;
  vector<Variable*> params;
  bool valid;
};

void printParams(vector<Variable*> params);

#endif