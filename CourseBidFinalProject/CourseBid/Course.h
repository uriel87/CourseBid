#pragma once

/*  Tomer Luster */

#ifndef COURSE_H
#define COURSE_H

#include "RefListField.h"
#include "NonRefField.h"


class Course: public IdObj
{
public:

	NonRefField<string, 0> name;	
	NonRefField <string, 1> description;
	NonRefField<int, 2> maxNumberOfStudents;
	NonRefField<int, 3> teachingHours;
	RefListField<Course, 4> pre;
	Course(int id, IdObjectFactory &factory) : IdObj(id, factory), name(*this), description(*this), 
	maxNumberOfStudents(*this), teachingHours(*this),pre(*this){}
	
};

#endif
