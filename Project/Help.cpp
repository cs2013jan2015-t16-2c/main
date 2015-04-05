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
	cout << MagicString::INSTRUCTION_ADD << endl;
	cout << MagicString::INSTRUCTION_ADD_FLOATING << endl;
	cout << MagicString::INSTRUCTION_ADD_DEADLINE << endl;
	cout << MagicString::INSTRUCTION_ADD_TIMED << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::displayHelpPage() {
	cout << MagicString::INSTRUCTION_DISPLAY << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_ALL << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_FLOATING << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_DEADLINE << endl;
	cout << MagicString::INSTRUCTION_DISPLAY_TIMED << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::deleteHelpPage() {
	cout << MagicString::INSTRUCTION_COMMON << endl;
	cout << MagicString::INSTRUCTION_DELETE << endl;
	cout << MagicString::INSTRUCTION_DELETE_EXP << endl;
	cout << MagicString::DIVIDER;
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
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::undoHelpPage() {
	cout << MagicString::INSTRUCTION_UNDO << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::redoHelpPage() {
	cout << MagicString::INSTRUCTION_REDO << endl;
	cout << MagicString::DIVIDER;
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
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_NEXT_ACTION << endl;
	cout << MagicString::MESSAGE_RETURN_TO_MAIN << endl;
	cout << MagicString::MESSAGE_EXIT_HELP << endl;
	cout << MagicString::DIVIDER;
	cout << MagicString::MESSAGE_COMMAND;
	return;
}

void Help::exitHelpPage () {
	cout << MagicString::INSTRUCTION_EXIT << endl;
	cout << MagicString::DIVIDER;
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