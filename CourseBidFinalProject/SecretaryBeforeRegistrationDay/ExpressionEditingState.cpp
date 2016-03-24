#include "ExpressionEditingState.h"

// return the number of field for expression object
int ExpressionEditingState::getFieldCount() {
	return 1;
}

// get the caption from specific index
string ExpressionEditingState::getCaption(int index){
	return "Formula";
}

// get the value from specific index
string ExpressionEditingState::getValue(int index) {

	try {
		return this->seasonConfig.pointAllocFormula.get();
	}catch (exception e) {
		return "Empty formula";
	}
	
}

// edit the formula 
void  ExpressionEditingState::edit(int index) {
	string formula;
	cout << "Please enter the new expression" << endl;
	cin.ignore();
	getline(cin, formula);
	this->seasonConfig.pointAllocFormula.set(formula);
}

// exit the state and move to anouther one
void ExpressionEditingState::exitt() {
	UILibraryState * state = new SecretaryHomeScreenState(this->seasonConfig);
	state->context = this->context;
	context->setState(state);
}
