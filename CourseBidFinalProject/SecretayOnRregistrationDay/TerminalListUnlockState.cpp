#include "TerminalListUnlockState.h"

// ask user for input and validate it
int insertInput() {
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

// unlock terminal from locked mode to open mode
void unlockTerminal(Terminal & terminal) {
	if (terminal.status.get() == LOCKED_TERMINAL) {
		terminal.status.set(UNLOCK_TERMINAL);
	}
	else {
		cout << "This terminal is already open" << endl << endl;
	}
}

// get an input and handle it accourdingly
void TerminalListUnlockState::handleInput(int input) {

	try{
		UILibraryState* state = NULL;
		switch (input){
		case 1:
			try {
				cout << "Please insert terminal index to unlock it: ";
				unlockTerminal(this->systemState.terminals.get(insertInput()));
			}
			catch (exception e) {
				cout << e.what();
			}
			break;
		case 2:
			exit(EXIT_SUCCESS);
			break;
		default:

			break;
		}

	}
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}

}

// receive status mode and return the status name 
string terminalStatus(int status) {
	switch (status) {
	case 0:
		return OPEN;
		break;
	case 1:
		return LOCKED;
		break;
	default:
		return ERROR;
		break;
	}
}

// display all the terminals on the screen and their mode
void TerminalListUnlockState::display() {
	system("cls");
	string terminal_status;
	int count = 0;
	cout << "Wellcome to secretary screen\n\n";

	for (int i = 0; i < this->systemState.terminals.count(); i++) {
		cout << i << "." << this->systemState.terminals.get(i).name.get() << " - " << terminalStatus(this->systemState.terminals.get(i).status.get()) << endl;
	}

	cout << endl << endl;

	cout << "Enter your operation: \n\n";
	cout << "1. Unlock terminal\n2. exit\n" << endl;
}

