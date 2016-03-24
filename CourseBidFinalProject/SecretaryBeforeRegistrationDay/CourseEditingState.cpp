#include "CourseEditingState.h"

void nodeValidation(int input, CrossRefMap<ListDigraph, ListDigraph::Node, int> & names, ListDigraph::Node & node, ListDigraph & g);
bool checkCircle(SeasonConfig & seasonConfig);

CourseEditingState::CourseEditingState(Course & course, SeasonConfig & seasonConfig) : course(course), seasonConfig(seasonConfig){}


// check if course is valid and show it in the screen
int displayAllAvailableCourses(SeasonConfig & seasonConfig, Course & course) {
	system("cls");
	bool print;
	int count = 0;
	cout << "List of courses : \n\n";
	for (int i = 0; i < seasonConfig.courses.count(); i++) {
		print = true;
		for (int j = 0; j < course.pre.count(); j++) {
			if (seasonConfig.courses.get(i).getId() == course.pre.get(j).getId()) {
				print = false;
			}

		}
		if (print && seasonConfig.courses.get(i).getId() != course.getId()) {
			count++;
			cout << i << ": " << seasonConfig.courses.get(i).name.get() << endl;
		}

	}
	cout << endl << endl << endl;
	return count;
}

// get a value and validate it 
int insertValue() {
	int num;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  try again \n";
		cin >> num;
	}
	return num;
}

// get an field index and edit the new value from the user
void CourseEditingState::edit(int index) {
	string new_svalue;
	int choise = 0;
	bool circle = false;;
	cout << "You have choosen to edit the field: \n";
	switch (index) {
	case 0:
		cout << "Name " << this->course.name.get() << endl << endl;
		cout << "Please enter new value \n\n";
		cin.ignore();
		getline(cin, new_svalue);
		course.name.set(new_svalue);
		break;
	case 1:
		cout << "Description " << this->course.description.get() << endl << endl;
		cout << "Please enter new value \n\n";
		cin.ignore();
		getline(cin, new_svalue);
		course.description.set(new_svalue);
		break;
	case 2:
		cout << "Max Number of students " << this->course.maxNumberOfStudents.get() << endl << endl;
		cout << "Please enter new value \n\n";
		course.maxNumberOfStudents.set(insertValue());
		break;
	case 3:
		cout << "Teaching Hours " << this->course.teachingHours.get() << endl << endl;
		cout << "Please enter new value \n\n";
		course.teachingHours.set(insertValue());
		break;
	case 4:
		system("cls");
		while (choise != 3) {
			cout << getCaption(4) << " : " << getValue(4) << endl << endl;
			cout << "1.adding pre course\n2.remove\n3.exit\n\n";
			choise = insertValue();
			switch (choise) {
			case 1:
				if (displayAllAvailableCourses(seasonConfig, course) != 0) {
					cout << "enter course index: ";
					course.pre.add(seasonConfig.courses.get(insertValue()));
					circle = checkCircle(this->seasonConfig);
					if (circle == true) {
						cout << "Cannot add course because circle was found \n\n";
						course.pre.remove(course.pre.count() - 1);	
					}
				}
				else {
					cout << "No available courses to add" << endl << endl;
				}
				_sleep(3000);
				break;
			case 2:
				if (course.pre.count() != 0) {
					cout << "enter course index: ";
					course.pre.remove(insertValue());
				}
				else {
					cout << "No pre courses to remove" << endl << endl;
					_sleep(3000);
				}
				break;
			case 3:
				choise = 3;
			default:
				cout << "Wrong key \n";
				break;
			}
		}
		break;
	}
}


//check for circle for each course with his pre courses
bool checkCircle(SeasonConfig  & seasonConfig) {

	ListDigraph g;
	CrossRefMap<ListDigraph, ListDigraph::Node, int> ids(g);
	ListDigraph::Node u, v;
	Bfs<ListDigraph> bfs(g);

	for (int i = 0; i < seasonConfig.courses.count(); i++){
		nodeValidation(seasonConfig.courses.get(i).getId(), ids, u, g);
		for (int j = 0; j < seasonConfig.courses.get(i).pre.count(); j++)
		{
			nodeValidation(seasonConfig.courses.get(i).pre.get(j).getId(), ids, v, g);
			bfs.run(v);

			if (bfs.reached(u)){ // If there is a path to u 
			
				return true; // circle was found we can exit the progeam;
			}
			g.addArc(u, v); // Else  we make a connection between u and v 
		}
	}
	return false;
}


// return the number of fields of course object 
int CourseEditingState::getFieldCount() {
	return NumberOfCourseFields;
}

// return the caption of specific field by index
string CourseEditingState::getCaption(int index){

	switch (index) {
	case 0:
		return "name";
		break;
	case 1:
		return "description";
		break;
	case 2:
		return "max number of students";
		break;
	case 3:
		return "teaching hours";
		break;
	case 4:
		return "pre courses";
		break;
	default:
		return "ERROR";
		break;
	}

}

// return the value of specific field by index
string CourseEditingState::getValue(int index) {
	int number_of_pre_courses = 0;
	string pre_courses = "";
	ostringstream lines;

	switch (index) {
	case 0:
		return this->course.name.get();
		break;
	case 1:
		return this->course.description.get();
		break;
	case 2:
		return to_string(this->course.maxNumberOfStudents.get());
		break;
	case 3:
		return to_string(this->course.teachingHours.get());
		break;
	case 4:
		number_of_pre_courses = this->course.pre.count();

		if (number_of_pre_courses > 0) {
			for (int i = 0; i < number_of_pre_courses; i++) {
				lines << endl << "   " << i << "." << this->course.pre.get(i).name.get();
			}
			pre_courses = lines.str();
		}
		else {
			pre_courses = "No pre courses for this course!! \n\n ";
		}
		return pre_courses;
		break;
	default:
		return "ERROR";
		break;
	}
}

// exit the current screen and move the another one 
void CourseEditingState::exitt() {

	UILibraryState * state = new CourseListEditionState(this->seasonConfig);
	state->context = this->context;
	context->setState(state);
}


/* The function purpose is to check if the node is exist, if not it create it and add it to the map*/
void nodeValidation(int input, CrossRefMap<ListDigraph, ListDigraph::Node, int> & ids, ListDigraph::Node & node, ListDigraph & g){
	node = ids(input);
	if (node == INVALID) {  // Check if node is inavlid 
		node = g.addNode();
		ids.set(node, input); // make a connection between the node and the string
	}
}
