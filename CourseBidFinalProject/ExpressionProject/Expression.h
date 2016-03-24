#pragma once

/* Livne Lang */

#ifndef EXPRESSION_H
#define EXPRESSION_H


class Expression {
public:
	/* Expression Abstract Class
	* has virtual function --> evaluate () = 0
	*/
	virtual double evaluate() = 0;
};

#endif
