#pragma once

/* Uriel Chechique*/

#ifndef STUDENT_COMPLETED_COURSE_LIST_STATE_H
#define STUDENT_COMPLETED_COURSE_LIST_STATE_H


#include "ListDisplayState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"
#include "CourseEditingState.h"

class StudentCompletedCourseListState : public ListDisplayState {

private:
	SeasonConfig seasonConfig;
	Student student;

public:

	StudentCompletedCourseListState(SeasonConfig &seasonConfig, Student  &student) :seasonConfig(seasonConfig), student(student){};

	// Get one student name
	string get(int index);

	// function not available here
	void select(int index);

	// Delete student fron the list
	void deletee(int index);

	// Add student to the list
	void add();

	// Exit from screen
	void exitt();

	// Count the number of students in the list
	int count();

};

#endif


