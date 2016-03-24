#pragma once

/* Tomer Luster */

#ifndef TECHNICIAN_HOME_SCREEN_STATE_H
#define TECHNICIAN_HOME_SCREEN_STATE_H

#include "SeasonConfig.h"
#include "UILibraryContext.h"
#include "TerminalTestingState.h"
#include "Terminal.h"

class TechnicianHomeScreenState : public UILibraryState {

private:

	SeasonConfig seasonConfig;
	Terminal terminal;

public:

	TechnicianHomeScreenState(SeasonConfig & seasonConfig, Terminal & terminal) :seasonConfig(seasonConfig),terminal(terminal){};

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display the opertation on the screen
	void display();
};


#endif