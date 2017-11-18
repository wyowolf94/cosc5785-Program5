// Shaya Wolf
// COSC5785 - Compilers   
// Program 5
// program5.cpp
// 11/16/2017

#include<FlexLexer.h>

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<vector>

#include "attributes.h"
#include "node.hpp"
#include "symboltable.hpp"
#include "program5.tab.h"

using namespace std;

attributes *atts;
yyFlexLexer myScanner;
vector<Node*> forest;

int main() { 
  // Initialize Attributes Struct
  atts = new attributes{0,0,0,""};
  
  cout << endl;
    
  // Make call for Bison
  yyparse();
  
  // Print the Parse Tree
  if(forest.size() > 0) {
    cout << endl << "<Program> -> ";
    for(unsigned int i = 0; i < forest.size(); i++) {
      cout << "<ClassDec> ";
    }
    cout << endl;
    for(unsigned int i = 0; i < forest.size(); i++) {
      cout << endl << "**" << i << "**" << endl;
      forest[i]->printNode();
      delete forest[i];
    }
    cout << endl;
  }
  
  /*
  SymbolTable* root = new SymbolTable();
  
  SymbolTable* class1 = new SymbolTable(root, CLASSTYPE);
  root->addChild(class1);
  
  SymbolTable* class2 = new SymbolTable(root, CLASSTYPE);
  root->addChild(class2);
  
  SymbolTable* const1 = new SymbolTable(class1, CONSTRUCTOR);
  class1->addChild(const1);
  
  SymbolTable* method1 = new SymbolTable(class1, METHODTYPE);
  class1->addChild(method1);
  
  SymbolTable* method2 = new SymbolTable(class1, METHODTYPE);
  class1->addChild(method2);
  
  SymbolTable* const2 = new SymbolTable(class2, CONSTRUCTOR);
  class2->addChild(const2);
  
  SymbolTable* method3 = new SymbolTable(class2, METHODTYPE);
  class2->addChild(method3);
  
  Variable* var1 = new struct Variable;
  var1->valid = true;
  var1->type = "t1";
  var1->iden = "var1";
  
  Variable* var2 = new struct Variable;
  var2->valid = true;
  var2->type = "t2";
  var2->iden = "var2";
  
  Variable* var3 = new struct Variable;
  var3->valid = true;
  var3->type = "t3";
  var3->iden = "var3";
  
  Variable* var4 = new struct Variable;
  var4->valid = true;
  var4->type = "t4";
  var4->iden = "var4";
  
  Variable* var5 = new struct Variable;
  var5->valid = true;
  var5->type = "t5";
  var5->iden = "var5";
  
  Variable* var6 = new struct Variable;
  var6->valid = true;
  var6->type = "t6";
  var6->iden = "var6";
 
  Variable* var7 = new struct Variable;
  var7->valid = true;
  var7->type = "t7";
  var7->iden = "var7";
  
  Method* meth1 = new struct Method;
  meth1->valid = true;
  meth1->returnType = "m1";
  meth1->iden = "meth1";
  meth1->params.push_back(var1);
  meth1->params.push_back(var5);
  
  Method* meth2 = new struct Method;
  meth2->valid = true;
  meth2->returnType = "m2";
  meth2->iden = "meth2";
  meth2->params.push_back(var3);
  meth2->params.push_back(var4);
  
  Method* meth3 = new struct Method;
  meth3->valid = true;
  meth3->returnType = "m3";
  meth3->iden = "meth3";
  meth3->params.push_back(var2);
  
  Method* meth4 = new struct Method;
  meth4->valid = true;
  meth4->returnType = "m4";
  meth4->iden = "meth4";
  
  Method* meth5 = new struct Method;
  meth5->valid = true;
  meth5->returnType = "m5";
  meth5->iden = "meth5";
  meth5->params.push_back(var1);
  meth5->params.push_back(var3);
  meth5->params.push_back(var5);
  
  class1->insert(var1);
  class1->insert(var2);
  class1->insert(meth1);
  class1->insert(meth2);
  class1->insert(meth3);
  
  const1->insert(var3);
  method1->insert(var4);
  method1->insert(var5);
  method2->insert(var5);
  
  class2->insert(meth4);
  class2->insert(meth5);
  
  const2->insert(var6);
  method3->insert(var7);
  
  root->printTable();
  */

  delete atts;
  
  return 0 ;
}
