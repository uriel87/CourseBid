#include "StudentCompletedCourseListState.h"

// get the student name from the list by index
string StudentCompletedCourseListState::get(int index) {
	return this->student.completedCoursesList.get(index).name.get();
}

// get an index for specific studnet and move to anouther state to see the details
void StudentCompletedCourseListState::select(int index)  {
	cout << "This option is not available for this list" << endl << "For editing course details go to main screen" << endl;
	_sleep(3000);
}

// delete the course from the list 
void StudentCompletedCourseListState::deletee(int index) {
	student.completedCoursesList.remove(index);
}

// ask for input number and validate it
int insertCourseNumber() {
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

// add course to the list, also check course validations before adding it 
void StudentCompletedCourseListState::add() {
	system("cls");
	int course_number;
	bool all_pre_courses_exist = false;
	cout << "Please choose course to add :" << endl << endl;

	for (int i = 0; i < seasonConfig.courses.count(); i++) {
		cout << endl << i << ". " << seasonConfig.courses.get(i).name.get();
	}

	cout << endl << endl;
	course_number = insertCourseNumber();
	auto course = seasonConfig.courses.get(course_number);

	if (course.pre.count() > 0) {
		for (int i = 0; i < course.pre.count(); i++) {
			for (int j = 0; j < student.completedCoursesList.count(); j++) {
				if (course.pre.get(i).getId() == student.completedCoursesList.get(j).getId()) {
					all_pre_courses_exist = true;
				}
			}
		}
	}
	else {
		all_pre_courses_exist = true;
	}
	if (all_pre_courses_exist) {
		student.completedCoursesList.add(course);
	}
	else {
		cout << "You cannot add this course because this student not compledted its pre courses" << endl;
		_sleep(3000);
	}

}

// Exit from state and move to another state
void StudentCompletedCourseListState::exitt() {
	UILibraryState * state = new SecretaryHomeScreenState(this->seasonConfig);
	state->context = this->context;
	this->context->setState(state);
}

// Count the number of completed courses
int StudentCompletedCourseListState::count() {
	return student.completedCoursesList.count();
}