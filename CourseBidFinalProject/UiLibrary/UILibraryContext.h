#pragma once

/* Tomer Luster */

#ifndef UILIBRARY_CONTEXT_H
#define UILIBRARY_CONTEXT_H

#include <iostream>
#include <string>
#include "UILibraryState.h"

class UILibraryContext {

public:

	UILibraryState * state; 

	UILibraryContext();

	// Set the new state
	void setState(UILibraryState* state);

	// loop for run the display and handle input
	void run();

protected:


};


#endif
