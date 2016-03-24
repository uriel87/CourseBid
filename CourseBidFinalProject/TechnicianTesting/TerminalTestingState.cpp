#include "TerminalTestingState.h"

// ask an input from the technician and validate it
int insertOperation() {
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

// run calculate scheduling testing and ask the technician for the result, if result is wrong lock the terminal
void runCalculateSchedulingTest(Terminal & terminal) {
	int opertaion;
	FileStorage storage(INPUT_TEST_FILE, GENERATED_IDS);
	IdObjectFactory factory(storage);
	auto seasonConfigTesting = factory.construct<SeasonConfig>(SEASON_CONFIG_ID);
	CalculateSchedulingOperation calculateScheduling(seasonConfigTesting);

	system("cls");
	cout << "Please compare between the output file and the test db file and choose accordingly: " << endl << endl;
	cout << "1.invalid result -lock the terminal" << endl << endl;

	cout << "For valid result please insert any other number " << endl;

	opertaion = insertOperation();
	switch (opertaion){

	case 1:
		terminal.status.set(1); // Locked terminal due failure of the test
		break;
	default:
		break;
	}


}



// get an input and handle it accourdingly
void TerminalTestingState::handleInput(int input) {

	try {
		UILibraryState* state = NULL;
		switch (input) {
		case 1:
			runCalculateSchedulingTest(terminal);
			break;
		case 2:
			state = new TechnicianHomeScreenState(seasonConfig,terminal);
			break;
		default:
			break;
		}
		if (state != NULL) {
			state->context = context;
			context->setState(state);
		}
	}
	catch (exception& e) {
		cout << "Standard exception: " << e.what() << endl;
	}

}

// display the opertation on the screen
void TerminalTestingState::display() {
	system("cls");
	cout << "wellcome technician" << endl;
	cout << "please choose from the foolowing options: " << endl << endl;
	cout << "1. run calculate scheduling test \n2. exit" << endl;

}