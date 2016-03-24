#include "Lexer.h"

/* Lexer Constructor
* use stringToFullNumbers function to convert hexNumbers
* initialize new parser, and activate tokenize
*/
Lexer::Lexer(string &exprString) : exprString(exprString){
	stringToFullNumbers(exprString);
	this->parser = new Parser();
	if (!tokenize())
		setHasError(true);
}

/*
* Lexer Dsetructor,
* deletes parser accurance 
*/
 Lexer :: ~Lexer() {
	 delete this->parser;
}

/* Lexer Tokenize Function
* makes a vector of char, and use parser tokenize function to break
* it into small pieces
*/
bool Lexer::tokenize() {
	vector<char> string(exprString.begin(), exprString.end());
	return parser->infixToPostFix(string, string.size(), tokens);
}

/* Lexer GetExpression Function
* gets the expression on top of the stack,
* the actuall call perfomrs Parser Class
*/
Expression *Lexer::getExpression(double _at) {
	if (getHasError()){

		throw ExpressionException();
	}

	/* Check '@' reliability */
	if (_at != NULL) {
		try {
			this->setAt((int)_at);
		}
		catch (ExpressionException e) {
			cout << e.what();
		}
	}

	for (unsigned int i = 0; i < tokens.size();i++) {
		
		char temp = tokens.at(i);

		/* Change The '@' into Number Expression*/
		if (temp == '@') {
			parser->processNumber(this->getAt());
			continue; // we won't want to fall & insert another number into the stack
			//parser->processAt();
		}

		if (temp == '+' || temp == '-' || temp == '/' || temp == '*') {
			parser->processOperator(temp);
		}


		else {
			parser->processNumber(temp);
		}

	
	}
	try {
		return parser->getExpression();
	}
	
	catch (exception e) {
		throw e;
	}
}

/* Lexer SetError Function,
* If Error was found, set an error flag
*/
void Lexer::setHasError(bool flag){
	hasError = flag;
}

/* Lexer GetError Function,
* Gets Error Flag
*/
bool Lexer::getHasError(){
	return hasError;
}




/* Converts multiple numbers to full value
*  we need to set numbers in vector in HexDec Values
*/
void Lexer::stringToFullNumbers(string &exprString) {

	string reString;      // our new string
	int temp = 0;		 // actual int number
	vector<int> number; // number vector to run

	for (unsigned int i = 0; i < exprString.size(); i++) {
		// if its a digit
		if (isdigit(exprString[i])) {
			// run until you see an operation
			// As Long As the next character is digit && i < string.length
			while (isdigit(exprString[i]) && i<exprString.size()) {
				number.push_back(exprString[i] - '0');
				i++;
			}
			// if its an operand, lower i minus back cause we wont miss it 
			i--;

			for (unsigned int y = 0; y < number.size(); ++y){
				temp += (int)(pow(10, number.size() - y - 1)*number[y]);
			}
			// empty number vector
			number.erase(number.begin(), number.begin() + (number.size()));
			// push to reString -- > Our New String
			reString.push_back(temp);
			temp = 0;
		}
		// if its an operation
		else {
			reString.push_back(exprString[i]);
		}
	}
	char tochar, t2;
	int t;
	for (unsigned int j = 0; j < reString.size(); j++) {
		tochar = reString[j] - '0';
		t2 = reString[j];
		t = reString[j];
	}

	/* Set New String*/
	setExprString(reString);
}


/* Expression String Setter
* Set the new returned string after restring 
*/
void Lexer::setExprString(string &reString) {
	this->exprString = reString;
}


/* At Parameter Setter,
* set the special @ Parameter
*/
void Lexer::setAt(int value) {
	this->at = value;
}

/* At Parameter Getter*/
int Lexer::getAt() {
	return this->at;
}