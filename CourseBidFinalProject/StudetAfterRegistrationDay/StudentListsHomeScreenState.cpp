#include "StudentListsHomeScreenState.h"

void StudentListsHomeScreenState::handleInput(int input) {
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			state = new StudentRegisteredCourseListState(this->seasonConfig, this->student);
			break;
		case 2:
			state = new StudentUnregisteredCourseListState(this->seasonConfig, this->student);
			break;
		case 3:
			state = new LoginState(this->seasonConfig);
			break;
		default:

			break;
		}
		if (state != NULL) {
			state->context = context;
			context->setState(state);
		}
	}
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
}

void StudentListsHomeScreenState::display() {
	system("cls");
	cout << "Wellcome to secretary screen\n\n";
	cout << "Enter your operation: \n\n";
	cout << "1. display registered course list\n2. display unregistered course list\n3. exit\n" << endl;
}

