#include <iostream>
#include "SecretaryRegisteredListsState.h"
#include "UILibraryContext.h"
#include "SystemState.h"

using namespace std;

#define DB_FILE_NAME "../CourseBid/db.txt"
#define GENERATED_ID_FILE_NAME "../CourseBid/generatedIds.txt"
#define TERMINAL_ID 7

void main() {
	FileStorage storage(DB_FILE_NAME, GENERATED_ID_FILE_NAME);
	IdObjectFactory factory(storage);
	auto terminal = factory.construct<Terminal>(TERMINAL_ID);
	if (terminal.status.get() == 1) {
		cout << "!!!!!!!!!!!!!!!!!!!! The terminal is locked !!!!!!!!!!!!!!!!!!!!" << endl << endl;
		return;
	}

	auto seasonConfig = factory.construct<SeasonConfig>(SEASON_CONFIG_ID);
	UILibraryContext * context = new UILibraryContext();
	UILibraryState* state = new SecretaryRegisteredListsState(seasonConfig);
	state->context = context;
	context->setState(state);
	context->run();
	delete context;
}
