#pragma once

/*  Tomer Luster */

#ifndef FILE_SEASONCONFIG_H
#define FILE_SEASONCONFIG_H

#include "Course.h"
#include "Student.h"

class SeasonConfig : public IdObj
{
public:

	RefListField<Course, 0> courses;
	RefListField<Student, 1> students;
	NonRefField <string, 2> pointAllocFormula;
	SeasonConfig(int id, IdObjectFactory &factory) : IdObj(id, factory), courses(*this), students(*this), pointAllocFormula(*this) {}
};

#endif
