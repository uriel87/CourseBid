#include "Division.h"

/*Evaluate Function
* Computes Arithemetical Divison action
*/
double Division::evaluate( ) {
	return (right->evaluate() / left->evaluate());
}

