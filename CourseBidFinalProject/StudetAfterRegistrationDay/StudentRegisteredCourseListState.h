#pragma once

/* Tomer Luster */

#ifndef STUDENT_REGISTERED_COURSE_LIST_STATE_H
#define STUDENT_REGISTERED_COURSE_LIST_STATE_H

#include <conio.h>
#include "StudentListsHomeScreenState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"

class StudentRegisteredCourseListState : public UILibraryState {

private:
	SeasonConfig seasonConfig;
	Student student;

public:

	StudentRegisteredCourseListState(SeasonConfig & seasonConfig, Student  & student) :seasonConfig(seasonConfig), student(student){}

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display operation on the screen
	void display();

};

#endif