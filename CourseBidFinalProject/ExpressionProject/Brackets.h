#pragma once

/* Livne Lang */

#ifndef BRACKETS_H
#define BRACKETS_H 

#include "Expression.h"


class Brackets : public Expression {
public:
	/*Evaluate function of Brackets*/
	virtual double evaluate();
};


#endif
