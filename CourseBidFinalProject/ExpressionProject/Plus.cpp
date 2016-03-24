#include "Plus.h"
/* Evaluate Function,
* Returns Plus Arithemetical Result
*/
double Plus::evaluate() {
	return right->evaluate() + left->evaluate();
}
