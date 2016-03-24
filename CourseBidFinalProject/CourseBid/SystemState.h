#pragma once

/*  Tomer Luster */

#ifndef SYSYEM_STATE_H
#define SYSYEM_STATE_H

#include "RefListField.h"
#include "Terminal.h"



class SystemState : public IdObj {


public:
	RefListField<Terminal, 0> terminals;
	SystemState(int id, IdObjectFactory &factory) : IdObj(id, factory), terminals(*this){};
	
};

#endif