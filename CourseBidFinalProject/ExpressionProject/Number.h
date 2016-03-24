#pragma once

/* Livne Lang */

#ifndef NUMBER_H
#define NUMBER_H
#include "Expression.h"

class Number : public Expression {

public:
	/*Number Constructor*/
	Number(int number_) : number(number_) { }
	/* Evaluate Function*/
	double evaluate();
private:
	double number;
};

#endif