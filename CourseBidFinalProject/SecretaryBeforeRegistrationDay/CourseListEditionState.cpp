#include "CourseListEditionState.h"

CourseListEditionState::CourseListEditionState(SeasonConfig &seasonConfig) :seasonConfig(seasonConfig) {}

// get the name of specific course by index
string CourseListEditionState::get(int index) { 
	return this->seasonConfig.courses.get(index).name.get();
}

// select specific course by index and move to anouther state to show details about it 
void CourseListEditionState::select(int index)  { 
	UILibraryState * state = new CourseEditingState(seasonConfig.courses.get(index),seasonConfig);
	state->context = this->context;
	state->context->setState(state);
}

// delete course from the system by index, also make sure deletion is allowed
void CourseListEditionState::deletee(int index) {
	system("cls");
	bool valid_to_delete = true;
	
	for (int i = 0; i < seasonConfig.students.count(); i++) {
		for (int j = 0; j < seasonConfig.students.get(i).completedCoursesList.count(); j++) {
			if (seasonConfig.courses.get(index).getId() == seasonConfig.students.get(i).completedCoursesList.get(j).getId()) {
				valid_to_delete = false;
			}
		}
	}

	if (!valid_to_delete) {
		cout << "Course cannot be deleted because there are student that already comlpeted this course \n";
		_sleep(3000);
		return;
	}

	for (int i = 0; i < seasonConfig.courses.count(); i++) {
		for (int j = 0; j < seasonConfig.courses.get(i).pre.count(); j++ ){
			if (seasonConfig.courses.get(index).getId() == seasonConfig.courses.get(i).pre.get(j).getId()) {
				valid_to_delete = false;
			}
		}
	}

	if (!valid_to_delete) {
		cout << "Course cannot be deleted because this course is included in other pre course list \n";
		_sleep(3000);
		return;
	}
	else {
		seasonConfig.courses.remove(index);
		cout << " the course is deleted" << endl << endl;
		_sleep(3000);
	}


}

// Check validation of input
int insertNumber() {
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

// Add Course to the system
void CourseListEditionState::add() {
	system("cls");
	auto course = this->seasonConfig.getFactory().allocate<Course>();
	string  name, description;
	int  choise = 1;

	try {

		cout << "Enter course name: ";
		cin.ignore();
		getline(cin, name);
		course.name.set(name);

		cout << "Enter description course: ";
		getline(cin, description);
		course.description.set(description);

		cout << "Enter number of max students  in course: ";
		course.maxNumberOfStudents.set(insertNumber());

		cout << "Enter teaching hours: ";
		course.teachingHours.set(insertNumber());
		cout << "For adding pre courses you need to go to edit this course" << endl << endl;
		seasonConfig.courses.add(course);
		cout << "The course was added" << endl;
		_sleep(2000);
	}
	catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}
}

// Exit from this state and move to anouther state
void CourseListEditionState::exitt() {
	UILibraryState * state = new SecretaryHomeScreenState(this->seasonConfig);
	state->context = this->context;
	this->context->setState(state);
}

// Count the number of courses in the list
int CourseListEditionState::count() {
	return this->seasonConfig.courses.count();
}