#include "Help.h"
#include "MagicString.h"

void Help::mainHelpPage() {
	cout << MagicString::HELP_MAIN_L1 << endl;
	cout << MagicString::HELP_MAIN_L2 << endl;
	cout << MagicString::HELP_MAIN_L3 << endl;
	cout << MagicString::HELP_MAIN_L4 << endl;
	cout << MagicString::HELP_MAIN_L5 << endl;
	cout << MagicString::HELP_MAIN_L6 << endl;
	cout << MagicString::HELP_MAIN_L7 << endl;
	cout << MagicString::HELP_MAIN_L8 << endl;
	cout << MagicString::HELP_MAIN_L9 << endl;
	cout << MagicString::HELP_MAIN_L10 << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::addHelpPage() {
	cout << MagicString::ADD_INSTRUCTION << endl;
	cout << MagicString::ADD_INSTRUCTION_FLOATING << endl;
	cout << MagicString::ADD_INSTRUCTION_DEADLINE << endl;
	cout << MagicString::ADD_INSTRUCTION_TIMED << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::displayHelpPage() {
	cout << MagicString::DISPLAY_INSTRUCTION << endl;
	cout << MagicString::DISPLAY_INSTRUCTION_ALL << endl;
	cout << MagicString::DISPLAY_INSTRUCTION_FLOATING << endl;
	cout << MagicString::DISPLAY_INSTRUCTION_DEADLINE << endl;
	cout << MagicString::DISPLAY_INSTRUCTION_TIMED << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::deleteHelpPage() {
	cout << MagicString::COMMON_INSTRUCTION << endl;
	cout << MagicString::DELETE_INSTRUCTION << endl;
	cout << MagicString::DELETE_INSTRUCTION_EXP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::updateHelpPage() {
	cout << MagicString::COMMON_INSTRUCTION << endl;
	cout << MagicString::UPDATE_INSTRUCTION << endl;
	cout << MagicString::UPDATE_INSTRUCTION_EXP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::undoHelpPage() {
	cout << MagicString::UNDO_INSTRUCTION << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::redoHelpPage() {
	cout << MagicString::REDO_INSTRUCTION << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::archiveHelpPage() {
	cout << MagicString::ARCHIVE_INSTRUCTION << endl;
	cout << MagicString::ARCHIVE_INSTRUCTION_EXP1 << endl;
	cout << MagicString::ARCHIVE_INSTRUCTION_EXP2 << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::exitHelpPage () {
	cout << MagicString::EXIT_INSTRUCTION << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

//const string Help::ADD_HELP_PAGE_INDEX = "1";
//const string Help::DISPLAY_HELP_PAGE_INDEX = "2";
//const string Help::DELETE_HELP_PAGE_INDEX = "3";
//const string Help::UPDATE_HELP_PAGE_INDEX = "4";
//const string Help::UNDO_HELP_PAGE_INDEX = "5";
//const string Help::REDO_HELP_PAGE_INDEX = "6";
//const string Help::ARCHIVE_HELP_PAGE_INDEX = "7";
//const string Help::EXIT_HELP_PAGE_INDEX = "8";
//const string Help::REUTRN_TO_MAIN_HELP_PAGE = "0";
//const string Help::EXIT_HELP = "00";

//const string Help::MESSAGE_INVALID_INDEX = "Error: invalid input!";

//const string Help::MESSAGE_NEXT_ACTION = "You may select the following actions";
//const string Help::MESSAGE_RETURN_TO_MAIN = "0:  return to the main help page";
//const string Help::MESSAGE_EXIT_HELP =      "00: get back to KeepTrack!";
//const string Help::MESSAGE_COMMAND = "Command: ";

bool Help::isInMainHelpPage = true;

void Help::showHelp(string helpText) {
	cout << helpText;
}

string Help::executeHelpCommand() {
	Help::mainHelpPage();
	string userInput;

	while (getline(cin, userInput)) {
		if (Help::isInMainHelpPage && userInput == MagicString::ADD_HELP_PAGE_INDEX) {
			Help::addHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::DISPLAY_HELP_PAGE_INDEX) {
			Help::displayHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::DELETE_HELP_PAGE_INDEX) {
			Help::deleteHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::UPDATE_HELP_PAGE_INDEX) {
			Help::updateHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::UNDO_HELP_PAGE_INDEX) {
			Help::undoHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::REDO_HELP_PAGE_INDEX) {
			Help::redoHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::ARCHIVE_HELP_PAGE_INDEX) {
			Help::archiveHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::EXIT_HELP_PAGE_INDEX) {
			Help::exitHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (!Help::isInMainHelpPage && userInput == MagicString::REUTRN_TO_MAIN_HELP_PAGE) {
			Help::mainHelpPage();
			Help::isInMainHelpPage = true;
		}
		else if (userInput == MagicString::EXIT_HELP) {
			Help::isInMainHelpPage = true;
			return "";
		}
		else {
			Help::showHelp(MagicString::MESSAGE_INVALID_INDEX);
			cout << endl;
			cout << MagicString::DIVIDER;
			Help::mainHelpPage();
			cout << endl;
			cout << MagicString::DIVIDER;
			cout << MagicString::HELP_INDEX;
		}

	}
	return "";
}