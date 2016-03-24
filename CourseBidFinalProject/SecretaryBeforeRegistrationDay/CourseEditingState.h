#pragma once

/* Uriel Chechique*/

#ifndef COURSE_EDITING_STATE_H
#define COURSE_EDITING_STATE_H


#include "EntryDisplayState.h"
#include "CourseListEditionState.h"
#include <lemon/list_graph.h>
#include <lemon/maps.h>
#include <lemon/bfs.h>

#define NumberOfCourseFields 5

using namespace lemon;

class CourseEditingState : public EntryDisplayState {

private:

	Course course;
	SeasonConfig seasonConfig;

public:

	CourseEditingState(Course & course, SeasonConfig & seasonConfig);

	// Get the number of fields for course object
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
