#include <iostream>
#include "Terminal.h"
#include "SystemState.h"
#include "UILibraryContext.h"
#include "SeasonConfig.h"
#include "TechnicianHomeScreenState.h"

using namespace std;

#define TERMINAL_ID 5
#define DB_FILE_NAME "../CourseBid/db.txt"
#define GENERATED_ID_FILE_NAME "../CourseBid/generatedIds.txt"

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
	UILibraryState* state = new TechnicianHomeScreenState(seasonConfig,terminal);
	state->context = context;
	context->setState(state);
	context->run();
	delete context;
}
