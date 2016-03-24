#include "StudentUnregisteredCourseListState.h"

void displayUnregisteredCoursesList(Student & student,SeasonConfig & seasonConfig) {
	bool exist = false;
	int count = 0;
	int min_points =0;
	system("cls");
	cout << "Unregistered course list" << endl << endl;

	for (int i = 0; i < student.biddingList.count(); i++) {
		for (int j = 0; j < student.registeredCoursesList.count(); j++) {
			if (student.biddingList.get(i).courseId.get().compare(to_string(student.registeredCoursesList.get(j).getId())) == 0) {
				exist = true;
				break;
			}

		}

		if (!exist) {

			for (int g = 0; g < seasonConfig.students.count(); g++) {

				for (int k = 0; k < seasonConfig.students.get(g).biddingList.count(); k++) {
					if (seasonConfig.students.get(g).biddingList.get(k).courseId.get().compare(student.biddingList.get(i).courseId.get()) == 0) {
						count++;
						if (count == 1) {
							min_points = seasonConfig.students.get(g).biddingList.get(k).pointsAllocated.get();
						}
						else {
							if (min_points > seasonConfig.students.get(g).biddingList.get(k).pointsAllocated.get()) {
								min_points = seasonConfig.students.get(g).biddingList.get(k).pointsAllocated.get();
							}
						}
					}
				}

			}

			for (int l = 0; l < seasonConfig.courses.count(); l++) {
				if (to_string(seasonConfig.courses.get(l).getId()).compare(student.biddingList.get(i).courseId.get()) == 0)
					cout << "* " << seasonConfig.courses.get(l).name.get() << " with minimal points: " << min_points << endl;
			}
		}

		count = 0;
		exist = false;
	}

}

void StudentUnregisteredCourseListState::handleInput(int input) {
	char any_key;
	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			displayUnregisteredCoursesList(student,seasonConfig);
			cout << "Press any key and press enter to continue" << endl;
			cin >> any_key;
			break;
		case 2:
			state = new StudentListsHomeScreenState(seasonConfig, student);
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


void StudentUnregisteredCourseListState::display() {
	system("cls");

	cout << "1. display list\n2. exit\n" << endl;
}


