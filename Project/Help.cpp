#include "Help.h"

void Help::mainHelpPage() {
	cout << "Please select the function you would like to know" << endl;
	cout << "1.  Add a task" << endl;
	cout << "2.  Display tasks" << endl;
	cout << "3.  Delete a task" << endl;
	cout << "4.  Update a task" << endl;
	cout << "5.  Undo the last action" << endl;
	cout << "6.  Redo the last action" << endl;
	cout << "7.  Archive your task list to another file" << endl;
	cout << "8.  How to exit KeepTrack" << endl;
	cout << "00. Get back to KeepTrack!" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::addHelpPage() {
	cout << "You can add three types of tasks" << endl;
	cout << "Floating task: add do assignment 1" << endl;
	cout << "Deadline:      add finish assignment 1 -by 14:00 13/4" << endl;
	cout << "Timed task:    add do assignment 1 -from 9:00 -to 11:00 12/4" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::displayHelpPage() {
	cout << "You can display your task list in the following ways" << endl;
	cout << "All the tasks:          display all" << endl;
	cout << "All the floating tasks: display floating" << endl;
	cout << "All the deadlines:      display deadline" << endl;
	cout << "All the timed task:     display timed" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::deleteHelpPage() {
	cout << "After displaying tasks," << endl;
	cout << "you can delete a task by its index" << endl;
	cout << "Example: delete 2" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::updateHelpPage() {
	cout << "After displaying tasks," << endl;
	cout << "you can select the task by its index and input the updated task information" << endl;
	cout << "Example: update Update 1 -from 1300 -to 1500 23/12\n" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::undoHelpPage() {
	cout << "You can undo your last action by simply entering 'undo'" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::redoHelpPage() {
	cout << "You can reoo your last action by simply entering 'redo'" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::archiveHelpPage() {
	cout << "You can archive your task list in the following ways" << endl;
	cout << "Archive in the program folder: archive myText.txt" << endl;
	cout << "Archive in another folder:     archive C:/Users/USER/Desktop/myText.txt" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

void Help::exitHelpPage () {
	cout << "You can exit KeepTrack by simply entering 'exit'" << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_NEXT_ACTION << endl;
	cout << Help::MESSAGE_RETURN_TO_MAIN << endl;
	cout << Help::MESSAGE_EXIT_HELP << endl;
	cout << "================================================================================";
	cout << Help::MESSAGE_COMMAND;
	return;
}

const string Help::ADD_HELP_PAGE_INDEX = "1";
const string Help::DISPLAY_HELP_PAGE_INDEX = "2";
const string Help::DELETE_HELP_PAGE_INDEX = "3";
const string Help::UPDATE_HELP_PAGE_INDEX = "4";
const string Help::UNDO_HELP_PAGE_INDEX = "5";
const string Help::REDO_HELP_PAGE_INDEX = "6";
const string Help::ARCHIVE_HELP_PAGE_INDEX = "7";
const string Help::EXIT_HELP_PAGE_INDEX = "8";
const string Help::REUTRN_TO_MAIN_HELP_PAGE = "0";
const string Help::EXIT_HELP = "00";

const string Help::MESSAGE_INVALID_INDEX = "Error: invalid input!";

const string Help::MESSAGE_NEXT_ACTION = "You may select the following actions";
const string Help::MESSAGE_RETURN_TO_MAIN = "0:  return to the main help page";
const string Help::MESSAGE_EXIT_HELP =      "00: get back to KeepTrack!";
const string Help::MESSAGE_COMMAND = "Command: ";

bool Help::isInMainHelpPage = true;

void Help::showHelp(string helpText) {
	cout << helpText;
}

string Help::executeHelpCommand() {
	Help::mainHelpPage();
	string userInput;

	while (getline(cin, userInput)) {
		if (Help::isInMainHelpPage && userInput == Help::ADD_HELP_PAGE_INDEX) {
			Help::addHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::DISPLAY_HELP_PAGE_INDEX) {
			Help::displayHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::DELETE_HELP_PAGE_INDEX) {
			Help::deleteHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::UPDATE_HELP_PAGE_INDEX) {
			Help::updateHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::UNDO_HELP_PAGE_INDEX) {
			Help::undoHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::REDO_HELP_PAGE_INDEX) {
			Help::redoHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::ARCHIVE_HELP_PAGE_INDEX) {
			Help::archiveHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (Help::isInMainHelpPage && userInput == Help::EXIT_HELP_PAGE_INDEX) {
			Help::exitHelpPage();
			Help::isInMainHelpPage = false;
		}
		else if (!Help::isInMainHelpPage && userInput == Help::REUTRN_TO_MAIN_HELP_PAGE) {
			Help::mainHelpPage();
			Help::isInMainHelpPage = true;
		}
		else if (userInput == Help::EXIT_HELP) {
			Help::isInMainHelpPage = true;
			return "";
		}
		else {
			Help::showHelp(Help::MESSAGE_INVALID_INDEX);
			cout << endl;
			cout << "================================================================================";
			Help::mainHelpPage();
			cout << endl;
			cout << "================================================================================";
			cout << "Help Index: ";
		}

	}
	return "";
}