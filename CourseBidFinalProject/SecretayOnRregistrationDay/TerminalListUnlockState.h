#pragma once

/* Tomer Luster */

#ifndef TERMINAL_LIST_UNLOCK_STATE_H
#define TERMINAL_LIST_UNLOCK_STATE_H

#include "UILibraryState.h"
#include "SystemState.h"

#define UNLOCK_TERMINAL 0
#define LOCKED_TERMINAL 1

#define LOCKED "Locked"
#define OPEN "Open"
#define ERROR "Error"

class TerminalListUnlockState : public UILibraryState{

private:
	SystemState systemState;

public:

	TerminalListUnlockState(SystemState & systemState) : systemState(systemState){};

	// get input and handle it accourdingly
	void handleInput(int input);

	// display the operations on the screen
	void display();
};

#endif

