#include "TechnicianHomeScreenState.h"

// get an input and handle it accourdingly
void TechnicianHomeScreenState ::handleInput(int input) {

	try {
		UILibraryState* state = NULL;
		switch (input) {
		case 1:
			state = new TerminalTestingState(seasonConfig,terminal);
			break;
		case 2:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
		if (state != NULL) {
			state->context = context;
			context->setState(state);
		}
	}
	catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}

}

// display the opertation on the screen
void TechnicianHomeScreenState::display() {

	cout << "wellcome technician" << endl;
	cout << "please choose from the foolowing options: " << endl << endl;
	cout << "1. go to testing screen \n2. exit" << endl;

}
