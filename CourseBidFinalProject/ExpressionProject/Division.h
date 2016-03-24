#pragma once

/* Livne Lang */

#ifndef DIVISION_H
#define DIVISION_H

#include "BinaryOperator.h"

class Division : public BinaryOperator {
public:
	/*Division Cunstructor*/
	Division(Expression * left, Expression * right) : BinaryOperator(left, right){ }
	/*Evaluate Function*/
	double evaluate();
};

#endif
