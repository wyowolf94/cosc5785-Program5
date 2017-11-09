// Shaya Wolf
// COSC5785 - Compilers   
// Program 5
// symbol.cpp
// 11/16/2017

#include<string>
#include "symbol.h"

using namespace std;

void updateVariable(Variable * var, string iden, string type){
  var->iden = iden;
  var->type = type;
  return;
}

void updateMethod(Method * method, string iden, string returnType, vector<tuple<string,string> *> params){
  method->iden = iden;
  method->returnType = returnType;
  method->params = params;
  return;
}