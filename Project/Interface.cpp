// Resource File
// BasicUI.cpp

#include "BasicUI.h"

string Interface::MESSAGE_WELCOME = "Welcome to KeepTrack";
const string Interface::MESSAGE_ADDED = "Added to %s: \"%s\"";
const string Interface::MESSAGE_DELETED = "Deleted from %s: \"%s\"";
const string Interface::MESSAGE_GOODBYE = "Goodbye!";

const string Interface::ERROR_INVALID_COMMAND = "Error: invalid command!";

string Interface::displayWelcome() {
	string currentDayTime;
	time_t now = time(0);
	struct tm tstruct;
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", &tstruct);

	return MESSAGE_WELCOME + "\n" + buffer;
}

void Interface::showToUser(string text) {
	cout << text << endl;
}

string Interface::getUserCommand() {
	string userCommand;

	cout << "command: ";
	getline(cin, userCommand);

	return userCommand;
}

string Interface::executeUserCommand(string fileName, string userCommand) {
	string commandTypeString;
	string taskString;
	string taskMessageString;

	commandTypeString = getFirstWord(userCommand);
	taskString = removeFirstWord(userCommand);

	transform(commandTypeString.begin(), commandTypeString.end(), commandTypeString.begin(), ::tolower);
	
	COMMAND_TYPE commandType;
	commandType = determineCommandType(commandTypeString, taskString);

	taskMessageString = getTaskMessage(taskString);

	switch (commandType) {
		// add more!!
	case HELP:
		help();
	case ADD_FLOATING:
	case ADD_STATIC:
	case ADD_DEADLINE:
	case SEARCH:
	case UPDATE:
	case DELETE_TASK:
	case DISPLAY_ALL:
	case DISPLAY_SATIC:
	case DISPLAY_DEADLINE:
	case DISPLAY_FLOATING:
	case DISPLAY_UNFINISHED:
	case DISPLAY_FINISHED:
	case DISPLAY_TODAY:
	case UNDO:
	case REDO:
	case EXIT:
		// copy to final file
		cout << MESSAGE_GOODBYE << endl;;
		exit(0);
	default:
		return ERROR_INVALID_COMMAND
	}
}

Task::TASK_TYPE Interface::determineTaskType(string taskString) {
	size_t foundFrom = taskString.find("-from");
	size_t foundTo = taskString.find("-to");
	size_t foundBy = taskString.find("-by");

	if ((foundFrom != string::npos) && (foundTo != string::npos)) {
		return TASK_TYPE::STATIC_TASK;
	}
	else if (foundBy != string::npos) {
		return TASK_TYPE::DEADLINE;
	}
	else {
		return TASK_TYPE::FLOATING;
	}
}

Interface::COMMAND_TYPE Interface::determineCommandType(string commandTypeString, string taskString) {
	if (commandTypeString == "help") {
		return COMMAND_TYPE::HELP;
	}
	else if (commandTypeString == "add") {
		if (determineTaskType(taskString) == TASK_TYPE::STATIC_TASK) {
			return COMMAND_TYPE::ADD_STATIC;
		}
		else if (determineTaskType(taskString) == TASK_TYPE::DEADLINE) {
			return COMMAND_TYPE::ADD_DEADLINE;
		}
		else {
			return COMMAND_TYPE::ADD_FLOATING;
		}
	}
	else if (commandTypeString == "update") {
		return COMMAND_TYPE::UPDATE;
	}
	else if (commandTypeString == "delete") {
		return COMMAND_TYPE::DELETE_TASK;
	}
	else if (commandTypeString == "search") {
		return COMMAND_TYPE::SEARCH;
	}
	else if (commandTypeString == "display") {
		return COMMAND_TYPE::DISPLAY_ALL;
	}
	else if (commandTypeString == "done") { // done??
		return COMMAND_TYPE::MARK_DONE;
	}
	else if (commandTypeString == "undo") {
		return COMMAND_TYPE::UNDO;
	}
	else if (commandTypeString == "redo") {
		return COMMAND_TYPE::REDO;
	}
	else {
		return COMMAND_TYPE::EXIT;
	}
}

string Interface::getFirstWord(string userCommand) {
	return userCommand.substr(0, userCommand.find(' '));
}

string Interface::removeFirstWord(string userCommand) {
	return userCommand.substr(userCommand.find_first_of(" ") + 1);
}

string Interface::getTaskMessage(string taskString) {
	if (determineTaskType(taskString) == TASK_TYPE::STATIC) {
		size_t foundFrom = taskString.find("-from");
		return taskString.substr(0, foundFrom - 1);
	}
	else if (determineTaskType(taskString) == TASK_TYPE::DEADLINE) {
		size_t foundBy = taskString.find("-by");
		return taskString.substr(0, foundBy - 1);
	}
	else {
		return taskString;
	}
}

void Interface::help() {
	cout << "Here are some instructions for you to follow:\n";
	cout << " 1. Add Function: add CS meeting -from 1200 -to 1400 23/12\n";
	cout << " 2. Display All Tasks Function: display all\n";
	cout << " 3. Update Function: Update 1 CS meeting -from 1300 -to 1500 23/12\n";
	cout << " 4. Search Function: search CS meeting\n";
	cout << " 5. Delete Function: delete 1\n";
	cout << " 6. Display Floating Tasks Function: display floating\n";
	cout << " 7. Display Static Tasks Function: display static\n ";
	cout << " 8. Display Deadline Tasks Function: display deadline\n";
	cout << " 9. Display Unfinished Tasks Function: display unfinished\n";
	cout << "10. Display Finished Tasks Function: display finished\n";
	cout << "11. Display Today's Tasks Function: display today\n";
	cout << "12. Undo Function: undo\n";
	cout << "13. Redo Function: redo\n";
	cout << "14. Exit Function: exit\n";
}