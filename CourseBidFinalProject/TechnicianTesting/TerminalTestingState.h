#pragma once

/* Tomer Luster */

#ifndef TERMINAL_TESTING_STATE_H
#define TERMINAL_TESTING_STATE_H

#define TERMINAL_ID 5
#define INPUT_TEST_FILE "DB_Testing.txt"
#define GENERATED_IDS	"generatedIds.txt"

#include "FileStorage.h"
#include "IdObjectFactory.h"
#include "SeasonConfig.h"
#include "UILibraryContext.h"
#include "TechnicianHomeScreenState.h"
#include "Terminal.h"
#include "CalculateSchedulingOperation.h"




class TerminalTestingState : public UILibraryState{

private:

	SeasonConfig seasonConfig;
	Terminal terminal;


public:

	TerminalTestingState(SeasonConfig & seasonConfig, Terminal & terminal) :seasonConfig(seasonConfig), terminal(terminal){};

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display the opertation on the screen
	void display();

};

#endif

