#pragma once

/* Tomer Luster */

#ifndef STUDENT_LIST_HOME_SCREEN_STATE_H
#define STUDENT_LIST_HOME_SCREEN_STATE_H

#include "StudentRegisteredCourseListState.h"
#include "StudentUnregisteredCourseListState.h"
#include "SeasonConfig.h"
#include "UILibraryContext.h"
#include "LoginState.h"

class StudentListsHomeScreenState : public UILibraryState {

private:
	SeasonConfig seasonConfig;
	Student student;

public:

	StudentListsHomeScreenState(SeasonConfig & seasonConfig, Student  & student) :seasonConfig(seasonConfig), student(student){}

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display operation on the screen
	void display();
};

#endif

