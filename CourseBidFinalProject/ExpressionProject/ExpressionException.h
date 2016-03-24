#pragma once

/* Livne Lang */

#ifndef EXPRESSION_EXCEPTION_H
#define EXPRESSION_EXCEPTION_H

// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;



class ExpressionException : public exception {

public:
	/*ExpressionException Cunstructor, Inherits From Exception Class
	* This class will use us to catch bad formatted exceptions
	*/
	ExpressionException(const string m = "Bad Expression My Friend \n\n") :msg(m){}
	const char* what(){ return msg.c_str(); }
private:
	string msg;
};


#endif