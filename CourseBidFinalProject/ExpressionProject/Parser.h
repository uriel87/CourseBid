#pragma once

/* Livne Lang */

#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <list>
#include <map>
#include <vector>
#include <iostream>
#include "Plus.h"
#include "Minus.h"
#include "UnaryMinus.h"
#include "Mult.h"
#include "Division.h"
#include "Number.h"
#include "At.h"
#include "ExpressionException.h"

using namespace std;

class Parser {
public:
	/*Parser Constructor*/
	Parser() {
		opMap['+'] = new pair<int, int>(0, 0);
		opMap['-'] = new pair<int, int>(0, 0);
		opMap['*'] = new pair<int, int>(5, 0);
		opMap['/'] = new pair<int, int>(5, 0);
	}
	/* Create A New Number Expression */
	void processNumber(int);				
	/* Create A New Operator Expression */
	void processOperator(char);									
	/* Create A New At Expression */
	void processAt();															
	/* Get Expression Function */
	Expression * getExpression();					
	/* Infix To PostFix Function */
	bool infixToPostFix(vector<char>& input, int size, vector<char> & strArray);  


private:
	bool isOperator(char c);
	bool isParanthesis(char c);
	int cmpPrecedence(char op1, char op2);
	bool isAssociative(char op, int size);

	map<char, pair<int, int>*> opMap;
	stack<Expression*> exprStack;
};


#endif 
