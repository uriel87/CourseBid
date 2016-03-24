#pragma once

/* Tomer Luster */

#ifndef LIST_DISPLAY_STATE_H
#define LIST_DISPLAY_STATE_H

#include <string>
#include <stdio.h>
#include "UILibraryState.h"

class ListDisplayState : public UILibraryState {
public:

	// Get an input and act accourdingly
	void handleInput(int input);

	// Display the list
	void display();

	// get name of object
	virtual string get(int index) = 0;

	// select object from list
	virtual void select(int index) = 0;

	// add object to the list
	virtual void add() = 0;

	// delete object from the list
	virtual void deletee(int index) = 0;

	// exit from current view
	virtual void exitt() = 0;

	// count the number of elements in the list 
	virtual int count() = 0;

};


#endif
