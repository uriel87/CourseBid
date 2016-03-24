#pragma once

/* Uriel Chechique*/

#ifndef CALCULATE_SCHEDULING_H
#define CALCULATE_SCHEDULING_H

#include <lemon/lp.h>



#include "SeasonConfig.h"

#define SeasonConfigId 1

using namespace lemon;

#define DB_FILE_NAME "../CourseBid/db.txt"
#define GENERATED_ID_FILE_NAME "../CourseBid/generatedIds.txt"

class CalculateSchedulingOperation
{
private:
	SeasonConfig seasonConfig;
public:
	CalculateSchedulingOperation(SeasonConfig & seasonConfig);
};

#endif