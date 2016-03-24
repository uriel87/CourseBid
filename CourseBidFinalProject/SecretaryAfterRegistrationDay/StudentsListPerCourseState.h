#pragma once

/* Tomer Luster */

#ifndef STUDENTS_LIST_PER_COURSE_STATE_H
#define STUDENTS_LIST_PER_COURSE_STATE_H

#include "SecretaryRegisteredListsState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"

class StudentsListPerCourseState : public UILibraryState {

private:
	SeasonConfig seasonConfig;

public:
	StudentsListPerCourseState(SeasonConfig & seasonConfig) :seasonConfig(seasonConfig){}

	// Handle the input that recevied from the user
	void handleInput(int input);

	//Display the current view
	void display();
};

#endif

