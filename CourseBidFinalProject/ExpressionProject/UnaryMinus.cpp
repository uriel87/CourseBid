#include "UnaryMinus.h"
/* Evaluate Function,
* Returns UnaryMinus Arithemetical Result
*/
double UnaryMinus::evaluate() {
	return -(expr->evaluate());
}
