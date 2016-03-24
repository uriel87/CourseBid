#pragma once

/* Livne Lang */

#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H
#include "Expression.h"

class BinaryOperator : public Expression {
protected:
	Expression* left;
	Expression* right;
public:
	/*BinaryOperator Cunstructor*/
	BinaryOperator(Expression *left, Expression *right) : left(left), right(right) { }
};


#endif
