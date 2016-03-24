#pragma once

/* Uriel Chechique*/

#ifndef EXPRESSION_EDITING_STATE_H
#define EXPRESSION_EDITING_STATE_H

#include "UILibraryContext.h"
#include "EntryDisplayState.h"
#include "SeasonConfig.h"
#include "SecretaryHomeScreenState.h"


class ExpressionEditingState : public EntryDisplayState {


private:
	SeasonConfig seasonConfig;

public:

	ExpressionEditingState(SeasonConfig & seasonConfig) :seasonConfig(seasonConfig){}

	// Get the number of fields for expression object
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