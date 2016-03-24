#pragma once

/* Uriel Chechique*/

#ifndef STUDENT_EDITING_STATE_H
#define STUDENT_EDITING_STATE_H

#include "EntryDisplayState.h"
#include "StudentListEditingState.h"
#include "StudentCompletedCourseListState.h"

#define NumberOfStudentFields 2

class StudentEditingState : public EntryDisplayState {

private:
	Student student;
	SeasonConfig seasonConfig;

public:
	StudentEditingState(Student & student, SeasonConfig &seasonConfig);

	// Get the number of fields for student object
	int getFieldCount();
	
	// Get the caption of the field
	string getCaption(int index);

	// Get value of the field
	string getValue(int index);

	// Exit from the screen
	void exitt();

	// Edit field value
	void edit(int index);


};


#endif
