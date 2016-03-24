#pragma once

/*  Tomer Luster */

#ifndef ID_OBJ_FACTORY_H
#define ID_OBJ_FACTORY_H

#include "IStorage.h"

using namespace std;



class IdObjectFactory{

private:
	IStorage & storage;

public:

	IdObjectFactory(IStorage & storage) : storage(storage){};
	
	// build an object by specific id 
	template<class T> T construct(int id) {
		T t(id, *this);
		return t;
	}

	// Allocate uniqe id for new object and build it 
	template<class T> T allocate() {
		int uniqeId = dynamic_cast<FileStorage&>(storage).generateUniqeId();
		T t = construct<T>(uniqeId);
		return t;
	}

	// Get the stroage
	IStorage & getStorage() { return storage; }
};

#endif