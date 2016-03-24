#pragma once

/*  Tomer Luster */

#ifndef BIDDING_H
#define BIDDING_H

#include "NonRefField.h"


class Bidding : public IdObj{

public:

	NonRefField<int, 0> pointsAllocated;
	NonRefField<string, 1> courseId;
	Bidding(int id, IdObjectFactory &factory) : IdObj(id, factory), pointsAllocated(*this), courseId(*this) {}

};

#endif

