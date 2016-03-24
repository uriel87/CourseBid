#pragma once

/* Tomer Luster */

#ifndef COURSE_LIST_PER_STUDENT_STATE_H
#define COURSE_LIST_PER_STUDENT_STATE_H


#include "SecretaryRegisteredListsState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"

class CourseListPerStudentState : public UILibraryState {

private:
	SeasonConfig seasonConfig;

public:

	CourseListPerStudentState(SeasonConfig & seasonConfig) :seasonConfig(seasonConfig){}

	// Handle the input that recevied from the user
	void handleInput(int input);

	//Display the current view
	void display();

};

#endif