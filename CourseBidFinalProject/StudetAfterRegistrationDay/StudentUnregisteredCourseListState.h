#pragma once

/* Tomer Luster */

#ifndef STUDENT_UNREGISTERED_COURSE_LIST_STATE_H
#define STUDENT_UNREGISTERED_COURSE_LIST_STATE_H

#include <conio.h>
#include "StudentListsHomeScreenState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"

class StudentUnregisteredCourseListState : public UILibraryState {

private:
	SeasonConfig seasonConfig;
	Student student;

public:

	StudentUnregisteredCourseListState(SeasonConfig & seasonConfig, Student  & student) :seasonConfig(seasonConfig), student(student){}

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display operation on the screen
	void display();

};

#endif
