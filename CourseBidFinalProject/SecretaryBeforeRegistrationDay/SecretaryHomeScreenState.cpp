#include "SecretaryHomeScreenState.h"


SecretaryHomeScreenState::SecretaryHomeScreenState(SeasonConfig & seasonConfig):seasonConfig(seasonConfig) {}

// get an input and act accourdingly
void SecretaryHomeScreenState::handleInput(int input) {
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			state = new ExpressionEditingState(this->seasonConfig);
			break;
		case 2:
			state = new StudentListEditingState(this->seasonConfig);
			break;
		case 3:
			state = new CourseListEditionState(this->seasonConfig);
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:

			break;
		}
		if (state != NULL) {
			state->context = context;
			context->setState(state);
		}
	} catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
}

// Display list of options
void SecretaryHomeScreenState :: display(){
	system("cls");
	cout << "Wellcome to secretary screen\n\n";
	cout << "Enter your operation: \n\n";
	cout << "1. Setting formula Screen\n2. Student list screen\n3. Course list screen\n4. exit\n" << endl;
}