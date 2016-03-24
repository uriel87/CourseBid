#pragma once

/* Tomer Luster */

#ifndef SECRETARY_REGISTERED_LISTS_STATE_H
#define SECRETARY_REGISTERED_LISTS_STATE_H


#include "CourseListPerStudentState.h"
#include "StudentsListPerCourseState.h"


class SecretaryRegisteredListsState : public UILibraryState {

private:
	SeasonConfig seasonConfig;

public:
	SecretaryRegisteredListsState(SeasonConfig &seasonConfig) :seasonConfig(seasonConfig){};

	// Handle the input that recevied from the user
	void handleInput(int input);

	//Display the current view
	void display();

};

#endif