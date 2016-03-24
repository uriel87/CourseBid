#include "StudentsListPerCourseState.h"

// Display all the courses list
void displayCourseList(SeasonConfig & seasonConfig) {
	system("cls");

	cout << "Course list :" << endl << endl;

	for (int i = 0; i < seasonConfig.courses.count(); i++) {
		cout << i << ". " << seasonConfig.courses.get(i).name.get() << endl;
	}

}

// validate input
int insertCourseListIndex() {
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

// Show all the student list for specific course
void showStudentList(SeasonConfig & seasonConfig, int index) {
	system("cls");

	cout << "Student list: " << endl << endl;

	for (int i = 0; i < seasonConfig.students.count(); i++){
		for (int j = 0; j < seasonConfig.students.get(i).registeredCoursesList.count(); j++) {
			if (seasonConfig.students.get(i).registeredCoursesList.get(j).getId() == seasonConfig.courses.get(index).getId()) {
				cout << "* " << seasonConfig.students.get(i).name.get() << endl;
			}
		}
		
	}

	cout << endl << endl << "To exit press any key \n";
}

// get an input and act accourdingly
void StudentsListPerCourseState::handleInput(int input) {
	char temp;
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			displayCourseList(this->seasonConfig);
			cout << "Please choose index: ";
			showStudentList(this->seasonConfig, insertCourseListIndex());
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

// display the  operations
void StudentsListPerCourseState::display() {
	system("cls");

	cout << "1. display list\n2. exit\n" << endl;
}
