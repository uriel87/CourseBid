#pragma once

/* Roni Chabra*/

#ifndef STUDENT_REGISTER_STATE_H
#define STUDENT_REGISTER_STATE_H

#include "LoginState.h"
#include "Lexer.h"

using namespace std;

class StudentRegisterState : public UILibraryState {

private:
	SeasonConfig seasonConfig;
	Student student;
	double points;

public:
	StudentRegisterState(SeasonConfig & seasonConfig, Student & student);

	// Handle the input that recevied from the user
	void handleInput(int input);

	//Display the current view
	void display();
	
};


#endif
