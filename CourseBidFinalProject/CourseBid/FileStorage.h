#pragma once

/*  Tomer Luster */

#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#define SEASON_CONFIG_ID 1
#define SYSTEM_STATE_ID 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <hash_map>
#include <iomanip>     
#include "IdObjectFactory.h"

using namespace std;


class FileStorage: public IStorage {

private:
	map<string, string> map;
	string dbFileName;
	string generatedIdFileName;
	

public:
	FileStorage(string dbName, string generatedIdFileName);

	// get the value from uniqe id
	string get(string id) {
		return this->map.at(id);
	}

	// Set the value for uniqe id 
	void set(string id, string value);
	std::map<string, string> getMap() {
		return this->map;
	}

	// Generate a uniqe id 
	int generateUniqeId();
};

#endif
