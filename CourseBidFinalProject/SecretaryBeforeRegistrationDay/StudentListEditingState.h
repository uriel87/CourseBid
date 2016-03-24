#pragma once

/* Uriel Chechique*/

#ifndef STUDENT_LIST_EDITING_STATE_H
#define STUDENT_LIST_EDITING_STATE_H

#include "Student.h"
#include "ListDisplayState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"
#include "SecretaryHomeScreenState.h"
#include "StudentEditingState.h"

class StudentListEditingState : public ListDisplayState {

private:
	SeasonConfig seasonConfig;

public:

	StudentListEditingState(SeasonConfig & seasonConfig);

	// Get one student name
	string get(int index);

	// Select one student and see details about him
	void select(int index);

	// Delete the student fron the system
	void deletee(int index);

	// Add student to the system
	void add();

	// Exit from screen
	void exitt();

	// Count the number of students in the list
	int count();

};

#endif