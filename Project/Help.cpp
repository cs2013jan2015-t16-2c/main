#include "Help.h"
#include "MagicString.h"

//@Cai Yu A0093586N
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
	cout << MagicString::HELP_MAIN_L11 << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::addHelpPage() {
	cout << MagicString::INSTRUCTION_ADD << endl;
	cout << MagicString::INSTRUCTION_ADD_FLOATING << endl;
	cout << MagicString::INSTRUCTION_ADD_DEADLINE << endl;
	cout << MagicString::INSTRUCTION_ADD_TIMED << endl;
	cout << MagicString::INSTRUCTION_ADD_TAG << endl;
	cout << MagicString::INSTRUCTION_ADD_VENUE << endl;
	cout << MagicString::INSTRUCTION_ADD_BOTH_1 << endl;
	cout << MagicString::INSTRUCTION_ADD_BOTH_2 << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::displayHelpPage() {
	cout << MagicString::INSTRUCTION_DISPLAY << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_TODAY << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_FLOATING << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_DEADLINE << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_TIMED << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_DONE << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_ALL << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::setPriorityHelpPage() {
	cout << MagicString::INSTRUCTION_COMMON << endl;
	cout << MagicString::INSTRUCTION_SET_PRIORITY << endl;
	cout << MagicString::INSTRUCTION_SET_PRIORITY_REMINDER << endl;
	cout << MagicString::INSTRUCTION_SET_PRIORITY_EXP1 << endl;
	cout << MagicString::INSTRUCTION_SET_PRIORITY_EXP2 << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
}

void Help::deleteHelpPage() {
	cout << MagicString::INSTRUCTION_COMMON << endl;
	cout << MagicString::INSTRUCTION_DELETE << endl;
	cout << MagicString::INSTRUCTION_DELETE_EXP << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::updateHelpPage() {
	cout << MagicString::INSTRUCTION_COMMON << endl;
	cout << MagicString::INSTRUCTION_UPDATE << endl;
	cout << MagicString::INSTRUCTION_UPDATE_EXP << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::undoRedoHelpPage() {
	cout << MagicString::INSTRUCTION_UNDO << endl;
	cout << MagicString::INSTRUCTION_REDO << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::archiveHelpPage() {
	cout << MagicString::INSTRUCTION_ARCHIVE << endl;
	cout << MagicString::INSTRUCTION_ARCHIVE_EXP1 << endl;
	cout << MagicString::INSTRUCTION_ARCHIVE_EXP2 << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::clearHelpPage() {
	cout << MagicString::INSTRUCTION_CLEAR_EXP1 << endl;
	cout << MagicString::INSTRUCTION_CLEAR_EXP2 << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::exitHelpPage () {
	cout << MagicString::INSTRUCTION_EXIT << endl;
	cout << endl;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

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
		else if (Help::isInMainHelpPage && userInput == MagicString::SET_PRIORITY_HELP_PAGE_INDEX) {
			Help::setPriorityHelpPage();
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
		else if (Help::isInMainHelpPage && userInput == MagicString::UNDO_REDO_HELP_PAGE_INDEX) {
			Help::undoRedoHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::ARCHIVE_HELP_PAGE_INDEX) {
			Help::archiveHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == MagicString::CLEAR_HELP_PAGE_INDEX) {
			Help::clearHelpPage();
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
			cout << endl;
			Help::mainHelpPage();
			Help::isInMainHelpPage = true;
		}

	}
	return "";
}