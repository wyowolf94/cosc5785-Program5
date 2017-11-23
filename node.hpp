// Shaya Wolf
// Program 5
// cosc5785 - Compilers
// 11/16/2017

#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include<string>
#include<vector>
#include "symboltable.hpp"

using std::string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;

// Base Class
class Node 
{
  public:
    vector<Node*> children;
  
    // Constructor
    Node() {
      reset();
      ival = 0;
      dval = 0;
      valid = true;
    }

    // Destructor
    virtual ~Node() {
      for(unsigned int i = 0; i < children.size(); i++) {
        delete children[i]; 
      }
    }

    // Get Functions
    int    getint()   const { return ival; }

    double getdbl()   const { return dval; }

    string getstr()   const { return sval; }
    
    bool   getValid() const { return valid;}

    // Set Functions
    void setVal(int i)          { ival = i; }

    void setVal(double d)       { dval = d; }

    void setVal(const string s) { sval = s; }

    void setVal(const char * c) { sval = c; }
    
    void setValid(const bool b) { valid = b; }
    
    // Crap code
    virtual string getType() {
      return INVALIDSYM;
    }
    
    virtual Variable* getParam() {
      return 0;
    }
    
    virtual vector<Variable*> getParams() {
      vector<Variable*> no;
      return no;
    }

    // Reset
    void reset() {
      lnum = 1;
      cnum = 1;
      sval.clear();
    } 
    
    // Get a Child
    Node* getChild(unsigned index) {
      return children[index];
    }

    // Set a Child
    void setChild(Node *c, unsigned index){
      children[index] = c;
      return;
    }
    
    void addChild(Node *c) {
      if(c != 0) {
        children.push_back(c);
      }
      return;
    }
    
    virtual void buildTable(SymbolTable* st) {
      cout << "PROBLEM!PROBLEM!PROBLEM!PROBLEM!PROBLEM!PROBLEM!" << endl;
      return;
    }

    // Print Node
    virtual void printNode(ostream * out = 0) {
      *out << sval;
      for(unsigned i = 0; i < children.size(); i++) {
        children[i]->printNode(out);
      }
      return;
    }

  protected:
    //vector<Node*> children;

    int lnum;
    int cnum;

    int ival;
    double dval;
    string sval;

    bool valid;
};

///////////////////////////////////////////////////////////////////////////////////

// Node used for all errors so far
class errorNode : public Node 
{
  public:
    errorNode(string er) : Node () {
      errorRed = er;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl << errorRed << " -> *** Error Node ***" << endl;
    }
  private:
    string errorRed;
}; 

// plusstar used for the place-holder nodes that don't print anything
class plusstarNode : public Node 
{
  public:
    plusstarNode() : Node () {
      // Nada
    } 
    
    void buildTable(SymbolTable* parent) {
      for(unsigned int i = 0; i < children.size(); i++) {
        children[i]->buildTable(parent);
      }
    }

    virtual void printNode(ostream * out = 0) {
      // Don't print anything
    }
}; 

// classdecNode that goes to class iden classbody
class classdecNode : public Node 
{
  public:
    classdecNode(string i) : Node () {
      id = i;
    } 

    void buildTable(SymbolTable* parent) {
      // Create SymbolTable for Class Declaration
      ClassDec* new_class = new ClassDec(parent, id);
      cout << "Created: " << id << endl;
      
      // Add the ClassDec to the parent
      parent->insert(new_class);
      cout << "Added " << id << " to " << parent->getIden() << endl << endl;
      
      // Call buildTable on the children
      for(unsigned int i = 0; i < children.size(); i++) {
        children[i]->buildTable(new_class);
      }
    }
    
    virtual void printNode(ostream * out = 0) {
      cout << endl << "<ClassDec> -> class identifier (" << id << ") <ClassBody>" << endl;
      children[0]->printNode();
    }
  private:
    string id;
}; 

// classbodyNode that goes to { vardecs constdecs methdecs }
class classbodyNode : public Node 
{
  public:
    classbodyNode(string t) : Node () {
      type = t;
    } 
    
    void buildTable(SymbolTable* parent) {
      // Create SymbolTable for Class Declaration
      BlockDec* new_classBlock = new BlockDec(parent, "class_");
      new_classBlock->setIden(new_classBlock->getNewName());
      cout << "Created: " << new_classBlock->getIden() << endl;
      
      // Add the ClassDec to the parent
      parent->insert(new_classBlock);
      cout << "Added " << new_classBlock->getIden() << " to " << parent->getIden() << endl << endl;
      
      // Call buildTable on the children
      for(unsigned int i = 0; i < children.size(); i++) {
        children[i]->buildTable(new_classBlock);
      }
      /*
      if (type == "vdecs" || type == "cdecs" || type == "mdecs") {
        children[0]->buildTable();
      } else if (type == "vcdecs" || type == "cmdecs" || type = "vmdecs") {
        children[0]->buildTable();
        children[1]->buildTable();
      } else if (type == "vcmdecs") {
        children[0]->buildTable();
        children[1]->buildTable();
        children[2]->buildTable();
      } 
      */
    }

    void printClassBody(string nonterm) {
        cout << "<ClassBody> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<" << nonterm << "> ";
        }
        cout << "}" << endl;
    }
    
    void printClassBody(string ntone, string nttwo) {
        cout << "<ClassBody> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<" << ntone << "> ";
        }
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "<" << nttwo << "> ";
        }
        cout << "}" << endl;
    }
    
    void printClassBody() {
        cout << "<ClassBody> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<VarDec> ";
        }
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "<ConstDec> ";
        }
        for(unsigned int i = 0; i < children[2]->children.size(); i++) {
          cout << "<MethDec> ";
        }
        cout << "}" << endl;
    }
    
    void printChildren(int index) {
        for(unsigned int i = 0; i < children[index]->children.size(); i++) {
          children[index]->children[i]->printNode();
        }
    }

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ClassBody> -> { }" << endl;
      } else if (type == "vdecs") {
        printClassBody("VarDec");
        printChildren(0);
      } else if (type == "cdecs") {
        printClassBody("ConstDec");
        printChildren(0);
      } else if (type == "mdecs") {
        printClassBody("MethDec");
        printChildren(0);
      } else if (type == "vcdecs") {
        printClassBody("VarDec", "ConstDec");
        printChildren(0);
        printChildren(1);
      } else if (type == "cmdecs") {
        printClassBody("ConstDec", "MethDec");
        printChildren(0);
        printChildren(1);
      } else if (type == "vmdecs") {
        printClassBody("VarDec", "MethDec");
        printChildren(0);
        printChildren(1);
      } else if (type == "vcmdecs") {
        printClassBody();
        printChildren(0);
        printChildren(1);
        printChildren(2);
      } else {
        cout << "classbody problem" << endl;
      }
    }
    
  private:
    string type;
}; 

// VarDec Node which just needs to print <VarDec>
class varDecNode : public Node 
{
  public:
    varDecNode(string i) : Node () {
      identifier = i;
    } 
    
    void buildTable(SymbolTable* parent) {
      // Create SymbolTable for Class Declaration
      string new_type = children[0]->getType();
      Variable* new_var = new Variable{new_type, identifier, true};
      cout << "Created: " << new_var->type << " " << new_var->iden << endl;
      
      // Add the ClassDec to the parent
      parent->insert(new_var);
      cout << "Added " << new_var->iden << " to " 
           << parent->getIden() << endl << endl;
      
      // Call buildTable on the children
      for(unsigned int i = 0; i < children.size(); i++) {
        //children[i]->buildTable(new_class);
      }
    }

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<VarDec> -> <Type> identifier (" 
           << identifier << ") semi" << endl;
      children[0]->printNode();
    }
  private:
    string identifier;
}; 

// Constructor Declaration node that goes to iden ( paramlist ) block
class constdecNode : public Node 
{
  public:
    constdecNode(string i) : Node () {
      id = i;
    } 
    
    void buildTable(SymbolTable* parent) {
      // Create SymbolTable for Class Declaration
      ConstrDec* new_const = new ConstrDec(parent, id);
      new_const->setParams(children[0]->getParams());
      cout << "Created: " << id ;
      printParams(new_const->getParams());
      cout << endl;
      
      // Add the ClassDec to the parent
      parent->insert(new_const);
      cout << "Added " << new_const->getIden() << " to " 
           << parent->getIden() << endl << endl;
      
      // Call buildTable on the children
      for(unsigned int i = 0; i < children.size(); i++) {
        //children[i]->buildTable(new_class);
      }
    }

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<ConstDec> -> identifier (" << id
           << ") ( <ParameterList> ) <Block>" << endl;
      children[0]->printNode();
      children[1]->printNode();
    }
  private:
    string id;
}; 

// Method Declaration node that goes to resulttype iden ( paramlist ) block
class methoddecNode : public Node 
{
  public:
    methoddecNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 
    
    void buildTable(SymbolTable* parent) {
      // Create SymbolTable for Class Declaration
      MethodDec* new_method = new MethodDec(parent, id);
      if(type == "type") {
        new_method->set_returnType(children[0]->getType());
      } else if (type == "void") {
        new_method->set_returnType(type);
      } else { 
        cout << "PROBLEM IN METHODDECNODE - BUILDTABLE" << endl;
        new_method->set_returnType(INVALIDSYM);
      }
      new_method->setParams(children[1]->getParams());
      cout << "Created: " << new_method->return_type() 
           << " " << new_method->getIden();
           printParams(new_method->getParams());
      cout << endl;
      
      // Add the ClassDec to the parent
      parent->insert(new_method);
      cout << "Added " << new_method->getIden() << " to " 
           << parent->getIden() << endl << endl;
      
      // Call buildTable on the children
      for(unsigned int i = 0; i < children.size(); i++) {
        //children[i]->buildTable(new_class);
      }
    }

    virtual void printNode(ostream * out = 0) {
      if(type == "type") {
        cout << endl << "<MethDec> -> <Type> identifier (" << id
             << ") ( <ParameterList> ) <Block>" << endl;
        children[0]->printNode();
        children[1]->printNode();
        children[2]->printNode();
      } else if(type == "void") {
        cout << endl << "<MethDec> -> void identifier (" << id
             << ") ( <ParameterList> ) <Block>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "methdec problem" << endl;
      }
      
    }
  private:
    string type;
    string id;
}; 

// paramlistNode that goes to empty or a paramstarNode
class paramlistNode : public Node 
{
  public:
    paramlistNode(string t) : Node () {
      type = t;
    } 

    vector<Variable*> getParams() {
      vector<Variable*> new_paramList;
      for(unsigned int i = 0; i < children[0]->children.size(); i++) {
        new_paramList.push_back(children[0]->children[i]->getParam());
      }
      return new_paramList;
    }
    
    void printParamList() {
        cout << "<ParameterList> -> ";
        for(unsigned int i = 0; i < children[0]->children.size() - 1; i++) {
          cout << "<Parameter> , ";
        }
        cout << "<Parameter>" << endl;
    }
    
    void printChildren() {
      for(unsigned int i = 0; i < children[0]->children.size(); i++) {
        children[0]->children[i]->printNode();
      }
    }
    
    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ParameterList> -> epsilon" << endl;
      } else if (type == "rec") {
        printParamList();
        printChildren();
      } else {
        cout << "paramlist problem" << endl;
      }
    }
  private:
    string type;
}; 

// param node which just goes to a type identifier
class paramNode : public Node 
{
  public:
    paramNode(string i) : Node () {
      id = i;
    } 
    
    Variable* getParam() {
      string new_type = children[0]->getType();
      Variable* param = new Variable{new_type,id,true};
      return param;
    }

    virtual void printNode(ostream * out = 0) {
      cout << endl << "<Parameter> -> <Type> identifier (" << id << ")" << endl;
      children[0]->printNode();
    }
  private:
    string id;
}; 

// Statement Node ... for now just a simple statement
class statementNode : public Node 
{
  public:
    statementNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      if(type == "semi") {
        cout << "<Statement> -> ;" << endl;
      } else if(type == "nameeq") {
        cout << "<Statement> -> <Name> = <Expression> ;" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "namearglist") {
        cout << "<Statement> -> <Name> ( <ArgList> ) ;" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "printarglist") {
        cout << "<Statement> -> print ( <ArgList> ) ;" << endl;
        children[0]->printNode();
      }else if(type == "cond") {
        cout << "<Statement> -> <ConditionalStatement>" << endl;
        children[0]->printNode();
      } else if(type == "while") {
        cout << "<Statement> -> while ( <Expression> ) <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "optexp") {
        cout << "<Statement> -> return <OptionalExpression> ;" << endl;
        children[0]->printNode();
      } else if (type == "block") {
        cout << "<Statement> -> <Block>" << endl;
        children[0]->printNode();
      } else {
        cout << endl << "statement problem" << endl;
      }
    }
  private:
    string type;
};

// ConditionalStatementNode goes to an if statement or an if-else statement
class condstatementNode : public Node 
{
  public:
    condstatementNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "if") {
        cout << "<ConditionalStatement> -> if ( <Expression> ) <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else if(type == "if-else") {
        cout << "<ConditionalStatement> -> if ( <Expression> ) <Statement> " 
             << "else <Statement>" << endl;
        children[0]->printNode();
        children[1]->printNode();
        children[2]->printNode();
      } else {
        cout << "conditional statement problem" << endl;
      }
    }
  private:
    string type;
};

// Block Node goes to any number of vardecs followed by any number of statements
class blockNode : public Node 
{
  public:
    blockNode(string t) : Node () {
      type = t;
    } 
    
    void printBlock(string nonterm) {
        cout << "<Block> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<" << nonterm << "> ";
        }
        cout << "}" << endl;
    }
    
    void printBlock() {
        cout << "<Block> -> { ";
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          cout << "<LocalVarDec> ";
        }
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "<Statement> ";
        }
        cout << "}" << endl;
    }
    
    void printChildren(int index) {
        for(unsigned int i = 0; i < children[index]->children.size(); i++) {
          children[index]->children[i]->printNode();
        }
    }

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      if(type == "empty") {
        cout << "<Block> -> { }" << endl;
      } else if (type == "locvardecs") {
        printBlock("LocalVarDec");
        printChildren(0);
      } else if (type == "statements") {
        printBlock("Statement");
        printChildren(0);
      } else if (type == "both") {
        printBlock();
        printChildren(0);
        printChildren(1);
      } else {
        cout << "block problem" << endl;
      }
    }
  private:
    string type;
};

// LocalVarDec Node with just prints type identifier;
class locvardecNode : public Node 
{
  public:
    locvardecNode(string i) : Node () {
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << endl;
      cout << "<LocalVarDec> -> <Type> identifier (" << id << ") ;" << endl;
      children[0]->printNode();
    }
  private:
    string id;
}; 

// Optional Expression Node that goes to epsilon or exp
class optexpNode : public Node 
{
  public:
    optexpNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<OptionalExpression> -> epsilon" << endl;
      } else if (type == "exp") {
        cout << "<OptionalExpression> -> <Expression>" << endl;
        children[0]->printNode();
      } else {
        cout << "optional expression problem" << endl;
      }
    }
  private:
    string type;
}; 

// Expression Op Node where t tells us what kind of expression it is
class expNode : public Node 
{
  public:
    expNode(string t) : Node () {
      expType = t;
      num = 0;
    } 
    
    expNode(string t, string n) : Node () {
      expType = t;
      num = atoi(n.c_str());
    }

    virtual void printNode(ostream * out = 0) {
      if(expType == "relop" || expType == "sumop"
           || expType == "proop") {
        cout << "<Expression> -> <Expression>";
        children[1]->printNode();
        cout << "<Expression>";
        cout << endl;
        children[0]->printNode();
        children[2]->printNode();
      } else if (expType == "unyop") {
        cout << "<Expression> -> ";
        children[0]->printNode();
        cout << " <Expression>";
        cout << endl;
        children[1]->printNode();
      } else if (expType == "name") {
        cout << "<Expression> -> <Name>" << endl;
        children[0]->printNode();
      } else if (expType == "name paren") {
        cout << "<Expression> -> <Name> ()" << endl;
        children[0]->printNode();
      } else if (expType == "read") {
        cout << "<Expression> -> read ()" << endl;;
      } else if (expType == "newexp") {
        cout << "<Expression> -> <NewExpression>" << endl;
        children[0]->printNode();
      } else if (expType == "paren") {
        cout << "<Expression) -> ( <Expression> )" << endl;
        children[0]->printNode();
      } else if (expType == "null") {
        cout << "<Expression> -> null" << endl;
      } else if (expType == "num") {
        cout << "<Expression> -> Number (" << num << ")" << endl;
      }  else {
        cout << "expression problem" << endl;
      }
    }
  private:
    string expType;
    int num;
}; 

// NewExpression node 
class newexpNode : public Node 
{
  public:
    newexpNode(string t) : Node () {
      type = t;
      id = "";
    }
    
    newexpNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 
    
    void printNewExp() {
        cout << "<NewExpression> -> new <SimpleType> ";
        for(unsigned int i = 0; i < children[1]->children.size(); i++) {
          cout << "[<Expression>] ";
        }
        for(unsigned int i = 0; i < children[2]->children.size(); i++) {
          cout << "[] ";
        }
        cout << endl;
    }
    
    void printChildren(int index) {
        for(unsigned int i = 0; i < children[index]->children.size(); i++) {
          children[index]->children[i]->printNode();
        }
    }

    virtual void printNode(ostream * out = 0) {
      if(type == "parens") {
        cout << "<NewExpression> -> new identifier (" << id 
             << ") ( <ArgList> )" << endl;
        children[0]->printNode();
      } else if(type == "empty") {
        cout << "<NewExpression> -> new <SimpleType>" << endl;
        children[0]->printNode();
      } else if(type == "bracks") {
        printNewExp();
        children[0]->printNode();
        printChildren(1);
        printChildren(2);
      } else {
        cout << "new expression problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// argList node that either prints to epsilon or to expList
class arglistNode : public Node 
{
  public:
    arglistNode(string t) : Node () {
      type = t;
    } 

    void printArgList() {
        cout << "<ArgList> -> ";
        for(unsigned int i = 0; i < children[0]->children.size() - 1; i++) {
          cout << "<Expression> , ";
        }
        cout << "<Expression>" << endl;
    }
    
    void printChildren() {
        for(unsigned int i = 0; i < children[0]->children.size(); i++) {
          children[0]->children[i]->printNode();
        }
    }
    
    virtual void printNode(ostream * out = 0) {
      if(type == "empty") {
        cout << "<ArgList> -> epsilon" << endl;
      } else if (type == "rec") {
        printArgList();
        printChildren();
      } else {
        cout << "arglist problem" << endl;
      }
    }
  private:
    string type;
}; 

// Name Node
class nameNode : public Node 
{
  public:
    nameNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Name> -> ";
      if(type == "this") {
        cout << "this" << endl;
      } else if (type == "id") {
        cout << "identifier (" << id << ")" << endl;
      } else if (type == "dotid") {
        cout << "<Name> . identifier (" << id << ")" << endl;
        children[0]->printNode();
      } else if (type == "exp") {
        cout << "<Name> [ <Expression> ]" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "name problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// Type node where t defines either a simpleType or a 
// recursive type [] 
class typeNode : public Node 
{
  public:
    typeNode(string t) : Node () {
      type = t;
    } 
    
    string getType() {
      if(type == "simpleType") {
        return children[0]->getType();
      } else if(type == "type") {
      return children[0]->getType() + "[]";
      } else {
        cout << "PROBLEM IN TYPE  NODE - GETTYPE()" << endl;
        return INVALIDSYM;
      }
    }

    virtual void printNode(ostream * out = 0) {
      cout << "<Type> -> ";
      if(type == "simpleType") {
        cout << "<SimpleType>" << endl;
        children[0]->printNode();
      } else if (type == "type") {
        cout << "<Type> []" << endl;
        children[0]->printNode();
      } else {
        cout << "type problem" << endl;
      }
    }
  private:
    string type;
}; 

// SimpleType Node which right now is just int
class simpleTypeNode : public Node 
{
  public:
    simpleTypeNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 
    
    string getType() {
      if(type == "int") {
        return type;
      } else if (type == "id") {
        return id;
      } else {
        cout << "PROBLEM IN SIMPLETYPE - GETTYPE" << endl;
        return INVALIDSYM;
      }
    }

    virtual void printNode(ostream * out = 0) {
      if(type == "int") {
        cout << "<SimpleType> -> " << type << endl; 
      } else if (type == "id") {
        cout << "<SimpleType> -> identifier (" << id << ")" << endl;
      } else {
        cout << "simpleType problem" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// Product Op Node where t tells us what kind of operator it is
class proopNode : public Node 
{
  public:
    proopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Sum Op Node where t tells us what kind of operator it is
class sumopNode : public Node 
{
  public:
    sumopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Relation Op Node where t tells us what kind of operator it is
class relopNode : public Node 
{
  public:
    relopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
}; 

// Unary Op Node where t tells us what kind of operator it is
class unyopNode : public Node 
{
  public:
    unyopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << type;
    }
    
  private:
    string type;
};

#endif
