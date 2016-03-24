#include "FileStorage.h"


void readFromFile(string dbName, map<string, string> & map);
void writeToFile(string key, string value, string dbFileName);

// Set the db file name and uniqe id's file name , read from db file and insert it to map
FileStorage::FileStorage(string dbName,string generatedIdFileName){
	this->dbFileName = dbName;
	this->generatedIdFileName = generatedIdFileName;
	readFromFile(this->dbFileName, this->map);
}

// Insert the new value for the specific id and write it to the file
void FileStorage::set(string id, string value) {
	this->map[id] = value;
	writeToFile(id, value,this->dbFileName);
}

// Open the generated id file and return the id and write a new uniqe one
int FileStorage::generateUniqeId(){

	int id;
	fstream file;
	file.open(this->generatedIdFileName, fstream::in);
	file >> id;
	file.close();
	file.open(this->generatedIdFileName, fstream::out | fstream::trunc);
	file << id + 1;
	file.close();
	return id;
}


// Read from the db file and insert it to map 
void readFromFile(string dbName , map<string, string>  & map){
	fstream file;
	string line;
	string value;
	string key;
	file.open(dbName, fstream::in);
	if (file.is_open()){
		while (getline(file, line)){
			size_t  index = line.find_first_of(",");
			key = line.substr(0, index);
			value = line.substr(index+1);
			map[key] = value;
		}
	}
	file.close();
}

// Write a pair key and vlaue to db file and insert it to the map
void writeToFile(string key, string value,string dbFileName){

	fstream file;
	file.open(dbFileName, fstream::out | fstream::app);
	if (file.is_open()){
		file << key << "," << value << "\n";
	}
	else {
		cout << "File not open \n\n";
	}

	file.close();
}








