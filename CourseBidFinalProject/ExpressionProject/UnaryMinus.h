#pragma once

/* Livne Lang */

#ifndef UNARY_MINUS_H
#define UNARY_MINUS_H


#include "Expression.h"

class UnaryMinus : public Expression {
private:
	Expression* expr;
public:
	/* Evaluate Function*/
	double evaluate();
	/* UnaryMinus Constructor */
	UnaryMinus(Expression * pExpression) : expr(pExpression) {};
};


#endif
