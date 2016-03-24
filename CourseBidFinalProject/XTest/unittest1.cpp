#include "stdafx.h"
#include <iostream>
#include "CppUnitTest.h"
#include "FileStorage.h"
#include "Student.h"
#include "SeasonConfig.h"
#include <cstdlib> 
#include <string>
#include "Lexer.h"
#include "Parser.h"
using namespace std;

/* Roni Chabra*/

#define SeasonConfigId 1
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define DB_FILE_NAME "../XTest/db.txt"
#define GENERATED_ID_FILE_NAME "../XTest/generatedIds.txt"
namespace Xtest
{

	TEST_CLASS(UnitTest1)
	{
	public:

		//Black-Box
		TEST_METHOD(checkExpression)
		{
			string s1 = "2*@+100";
			Lexer * L1 = new Lexer(s1);
			double result = L1->getExpression(5)->evaluate();
			Assert::AreEqual(110, result, 0.01);
		}

		//White-Box
		TEST_METHOD(maxNumberOfStudents)
		{
			FileStorage storage(DB_FILE_NAME, GENERATED_ID_FILE_NAME);
			IdObjectFactory factory(storage);
			auto seasonConfig = factory.construct<SeasonConfig>(SeasonConfigId);
			auto y = factory.allocate<Course>();
			int num = 30;
			y.maxNumberOfStudents.set(num);
			seasonConfig.courses.add(y);
			//check num of students set in course
			Assert::AreEqual(30, y.maxNumberOfStudents.get(), 0.01);

		}
		//White-Box
		TEST_METHOD(coursesCountForStudent)
		{
			FileStorage storage(DB_FILE_NAME, GENERATED_ID_FILE_NAME);
			IdObjectFactory factory(storage);
			auto seasonConfig = factory.construct<SeasonConfig>(SeasonConfigId);
			auto x = factory.allocate<Student>();
			seasonConfig.students.add(x);
			x.name.set("Roni");
			auto y = factory.allocate<Course>();
			seasonConfig.courses.add(y);
			y.name.set("algebra");
			auto d = factory.allocate<Course>();
			seasonConfig.courses.add(d);
			d.name.set("Math");
			x.completedCoursesList.add(y);
			x.completedCoursesList.add(d);

			//add 2 courses to student list. 
			Assert::AreEqual(2, x.completedCoursesList.count(), 0.01);
		}

	};
}
