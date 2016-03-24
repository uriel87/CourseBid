#pragma once

/*  Tomer Luster */

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include "Bidding.h"

class Student : public IdObj {

private:

public:
	NonRefField<string, 0> name;
	RefListField<Course, 1> completedCoursesList;
	RefListField<Bidding, 2 > biddingList;
	RefListField<Course, 3 > acceptableCourses;
	RefListField<Course, 4> registeredCoursesList;

	Student(int id, IdObjectFactory &factory) : IdObj(id, factory), name(*this), completedCoursesList(*this), biddingList(*this), registeredCoursesList(*this), acceptableCourses(*this){}


};

#endif

