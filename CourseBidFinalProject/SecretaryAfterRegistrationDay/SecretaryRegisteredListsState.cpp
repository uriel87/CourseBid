#include "SecretaryRegisteredListsState.h"

//get an input and act accourdingly
void SecretaryRegisteredListsState:: handleInput(int input) {
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			state = new CourseListPerStudentState(this->seasonConfig);
			break;
		case 2:
			state = new StudentsListPerCourseState(this->seasonConfig);
			break;
		case 3:
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
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
}

// display operations
void SecretaryRegisteredListsState :: display() {
	system("cls");
	cout << "Wellcome to secretary screen\n\n";
	cout << "Enter your operation: \n\n";
	cout << "1. display course list per student \n2. display students list per course \n3. exit\n" << endl;
}


