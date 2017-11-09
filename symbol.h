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
  bool valid;
  string iden;
  string type;
};

void updateVariable(Variable * var, string iden, string type);

struct Method{
  bool valid;
  string iden;
  string returnType;
  vector<tuple<string,string> *> params;
};

void updateMethod(Method * method, string iden, string returnType, vector<tuple<string,string> *> params);

#endif