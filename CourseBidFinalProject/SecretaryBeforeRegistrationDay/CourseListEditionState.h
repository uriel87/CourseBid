#pragma once

/* Uriel Chechique*/

#ifndef COURSE_LIST_EDDITIONSTATE_H
#define COURSE_LIST_EDDITIONSTATE_H

#include <stdlib.h>   
#include "ListDisplayState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"
#include "CourseEditingState.h"
#include "IdObjectFactory.h"
#include "SecretaryHomeScreenState.h"

class CourseListEditionState : public ListDisplayState {


private:
	SeasonConfig seasonConfig;

public:

	CourseListEditionState(SeasonConfig &seasonConfig);

	// Get one course name
	string get(int index);

	// Select one course and see details about him
	void select(int index);

	// Delete the course from the system
	void deletee(int index);

	// Add course to the system
	void add();

	// Exit from screen
	void exitt();

	// Count the number of courses in the list
	int count();

};

#endif