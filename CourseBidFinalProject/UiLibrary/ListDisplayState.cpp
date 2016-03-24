#include "ListDisplayState.h"



void ListDisplayState::display() {

	system("cls");

	cout << "The list: " << endl << endl;
	for (int i = 0; i < count(); i++) {
		cout << i << ". " << get(i) << endl;
	}
	cout << endl << endl << endl;

	cout << "Enter your operation: \n\n" << endl;
	cout << "1. select\n2. add\n3. delete\n4. exit\n\n";
}

int validIndex(){
	int index;
	cout << "enter index: ";
	cin >> index;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  try again \n";
		cin >> index;
	}
	return index;
}

void ListDisplayState::handleInput(int input) {
	try {
		switch (input){
		case 1 :
			select(validIndex());
			break;
		case 2:
			add();
			break;
		case 3:
			if (count() != 0) {
				deletee(validIndex());
			}
			else {
				cout << "no records to delete" << endl;
			}
			break;
		case 4:
			exitt();
			break;
		default:
			break;
		}
	}catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
}