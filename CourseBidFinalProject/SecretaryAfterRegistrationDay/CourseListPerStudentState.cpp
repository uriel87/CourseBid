#include "CourseListPerStudentState.h"

// run on student list and display it to the screen
void displayStudentList(SeasonConfig & seasonConfig) {
	system("cls");

	cout << "Student lis t :" << endl << endl;
		 
	for (int i = 0; i < seasonConfig.students.count(); i++) {
		cout << i << ". " << seasonConfig.students.get(i).name.get() << endl;
	}

}

// insert student index and check validation
int insertStudentListIndex() {
	int num;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  try again \n";
		cin >> num;
	}
	return num;
}

// show all the  registered courses list for specific student 
void showCourseList(SeasonConfig & seasonConfig, int index) {
	system("cls");

	cout << "Student course list: " << endl << endl;

	for (int i = 0; i < seasonConfig.students.get(index).registeredCoursesList.count(); i++) {
		cout << i << ". " << seasonConfig.students.get(index).registeredCoursesList.get(i).name.get() << endl;
	}

	cout << endl << endl << "To exit press any key \n";
}

// receive an input and act accourdingly
void CourseListPerStudentState::handleInput(int input) {
	char temp;
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			displayStudentList(this->seasonConfig);
			cout << "Please choose index: ";
			showCourseList(this->seasonConfig, insertStudentListIndex());
			cin >> temp;
		case 2:
			state = new SecretaryRegisteredListsState(seasonConfig);
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

// display the options
void CourseListPerStudentState::display() {
	system("cls");

	cout << "1. display list\n2. exit\n" << endl;
}


