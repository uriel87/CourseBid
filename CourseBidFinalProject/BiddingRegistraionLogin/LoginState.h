#pragma once

/* Roni Chabra*/

#ifndef LOGIN_STATE_H
#define LOGIN_STATE_H

#include "SeasonConfig.h"
#include "UILibraryContext.h"
#include "StudentRegisterState.h"
#include "Terminal.h"


#define TERMINAL_ID 5
#define LOCKED_MODE 1

class LoginState : public UILibraryState{

private:
	SeasonConfig seasonConfig;

public:

	LoginState(SeasonConfig & seasonConfig) :seasonConfig(seasonConfig){};
	
	// Handle the input that recevied from the user
	void handleInput(int input);
	
	//Display the current view
	void display();

	// Check the uniqe id of student for login
	int checkIdentification();
};

#endif