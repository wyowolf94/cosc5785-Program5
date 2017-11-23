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
  
  /*
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
  */
  // Build Symbol Table
  SymbolTable* root = new SymbolTable();
  
  if(forest.size() > 0) {
    for(unsigned int i = 0; i < forest.size(); i++) {
      forest[i]->buildTable(root);
    }
  }
  
  // Type Check
  
  // Print Symbol Table
  root->printTable();
  
  /*SymbolTable* root = new SymbolTable();
  
  ClassDec* class1 = new ClassDec(root, "Class_One");
  ClassDec* class2 = new ClassDec(root, "Class_Two");
  
  ConstrDec* const1 = new ConstrDec(class1, "Constr_One");
  ConstrDec* const2 = new ConstrDec(class2, "Constr_Two");
  ConstrDec* const3 = new ConstrDec(class2, "Constr_Three");
  
  MethodDec* method1 = new MethodDec(class1, "Method_One");
  MethodDec* method2 = new MethodDec(class1, "Method_Two");
  MethodDec* method3 = new MethodDec(class2, "Method_Three");
  
  BlockDec* b1 = new BlockDec(const1, "b1");
  BlockDec* b2 = new BlockDec(const2, "b2");
  BlockDec* b3 = new BlockDec(method1, "b3");
  BlockDec* b4 = new BlockDec(method1, "b4");
  BlockDec* b5 = new BlockDec(method3, "b5");
  
  Variable* var1 = new struct Variable;
  var1->valid = true;
  var1->type = "t1";
  var1->iden = "var1";
  
  Variable* var2 = new struct Variable;
  var2->valid = true;
  var2->type = "t2";
  var2->iden = "Method_Two";
  
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
  
  Variable* var8 = new struct Variable;
  var8->valid = false;
  var8->type = "t8";
  var8->iden = "var8";
  
  class1->insert(var1);
  class1->insert(var2);
  const1->insert(var3);
  method1->insert(var4);
  method1->insert(var5);
  method2->insert(var5);
  const2->insert(var6);
  method3->insert(var7);
  b1->insert(var2);
  b2->insert(var8);
  b4->insert(var8);
  b4->insert(var8);
  
  method1->set_return_type("method-rt1");
  method2->set_return_type("method-rt2");
  method3->set_return_type("method-rt3");
  
  method1->add_param(var1);
  method1->add_param(var2);
  const1->add_param(var4);
  const3->add_param(var5);
  const3->add_param(var6);
  const3->add_param(var7);

  root->insert(class1);
  root->insert(class2);

  class1->insert(const1);
  class2->insert(const2);
  class2->insert(const3);

  class1->insert(method1);
  class1->insert(method2);
  class2->insert(method3);

  const1->insert(b1);
  const2->insert(b2);
  method1->insert(b3);
  method1->insert(b4);
  method3->insert(b5);

  root->printTable();
  
  cout << endl << "Root (true)" << endl;
  cout << "0 - " << root->lookup_children(class1) << endl;
  cout << "1 - " << root->lookup_children(class2) << endl;
  
  cout << endl << "Class1 (true)" << endl;
  cout << "0 - " << class1->lookup_children(const1) << endl;
  cout << "1 - " << class1->lookup_children(method1) << endl;
  cout << "2 - " << class1->lookup_children(method2) << endl;
  cout << "3 - " << class1->lookup_children(var1) << endl;
  cout << "4 - " << class1->lookup_children(var2) << endl;
  cout << "5 - " << class1->lookup_siblings(class2) << endl;  
  cout << "6 - " << class1->lookup_ancestors(class1) << endl;
  cout << "7 - " << class1->lookup_ancestors(class2) << endl;
  //cout << "8 - " << class1->lookup_ancestors(root) << endl;
  
  cout << endl << "Class2 (true)" << endl;
  cout << "0 - " << class2->lookup_children(const2) << endl;
  cout << "1 - " << class2->lookup_children(const3) << endl;
  cout << "2 - " << class2->lookup_children(method3) << endl;
  cout << "3 - " << class2->lookup_siblings(class1) << endl;  
  cout << "4 - " << class2->lookup_ancestors(class1) << endl;
  cout << "5 - " << class2->lookup_ancestors(class2) << endl;
  //cout << "8 - " << class1->lookup_ancestors(root) << endl;
  
  cout << endl << "Const1 (true)" << endl;
  cout << "0 - " << const1->lookup_children(b1) << endl;
  cout << "1 - " << const1->lookup_children(var3) << endl;
  cout << "2 - " << const1->lookup_siblings(var1) << endl;  
  cout << "3 - " << const1->lookup_siblings(var2) << endl; 
  cout << "4 - " << const1->lookup_siblings(method1) << endl;
  cout << "5 - " << const1->lookup_siblings(method2) << endl;
  cout << "6 - " << const1->lookup_ancestors(var1) << endl;
  cout << "7 - " << const1->lookup_ancestors(var2) << endl;
  cout << "8 - " << const1->lookup_ancestors(method1) << endl;
  cout << "9 - " << const1->lookup_ancestors(method2) << endl;
  cout << "10 - " << const1->lookup_ancestors(class1) << endl;
  cout << "11 - " << const1->lookup_ancestors(class2) << endl;
  //cout << "11 - " << const1->lookup_ancestors(root) << endl;
  
  cout << endl << "Const2 (true)" << endl;
  cout << "0 - " << const2->lookup_children(b2) << endl;
  cout << "1 - " << const2->lookup_children(var6) << endl;
  cout << "2 - " << const2->lookup_siblings(const3) << endl;  
  cout << "3 - " << const2->lookup_siblings(method3) << endl; 
  cout << "4 - " << const2->lookup_ancestors(const3) << endl;  
  cout << "5 - " << const2->lookup_ancestors(method3) << endl; 
  cout << "6 - " << const2->lookup_ancestors(class2) << endl; 
  cout << "7 - " << const2->lookup_ancestors(class1) << endl;
  //cout << "7 - " << const2->lookup_ancestors(root) << endl; 

  cout << endl << "Const3 (true)" << endl;
  cout << "0 - " << const3->lookup_siblings(const2) << endl;  
  cout << "1 - " << const3->lookup_siblings(method3) << endl; 
  cout << "2 - " << const3->lookup_ancestors(const2) << endl; 
  cout << "3 - " << const3->lookup_ancestors(method3) << endl;  
  cout << "4 - " << const3->lookup_ancestors(class2) << endl; 
  cout << "5 - " << const3->lookup_ancestors(class1) << endl;
  //cout << "5 - " << const3->lookup_ancestors(root) << endl;  
  
  cout << endl << "Method1 (true)" << endl;
  cout << "0 - " << method1->lookup_children(b3) << endl;
  cout << "1 - " << method1->lookup_children(b4) << endl; 
  cout << "2 - " << method1->lookup_children(var4) << endl;  
  cout << "3 - " << method1->lookup_children(var5) << endl;   
  cout << "4 - " << method1->lookup_siblings(var1) << endl;  
  cout << "5 - " << method1->lookup_siblings(var2) << endl; 
  cout << "6 - " << method1->lookup_siblings(const1) << endl;
  cout << "7 - " << method1->lookup_siblings(method1) << endl; 
  cout << "8 - " << method1->lookup_siblings(method2) << endl; 
  cout << "9 - " << method1->lookup_ancestors(var1) << endl;  
  cout << "10 - " << method1->lookup_ancestors(var2) << endl; 
  cout << "11 - " << method1->lookup_ancestors(const1) << endl;
  cout << "12 - " << method1->lookup_ancestors(method1) << endl; 
  cout << "13 - " << method1->lookup_ancestors(method2) << endl; 
  cout << "14 - " << method1->lookup_ancestors(class1) << endl; 
  cout << "15 - " << method1->lookup_ancestors(class2) << endl; 
  //cout << "15 - " << method1->lookup_ancestors(root) << endl; 
  
  cout << endl << "Method2 (true)" << endl;
  cout << "0 - " << method2->lookup_children(var5) << endl; 
  cout << "1 - " << method2->lookup_siblings(var1) << endl;  
  cout << "2 - " << method2->lookup_siblings(var2) << endl; 
  cout << "3 - " << method2->lookup_siblings(const1) << endl;
  cout << "4 - " << method2->lookup_siblings(method1) << endl; 
  cout << "5 - " << method2->lookup_siblings(method2) << endl; 
  cout << "6 - " << method2->lookup_ancestors(var1) << endl;  
  cout << "7 - " << method2->lookup_ancestors(var2) << endl; 
  cout << "8 - " << method2->lookup_ancestors(const1) << endl;
  cout << "9 - " << method2->lookup_ancestors(method1) << endl; 
  cout << "10 - " << method2->lookup_ancestors(method2) << endl; 
  cout << "11 - " << method2->lookup_ancestors(class1) << endl;  
  cout << "12 - " << method2->lookup_ancestors(class2) << endl; 
  //cout << "12 - " << method2->lookup_ancestors(root) << endl; 
  
  cout << endl << "Method3 (true)" << endl;
  cout << "0 - " << method3->lookup_children(b5) << endl; 
  cout << "1 - " << method3->lookup_children(var7) << endl;
  cout << "2 - " << method3->lookup_siblings(const2) << endl; 
  cout << "3 - " << method3->lookup_siblings(const3) << endl; 
  cout << "4 - " << method3->lookup_ancestors(const2) << endl; 
  cout << "5 - " << method3->lookup_ancestors(const3) << endl; 
  cout << "6 - " << method3->lookup_ancestors(class2) << endl; 
  cout << "7 - " << method3->lookup_ancestors(class1) << endl; 
  //cout << "7 - " << method3->lookup_ancestors(root) << endl; 
  
  cout << endl << "Block1 (true)" << endl;
  cout << "0 - " << b1->lookup_children(var2) << endl;
  cout << "1 - " << b1->lookup_siblings(var3) << endl;
  cout << "2 - " << b1->lookup_ancestors(var3) << endl;
  cout << "3 - " << b1->lookup_ancestors(var1) << endl;
  cout << "4 - " << b1->lookup_ancestors(var2) << endl;
  cout << "5 - " << b1->lookup_ancestors(const1) << endl;
  cout << "6 - " << b1->lookup_ancestors(method1) << endl;
  cout << "7 - " << b1->lookup_ancestors(method2) << endl;
  cout << "8 - " << b1->lookup_ancestors(class1) << endl;
  cout << "9 - " << b1->lookup_ancestors(class2) << endl;
  //cout << "9 - " << b1->lookup_ancestors(root) << endl;
  
  cout << endl << "Root (false)" << endl;
  cout << "0 - " << root->lookup_children(const1) << endl;
  cout << "1 - " << root->lookup_children(method3) << endl;
  cout << "2 - " << root->lookup_ancestors(var1) << endl;
  cout << "3 - " << root->lookup_ancestors(b2) << endl;
  cout << "4 - " << root->lookup_ancestors(class1) << endl;
  cout << "5 - " << root->lookup_ancestors(class2) << endl;
  
  cout << endl << "Class1 (false)" << endl;
  cout << "0 - " << class1->lookup_children(var3) << endl;
  cout << "1 - " << class1->lookup_children(var8) << endl;
  cout << "2 - " << class1->lookup_children(b3) << endl;
  cout << "3 - " << class1->lookup_siblings(root) << endl;
  cout << "4 - " << class1->lookup_siblings(const2) << endl;
  cout << "5 - " << class1->lookup_ancestors(const2) << endl;
  cout << "6 - " << class1->lookup_ancestors(b5) << endl;
  
  cout << endl << "Class2 (false)" << endl;
  cout << "0 - " << class2->lookup_children(class1) << endl;
  cout << "1 - " << class2->lookup_children(var6) << endl;
  cout << "2 - " << class2->lookup_children(var1) << endl;
  cout << "3 - " << class2->lookup_siblings(const2) << endl;
  cout << "4 - " << class2->lookup_siblings(root) << endl;
  cout << "5 - " << class2->lookup_ancestors(method1) << endl;
  cout << "6 - " << class2->lookup_ancestors(const2) << endl;
  
  cout << endl << "Const1 (false)" << endl;
  cout << "0 - " << const1->lookup_children(var2) << endl;
  cout << "1 - " << const1->lookup_children(method1) << endl;
  cout << "2 - " << const1->lookup_siblings(class1) << endl;
  cout << "3 - " << const1->lookup_siblings(const2) << endl;  
  cout << "4 - " << const1->lookup_ancestors(var3) << endl;
  cout << "5 - " << const1->lookup_ancestors(var8) << endl;
  //cout << "6 - " << const1->lookup_ancestors(class2) << endl;
  
  cout << endl << "Const2 (false)" << endl;
  cout << "0 - " << const2->lookup_children(var8) << endl;
  cout << "1 - " << const2->lookup_children(var7) << endl;
  cout << "2 - " << const2->lookup_siblings(var1) << endl;
  cout << "3 - " << const2->lookup_siblings(class2) << endl;
  cout << "4 - " << const2->lookup_ancestors(method1) << endl;
  cout << "5 - " << const2->lookup_ancestors(b3) << endl;
  //cout << "6 - " << const2->lookup_ancestors(class1) << endl; 
  
  cout << endl << "Const3 (false)" << endl;
  cout << "0 - " << const3->lookup_children(const2) << endl;
  cout << "1 - " << const3->lookup_children(class2) << endl;
  cout << "2 - " << const3->lookup_siblings(method2) << endl;
  cout << "3 - " << const3->lookup_siblings(class2) << endl;
  cout << "4 - " << const3->lookup_ancestors(b2) << endl;
  cout << "5 - " << const3->lookup_ancestors(var1) << endl;
  //cout << "6 - " << const3->lookup_ancestors(class1) << endl; 
  
  cout << endl << "Method1 (false)" << endl;
  cout << "0 - " << method1->lookup_children(var3) << endl;
  cout << "1 - " << method1->lookup_children(class1) << endl;
  cout << "2 - " << method1->lookup_siblings(method3) << endl;
  cout << "3 - " << method1->lookup_siblings(root) << endl;
  cout << "4 - " << method1->lookup_ancestors(b1) << endl;
  cout << "5 - " << method1->lookup_ancestors(const3) << endl;
  //cout << "6 - " << method1->lookup_ancestors(class2) << endl; 
  
  cout << endl << "Method2 (false)" << endl;
  cout << "0 - " << method2->lookup_children(method1) << endl;
  cout << "1 - " << method2->lookup_children(var7) << endl;
  cout << "2 - " << method2->lookup_siblings(var5) << endl;
  cout << "3 - " << method2->lookup_siblings(class1) << endl;
  cout << "4 - " << method2->lookup_ancestors(var4) << endl;
  //cout << "5 - " << method2->lookup_ancestors(class2) << endl; 
  
  cout << endl << "Method3 (false)" << endl;
  cout << "0 - " << method3->lookup_children(const3) << endl;
  cout << "1 - " << method3->lookup_children(method1) << endl;
  cout << "2 - " << method3->lookup_children(method3) << endl;
  cout << "3 - " << method3->lookup_siblings(b2) << endl;
  cout << "4 - " << method3->lookup_siblings(class1) << endl;
  cout << "5 - " << method3->lookup_ancestors(var6) << endl;
  cout << "6 - " << method3->lookup_ancestors(var1) << endl;
  //cout << "7 - " << method3->lookup_ancestors(class1) << endl; 
  
  cout << endl << "Block2 (false)" << endl;
  cout << "0 - " << b2->lookup_children(var6) << endl;
  cout << "1 - " << b2->lookup_children(class2) << endl;
  cout << "2 - " << b2->lookup_siblings(var8) << endl;
  cout << "3 - " << b2->lookup_siblings(const2) << endl;
  cout << "4 - " << b2->lookup_ancestors(var8) << endl;
  //cout << "5 - " << b2->lookup_ancestors(const3) << endl;
  //cout << "6 - " << b2->lookup_ancestors(method3) << endl;
  cout << "7 - " << b2->lookup_ancestors(var7) << endl;
  cout << "8 - " << b2->lookup_ancestors(b5) << endl;
  //cout << "9 - " << b2->lookup_ancestors(class1) << endl;
  cout << "10 - " << b2->lookup_ancestors(var1) << endl;
  cout << "11 - " << b2->lookup_ancestors(var2) << endl;
  cout << "12 - " << b2->lookup_ancestors(const1) << endl;
  cout << "13 - " << b2->lookup_ancestors(method1) << endl;
  cout << "14 - " << b2->lookup_ancestors(method2) << endl;*/

  delete atts;
  
  return 0 ;
}
