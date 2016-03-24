#pragma once

/*  Tomer Luster */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "RefListField.h"
#include "NonRefField.h"


class Terminal: public IdObj
{
public:
	NonRefField<string ,0> name;		
	NonRefField<int , 1> status;
	Terminal(int id, IdObjectFactory &factory) : IdObj(id, factory),name(*this), status(*this) {}
};

#endif
