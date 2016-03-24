#pragma once

/* Uriel Chechique*/

#ifndef SECRETARY_HOME_SCREEN_STATE_H
#define SECRETARY_HOME_SCREEN_STATE_H

#include "UILibraryState.h"
#include "StudentListEditingState.h"
#include "ExpressionEditingState.h"
#include "CourseListEditionState.h"
#include "SeasonConfig.h"

class SecretaryHomeScreenState : public UILibraryState {

private:
	SeasonConfig seasonConfig;

public:
	SecretaryHomeScreenState(SeasonConfig &seasonConfig);

	//get an input and act accourdingly
	void handleInput(int input);

	// display the operations
	void display();
};


#endif

