#include "StudentEditingState.h"

StudentEditingState::StudentEditingState(Student & student, SeasonConfig & seasonConfig):student(student), seasonConfig(seasonConfig) {}

// Count the number of fields and return it 
int StudentEditingState::getFieldCount() {
	return NumberOfStudentFields;
}

// get the caption for specific index
string StudentEditingState::getCaption(int index){
	switch (index) {
	case 0:
		return "name";
		break;
	case 1: 
		return "completed courses list";
		break;
	default:
		return "ERROR";
		break;
	}
}

// get the value for specific index
string StudentEditingState::getValue(int index) {
	ostringstream lines;
	switch (index) {
	case 0:
		return student.name.get();
		break;
	case 1: 
		for (int i = 0; i < student.completedCoursesList.count(); i++){

			lines << student.completedCoursesList.get(i).name.get();
			if (i + 1 < student.completedCoursesList.count()) {
				lines << ", ";
			}
		}
		return lines.str();
		break;
	default:
		return "ERROR";
		break;
	}

}

// edit filed by specific index
void  StudentEditingState::edit(int index) {
	string name;
	UILibraryState * state = NULL;
	switch (index) {
	case 0:
		cout << getCaption(0) << " : " << getValue(0) << endl << endl;
		cout << "Please enter new value \n\n";
		cin.ignore();
		getline(cin, name);
		student.name.set(name);
		break;

	case 1:
		state = new StudentCompletedCourseListState(this->seasonConfig,this->student);
		if (state != NULL) {
			state->context = this->context;
			context->setState(state);
		}
		break;
	default:
		break;
	}
}

// exist the state and move to another one
void StudentEditingState::exitt() {
	UILibraryState * state = new StudentListEditingState(this->seasonConfig);
	state->context = this->context;
	context->setState(state);
}



