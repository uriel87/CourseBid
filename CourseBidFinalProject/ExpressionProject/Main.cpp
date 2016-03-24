#include <iostream>
#include "Lexer.h"
#include "Parser.h"
using namespace std;

void main()
{
	/* Just Strings For Example*/
	string s1 = "2*@+100";
	//string s2 = "2+15-33";
	//string exprString= "7*6+2-5";

	/* Create A New Lexer With Your Expression*/
	Lexer *L1 = new Lexer(s1);

	/* Pay Attention, you have to send Lexer->GetExpression The '@' parameter*/
	try {
		cout << "********* Lexer-Parser Program **********" << endl;
		cout << "*********        Welcome       **********\n" << endl;
		cout << "Expression Tree Evaluate: ";
		cout << L1->getExpression(5)->evaluate() << endl << endl;
	}
	catch (ExpressionException e) {
		cout << e.what();
	}
}

