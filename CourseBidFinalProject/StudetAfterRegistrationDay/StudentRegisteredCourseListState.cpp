#include "StudentRegisteredCourseListState.h"

void displayRegisteredCoursesList(Student & student, SeasonConfig & seasonConfig) {
	int count = 0;
	int min_points = 0;
	system("cls");
	cout << "Registered course list" << endl << endl;

	for (int i = 0; i < student.registeredCoursesList.count(); i++) {
		for (int j = 0; j < seasonConfig.students.count(); j++) {
			for (int k = 0; k < seasonConfig.students.get(j).biddingList.count(); k++) {
				if (to_string(student.registeredCoursesList.get(i).getId()).compare(seasonConfig.students.get(j).biddingList.get(k).courseId.get()) == 0) {
					count++;
					if (count == 1) {
						min_points = seasonConfig.students.get(j).biddingList.get(k).pointsAllocated.get();
					}
					else {
						if (min_points > seasonConfig.students.get(j).biddingList.get(k).pointsAllocated.get()) {
							min_points = seasonConfig.students.get(j).biddingList.get(k).pointsAllocated.get();
						}
					}
				}

			}
		}
		cout << "* " << student.registeredCoursesList.get(i).name.get() << " with minimal points: " << min_points << endl;
		count = 0;
	}

}

void StudentRegisteredCourseListState::handleInput(int input) {
	char any_key;
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			displayRegisteredCoursesList(student,seasonConfig);
			cout << "Press any key and press enter to continue" << endl;
			cin >> any_key;
			break;
		case 2:
			state = new StudentListsHomeScreenState(seasonConfig,student);
			break;
		default:
			break;
		}
		if (state != NULL) {
			state->context = context;
			context->setState(state);
		}
	}
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}

}


void StudentRegisteredCourseListState::display() {
	system("cls");

	cout << "1. display list\n2. exit\n" << endl;
}


