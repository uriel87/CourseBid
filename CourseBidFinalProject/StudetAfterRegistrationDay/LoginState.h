#pragma once

/* Tomer Luster */

#ifndef LOGIN_STATE_H
#define LOGIN_STATE_H


#include "Terminal.h"
#include "StudentListsHomeScreenState.h"


#define TERMINAL_ID 8
#define LOCKED_MODE 1

class LoginState : public UILibraryState{

private:
	SeasonConfig seasonConfig;

public:
	LoginState(SeasonConfig & seasonConfig) :seasonConfig(seasonConfig){};

	// get an input and handle it accourdingly
	void handleInput(int input);

	// display operation on the screen
	void display();

	// check the indefication of the student
	int checkIdentification();
};

#endif