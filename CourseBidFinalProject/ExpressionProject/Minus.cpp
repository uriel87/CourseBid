#include "Minus.h"
/* Evaluate Function,
* Returns Minus Arithemetical Result
*/
double Minus::evaluate() {
	return right->evaluate() - left->evaluate();
}
