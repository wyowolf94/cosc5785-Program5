// Shaya Wolf
// COSC5785 - Compilers   
// Program 5
// symbol.cpp
// 11/16/2017

#include<string>
#include "symbol.h"

using namespace std;

void printParams(vector<Variable*> params) {
  cout << "(";
  if(params.size() > 0) {
    cout << params[0]->type << " " << params[0]->iden;
    for(unsigned int i = 1; i < params.size(); i++) {
      cout << ", " << params[i]->type << " " << params[i]->iden;
    }
  }
  cout << ")" << endl;
  
  return;
}