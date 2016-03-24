#pragma once

/* Livne Lang */

#ifndef MULT_H
#define MULT_H
#include "BinaryOperator.h"


class Mult : public BinaryOperator {

public:
	/*Mult Constructor*/
	Mult(Expression *left, Expression *right) : BinaryOperator(left, right) { }
	/* Evaluate Function*/
	double evaluate();
};


#endif
