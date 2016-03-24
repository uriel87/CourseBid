#pragma once

/* Tomer Luster */

#ifndef UILIBRARY_STATE_H
#define UILIBRARY_STATE_H


#include <iostream>

using namespace std;

class UILibraryContext;


class UILibraryState{  // abstract class for screens

public:

	UILibraryContext * context;

	// Get an input and act accourdingly
	virtual void handleInput(int input) = 0;

	// Display state
	virtual void display() = 0;




};


#endif
