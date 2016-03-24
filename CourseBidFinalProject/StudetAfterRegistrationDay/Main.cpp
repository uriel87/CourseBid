#include <iostream>
#include "LoginState.h"
#include "Terminal.h"
#include "SystemState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"

using namespace std;

#define TERMINAL_ID 8
#define DB_FILE_NAME "../CourseBid/db.txt"
#define GENERATED_ID_FILE_NAME "../CourseBid/generatedIds.txt"

void main() {
	FileStorage storage(DB_FILE_NAME, GENERATED_ID_FILE_NAME);
	IdObjectFactory factory(storage);

	//create new terminal
	auto terminal = factory.construct<Terminal>(TERMINAL_ID);

	if (terminal.status.get() == 1) {
		cout << "!!!!!!!!!!!!!!!!!!!! The terminal is locked !!!!!!!!!!!!!!!!!!!!" << endl << endl;
		system("pause");
		return;
	}

	auto seasonConfig = factory.construct<SeasonConfig>(SEASON_CONFIG_ID);

	UILibraryContext * context = new UILibraryContext();
	UILibraryState* state = new LoginState(seasonConfig);
	state->context = context;
	context->setState(state);
	context->run();
	delete context;
}
