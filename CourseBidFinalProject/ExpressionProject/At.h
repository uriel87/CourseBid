#pragma once

/* Livne Lang */

#ifndef AT_H
#define AT_H

#include "Expression.h"


class At : public Expression {
public:
	/* evaluate function of At*/
	 double evaluate(double at);
	 double evaluate();
};


#endif
