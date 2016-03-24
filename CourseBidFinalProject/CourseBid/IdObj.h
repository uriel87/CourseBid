#pragma once

/*  Tomer Luster */

#ifndef IDOBJ_H
#define IDOBJ_H

#include "IdObjectFactory.h"
#include <iostream>

class IdObj{

private:

	int id;
	IdObjectFactory factory;

public:

	IdObj(int id, IdObjectFactory & factory) : factory(factory), id(id) {}; 
	// Get the id of the object 
	int getId() { return id; } 
	// Get the Factory instance
	IdObjectFactory getFactory()  {return factory; }

};

#endif