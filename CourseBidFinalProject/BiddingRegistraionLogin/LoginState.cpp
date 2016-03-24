#include "LoginState.h"

// Insert index and check valid number
int insertIndex() {
	int identification;
	cout << "Enter your identification: ";
	cin >> identification;
	if (!cin) {
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
	}
	return identification;
}

// Receive an innput and act accourdingly
void LoginState::handleInput(int input){
	try {
		UILibraryState* state = NULL;
		int id;
		switch (input) {
		case 1:
			id = checkIdentification();
			if (id > -1){
				for (int i = 0; i < seasonConfig.students.count(); i++) {
					if (seasonConfig.students.get(i).getId() == id) {
						state = new StudentRegisterState(this->seasonConfig, this->seasonConfig.students.get(i));
					}
				}
				
			}
			else {
				this->seasonConfig.getFactory().construct<Terminal>(TERMINAL_ID).status.set(LOCKED_MODE);
				system("cls");
				cout << "!!!!!!!!!!!!!!!!!!!! The terminal  is locked !!!!!!!!!!!!!!!!!!!!" << endl << endl;
				exit(EXIT_SUCCESS);
			}
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

// Display instructions
void LoginState::display(){
	system("cls");
	cout << "Enter your operation: " << endl;
	cout << "1. Enter identification\n2. exit" << endl;
}

// Check user identification by uniqe id in the db
int LoginState::checkIdentification()
{
	for (int i = 0; i < 3; i++) {
		int id = insertIndex();
		for (int j = 0; j < seasonConfig.students.count(); j++)
		if (id == seasonConfig.students.get(j).getId()) {
			return id;
		}
	}
	return -1;
}