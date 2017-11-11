##
# Shaya Wolf
# Makefile
# Compilers - Program 5
# 11/16/2017
##

CXX=g++
CXXFLAGS=-std=c++11 -ggdb -Wall
LEX=flex++
LEXFLAGS=--warn
YACC=bison
YACCFLAGS=--report=state -W -d

.PHONY: clean

program5: program5.tab.c program5.tab.h program5_lex.cpp program5.cpp \
		attributes.h node.hpp symbol.h symboltable.hpp
	${CXX} ${CXXFLAGS} program5.cpp program5.tab.c program5_lex.cpp \
		attributes.cpp symbol.cpp -o program5

program5.tab.c : program5.y node.hpp attributes.h
	${YACC} ${YACCFLAGS} program5.y

program5_lex.cpp: program5.lpp node.hpp
	${LEX} ${LEXFLAGS} program5.lpp

clean: 
	/bin/rm -f *.o a.out core.* program5 program5_lex.cpp program5.tab.*
