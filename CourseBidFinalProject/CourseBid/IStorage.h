#pragma once

/*  Tomer Luster */

#ifndef ISTORAGE_H
#define ISTORAGE_H

#include <iostream>
#include <string>
using namespace std;

class IStorage{

public:
	virtual string get(string id) = 0;
	virtual void set(string id, string value) = 0;

};

#endif