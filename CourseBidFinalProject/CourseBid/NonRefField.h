#pragma once

/*  Tomer Luster */

#ifndef NON_REF_FIELD_H
#define NON_REF_FIELD_H

#include "IdObj.h"

template<class T, int i>
class NonRefField{

private:
	IdObj obj;

public:

	NonRefField(IdObj obj) : obj(obj){};

	// Get the field value
	T get() {
		int id = obj.getId();
		string fieldId = to_string(obj.getId()) + '.' + to_string(i); // uniqe id for the field
		return convertForReturn<T>(obj.getFactory().getStorage().get(fieldId));

	};
	
	// Set the field value
	void set(T value) {
		string fieldId = to_string(obj.getId()) + '.' + to_string(i); // uniqe id for the field
		string stringValue = convert<T>(value);
		if (stringValue != "Not supported type") {
			cout << "stringValue " << stringValue << "\n";
			obj.getFactory().getStorage().set(fieldId, stringValue);
		}
		else {
			cout << stringValue << "\n";
		}
	};

	// explicit_specialization , 
	template<class T> string convert(T t) {
		return "Not supported type";
	};

	// Explicit specialization of convert with 'int' with the
	// template argument explicitly specified:
	template<> string convert<int>(int value) {
		return  to_string(value);

	}

	// Explicit specialization of convert with 'string' with the
	// template argument explicitly specified:
	template<> string convert<string>(string value) {
		return  value;

	}

	// explicit_specialization
	template<class T> T convertForReturn(string value) {
		return value;
	};

	// Explicit specialization of convert with 'int' with the
	// template argument explicitly specified:
	template<> int convertForReturn<int>(string value) {
		return  stoi(value);
	}

};

#endif