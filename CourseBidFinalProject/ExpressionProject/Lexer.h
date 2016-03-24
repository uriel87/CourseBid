#pragma once

/* Livne Lang */

#ifndef LEXER_H
#define LEXER_H

#include <stack>
#include <list>
#include <map>
#include <vector>
#include "Parser.h"

using namespace std;

class Lexer {
public:
	/*Division Cunstructor*/
	Lexer(string &);
	/*Division Destrctor*/
	~Lexer();
	/*Tokenize Our String into vector*/
	bool tokenize();		
	/*Will Calculate our RPN Expression, '@' is needed*/
	Expression * getExpression(double _at);	
	/*Set Error Flag Function*/
	void setHasError(bool);			
	/* Get Error Flag Function */
	bool getHasError();		
	/*convert our string to full numbers*/
	void stringToFullNumbers(string &exprString);	
	/*Expression String Setter*/
	void setExprString(string &str);				
	/*Sets The '@' Parameter*/
	void setAt(int value);								
	/*Gets The '@' Parameter*/
	int getAt();										

private:
	bool hasError = false;
	Parser* parser;
	string exprString;
	vector<char> tokens;
	map<char, pair<int, int>*> opMap;
	int at; // This Is Our Special Parameter -- > '@'
};



#endif 
