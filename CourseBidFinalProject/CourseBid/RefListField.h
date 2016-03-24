#pragma once

/*  Tomer Luster */

#ifndef REF_LIST_FIELD_H
#define REF_LIST_FIELD_H

#include <vector>
#include <sstream>
#include "IdObj.h"
#include "FileStorage.h"

template<class T,int i>
class RefListField{

private:

	IdObj obj;

public:

	RefListField(IdObj obj) : obj(obj){};

	// Count the number of objects in the list by checking the numbers of commas in the string
	int count(){
		try {
			string fieldId = to_string(this->obj.getId()) + '.' + to_string(i); // uniqe id for the field
			string value = this->obj.getFactory().getStorage().get(fieldId);
			istringstream ss(value);
			string token;
			int count = 0;
			while (getline(ss, token, ',')) {
				count++;
			}
			return count;
		} catch (exception e) {
			return 0;
		}
	}

	// Add object to the list by assembling the key for that object and add it to storage
	void add(T obj){
		string fieldId = to_string(this->obj.getId()) + '.' + to_string(i); // uniqe id for the field
		string existingValue;
		string value;

		try {
			existingValue = this->obj.getFactory().getStorage().get(fieldId);
			if (existingValue.empty()) {
				value = to_string(obj.getId());
			}
			else {
				value = existingValue + "," + to_string(obj.getId());
			}
			this->obj.getFactory().getStorage().set(fieldId, value);
		} catch  (exception e){
			value = to_string(obj.getId());
			this->obj.getFactory().getStorage().set(fieldId, value);
		}
		
	};

	//Remove object from the list by specific index
	void remove(int index){
		string fieldId = to_string(this->obj.getId()) + '.' + to_string(i); // uniqe id for the field
		string value = this->obj.getFactory().getStorage().get(fieldId);
		istringstream ss(value);
		string token;
		int count =0;
		string newValue;

		while (getline(ss, token, ',')) {
			if (index != count) {
				newValue += token + ",";
			}
			count++;
		}
		newValue = newValue.substr(0,newValue.length() - 1);
		this->obj.getFactory().getStorage().set(fieldId, newValue);

	}

	// get an object by specific index , throw an exception if not found
	T get(int index){
		string fieldId = to_string(this->obj.getId()) + '.' + to_string(i); // uniqe id for the field
		string value = this->obj.getFactory().getStorage().get(fieldId);
		istringstream ss(value);
		string token;
		int count = 0;

		while (getline(ss, token, ',')) {
			if (index == count) {
				return this->obj.getFactory().construct<T>(stoi(token));
			}
			count++;
		}

		throw exception("index is not exist in the list");
	}
};

#endif