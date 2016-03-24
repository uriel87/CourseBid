#pragma once

/* Livne Lang */

#ifndef MINUS_H
#define MINUS_H

#include "BinaryOperator.h"
class Minus : public BinaryOperator {

public:
	/*Minus Constructor*/
	Minus(Expression *left, Expression *right) : BinaryOperator(left, right) { }

private:
	/* Evaluate Function*/
	double evaluate();
};


#endif
