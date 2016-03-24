#pragma once

/* Tomer Luster */

#ifndef ENTRY_DISPLAY_STATE_H
#define ENTRY_DISPLAY_STATE_H


#include "UILibraryState.h"
#include <string>


class EntryDisplayState : public UILibraryState {

public:

	// Get an input and act accourdingly
	void handleInput(int input);

	// Display the fields on the screen
	void display();

	// count the number of the fields for an object
	virtual int getFieldCount() = 0;

	// return the caption by specific index
	virtual string getCaption(int index) = 0;

	// return the value by specific index
	virtual string getValue(int index) = 0;

	// edit field
	virtual void edit(int index) = 0;

	// exit current state and move the another one
	virtual void exitt() = 0;
};



#endif



