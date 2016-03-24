#include "EntryDisplayState.h"

void EntryDisplayState::display(){
	system("cls");
	for (int i = 0; i < getFieldCount(); i++) {
		cout << i << ". " << getCaption(i) << " : " << getValue(i) << endl << endl;
	}

	cout << endl << endl;
	cout << "Enter your operation: " << endl;
	cout << "1. edit\n2. exit\n";

}

void EntryDisplayState::handleInput(int input){
	int index=-1;
	UILibraryState * state = NULL;
	try {
			switch (input){
			case 1:
				cout << "please enter field index: ";
				cin >> index;
				if (!cin) {
					// user didn't input a number
					cin.clear(); // reset failbit
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
					// next, request user reinput
				}
				edit(index);
				break;
			case 2:
				exitt();
				break;
			default:
				break;
			}
	}catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}
}

