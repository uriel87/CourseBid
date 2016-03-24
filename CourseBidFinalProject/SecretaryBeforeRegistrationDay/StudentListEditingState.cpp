#include "StudentListEditingState.h"

StudentListEditingState::StudentListEditingState(SeasonConfig & seasonConfig):seasonConfig(seasonConfig){}

// get the studnet name by specific index
string StudentListEditingState::get(int index)  {
	return this->seasonConfig.students.get(index).name.get();
}

// get index from the student list and move to another state to see the details for that student
void StudentListEditingState::select(int index) {
	UILibraryState * state = new StudentEditingState(seasonConfig.students.get(index), seasonConfig);
	state->context = this->context;
	state->context->setState(state);
}

// delete student from the system by specific index
void StudentListEditingState::deletee(int index)  {
	seasonConfig.students.remove(index);
}

// add new studnet to the list 
void StudentListEditingState::add() {
	system("cls");
	auto student = this->seasonConfig.getFactory().allocate<Student>();
	string name;
	try {

		cout << "Please enter the full name: ";
		cin.ignore();
		getline(cin, name);
		student.name.set(name);
		this->seasonConfig.students.add(student);

	} catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}
}

// exit from the current state and move to another one
void StudentListEditingState::exitt() {
	UILibraryState * state = new SecretaryHomeScreenState(this->seasonConfig);
	state->context = this->context;
	this->context->setState(state);
}

// count the number of studnet in the list and return it 
int StudentListEditingState::count() {
	return this->seasonConfig.students.count();
}