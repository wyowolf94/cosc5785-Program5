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
  
  SymbolTable* parent = new SymbolTable();
  
  SymbolTable* child = new SymbolTable(parent);
  parent->addChild(child);
  
  SymbolTable* grandchild1 = new SymbolTable(child);
  child->addChild(grandchild1);
  
  SymbolTable* grandchild2 = new SymbolTable(child);
  child->addChild(grandchild2);
  
  Variable* var1 = new struct Variable;
  var1->valid = true;
  var1->type = "t1";
  var1->iden = "var1";
  parent->insert(var1);
  
  Variable* var2 = new struct Variable;
  var2->valid = false;
  var2->type = "t2";
  var2->iden = "var2";
  child->insert(var2);
  
  Variable* var5 = new struct Variable;
  var5->valid = false;
  var5->type = "t5";
  var5->iden = "var2";
  child->insert(var5);
  grandchild1->insert(var5);
  
  Method* meth1 = new struct Method;
  meth1->valid = true;
  meth1->returnType = "rt1";
  meth1->iden = "method1";
  vector<Variable*> parameters;
  parameters.push_back(var1);
  parameters.push_back(var2);
  meth1->params = parameters;
  child->insert(meth1);
  
  Method* meth4 = new struct Method;
  meth4->valid = true;
  meth4->returnType = "rt4";
  meth4->iden = "method1";
  meth4->params = parameters;
  child->insert(meth4);
  grandchild2->insert(meth4);
  
  Method* meth2 = new struct Method;
  meth2->valid = false;
  meth2->returnType = "rt2";
  meth2->iden = "method2";
  parameters.pop_back();
  meth2->params = parameters;
  child->insert(meth2);
  
  Variable* var3 = new struct Variable;
  var3->valid = true;
  var3->type = "t3";
  var3->iden = "var3";
  grandchild1->insert(var3);
  grandchild2->insert(var3);
  
  Variable* fakevar3 = new struct Variable;
  fakevar3->valid = true;
  fakevar3->type = "t3";
  fakevar3->iden = "var3";
  bool fail = grandchild1->insert(fakevar3);
  cout << "False(0): " << fail << endl;
  
  Variable* var4 = new struct Variable;
  var4->valid = true;
  var4->type = "t4";
  var4->iden = "var4";
  grandchild2->insert(var4);
  
  Method* meth3 = new struct Method;
  meth3->valid = true;
  meth3->returnType = "rt3";
  meth3->iden = "method3";
  parameters.push_back(var2);
  parameters.push_back(var3);
  parameters.push_back(var4);
  meth3->params = parameters;
  grandchild2->insert(meth3);
  
  parent->printTable();
  
  cout << "LookupAll var1 (Grandchild1): " << grandchild1->lookupAll(var1->iden) << endl;
  cout << "LookupAll var2 (Grandchild1): " << grandchild1->lookupAll(var2->iden) << endl;
  cout << "LookupAll var2 (Grandchild2): " << grandchild2->lookupAll(var2->iden) << endl;
  cout << "LookupAll var4 (Grandchild1): " << grandchild1->lookupAll(var4->iden) << endl;
  
  cout << "LookupAll method3 (grandchild1): " << grandchild1->lookupAll(meth3->iden) << endl;
  cout << "LookupAll method3 (grandchild2): " << grandchild2->lookupAll(meth3->iden) << endl;
  cout << "LookupAll method1 (grandchild2): " << grandchild2->lookupAll(meth1->iden) << endl;
  cout << "LookupAll method2 (Child): " << child->lookupAll(meth2->iden) << endl;
  
  cout << "LookupAll var1 (Child): " << child->lookupAll(var1->iden) << endl;
  cout << "LookupAll var2 (Child): " << child->lookupAll(var2->iden) << endl;
  cout << "LookupAll var2 (Parent): " << parent->lookupAll(var2->iden) << endl;
  
  delete atts;
  
  return 0 ;
}
