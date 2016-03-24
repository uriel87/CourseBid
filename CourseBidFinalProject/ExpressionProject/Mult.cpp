#include "Mult.h"

/* Evaluate Function,
* Returns Mult Arithemetical Result
*/
double Mult::evaluate() {
	return (left->evaluate()) * (right->evaluate());

}
