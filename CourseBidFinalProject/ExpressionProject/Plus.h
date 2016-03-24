#pragma once

/* Livne Lang */

#ifndef PLUS_H
#define PLUS_H

#include "BinaryOperator.h"
class Plus : public BinaryOperator {

public:
	/* Plus Constructor */
	Plus(Expression * left, Expression * right) : BinaryOperator(left, right){ }
	/* Evaluate Function*/
	double evaluate();
};


#endif
