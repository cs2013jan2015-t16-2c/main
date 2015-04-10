// Source File
// Interface.cpp

#include "InterfaceInput.h"

const string InterfaceInput::SHORTENED_COMMAND_UPDATE = "up";
const string InterfaceInput::SHORTENED_COMMAND_DELETE = "del";
const string InterfaceInput::SHORTENED_COMMAND_DISPLAY = "dis";
const string InterfaceInput::SHORTENED_COMMAND_SEARCH = "se";
const string InterfaceInput::SHORTENED_COMMAND_ARCHIVE = "arc";
const string InterfaceInput::SHORTENED_COMMAND_UNDO = "un";
const string InterfaceInput::SHORTENED_COMMAND_REDO = "re";
const string InterfaceInput::SHORTENED_COMMAND_EXIT = "q";

const string InterfaceInput::STRING_EMPTY = "";
const string InterfaceInput::STRING_TODAY = "today";
const string InterfaceInput::STRING_DO_NOT_EXIST = "does not exit";

//@Cai Yu A0093586N
string InterfaceInput::getUserCommand() {
	string userCommand;

	cout << MagicString::MESSAGE_USER_COMMAND;
	getline(cin, userCommand);

	return userCommand;
}

string InterfaceInput::executeUserCommand(string userCommand) {
	string commandTypeString;
	string taskString;

	commandTypeString = getFirstWord(userCommand);
	taskString = removeFirstWord(userCommand);

	transform(commandTypeString.begin(), commandTypeString.end(), commandTypeString.begin(), ::tolower);
	
	COMMAND_TYPE commandType;
	commandType = determineCommandType(commandTypeString, taskString);

	string displayText;

	switch (commandType) {
	case HELP:
		return Help::executeHelpCommand();
	case ADD_TASK:
		displayText = TaskList::addTask(taskString);
		DisplayColor::displaySuccess(displayText);
		cout << '\n' << MagicString::DIVIDER;
		return displayToday();
	case SEARCH:
		displayText = TaskList::search(taskString);
		DisplayColor::displayColor(displayText);
		return STRING_EMPTY;
	case UPDATE:
		cout << TaskList::updateTask(taskString) << endl;
		cout << MagicString::DIVIDER;
		return displayToday();
	case DELETE_TASK:
		displayText = TaskList::deleteTask(taskString);
		if (displayText.find(STRING_DO_NOT_EXIST) != string::npos) {
			DisplayColor::displayError(displayText);
		}
		else {
			DisplayColor::displaySuccess(displayText);
		}
		cout << '\n' << MagicString::DIVIDER;
		return displayToday();
	case DISPLAY_TASKS:
		displayText = TaskList::display(taskString);
		if (displayText == MagicString::INVALID_DISPLAY) {
			DisplayColor::displayError(displayText);
		}
		else if (displayText == MagicString::TASK_EMPTY2){
			DisplayColor::displayError(displayText);
		}
		else {
			DisplayColor::displayColor(displayText);
		}
		return STRING_EMPTY;
	case MARK_DONE:
		return TaskList::markAsDone(taskString);
	case SET_PRIORITY:
		displayText = TaskList::setPriority(taskString);
		if (displayText.find(STRING_DO_NOT_EXIST) != string::npos) {
			DisplayColor::displayError(displayText);
		}
		else {
			DisplayColor::displaySuccess(displayText);
		}
		cout << '\n' << MagicString::DIVIDER;
		return displayToday();
	case ARCHIVE:
		displayText = storage::archive(taskString);
		DisplayColor::displaySuccess(displayText);
		return STRING_EMPTY;
	case SAVE_DONE:
		displayText = storage::saveDone();
		DisplayColor::displaySuccess(displayText);
		return STRING_EMPTY;
	case SAVE_IN_PROGRESS:
		displayText = storage::saveProgress();
		DisplayColor::displaySuccess(displayText);
		return STRING_EMPTY;
	case CLEAR_FILE:
		displayText = storage::deletePer();
		DisplayColor::displaySuccess(displayText);
		return STRING_EMPTY;
	case CLEAR_ARCHIVE:
		displayText = storage::archiveDelete(taskString);
		DisplayColor::displaySuccess(displayText);
		return STRING_EMPTY;
	case UNDO:
		displayText = TaskList::undo();
		if (displayText == MagicString::UNDO_UNABLE) {
			DisplayColor::displayError(displayText);
		}
		else {
			DisplayColor::displaySuccess(displayText);
		}
		return STRING_EMPTY;
	case REDO:
		displayText = TaskList::redo();
		if (displayText == MagicString::REDO_UNABLE) {
			DisplayColor::displayError(displayText);
		}
		else {
			DisplayColor::displaySuccess(displayText);
		}
		return STRING_EMPTY;
	case EXIT:
		TaskList::copyToStorage();
		cout << MagicString::MESSAGE_GOODBYE << endl;
		exit(0);
	case OTHERS:
	default:
		DisplayColor::displayError(MagicString::ERROR_INVALID_COMMAND);
		return STRING_EMPTY;
	}
}

InterfaceInput::COMMAND_TYPE InterfaceInput::determineCommandType(string commandTypeString, string taskString) {
	if (commandTypeString == "help") {
		return COMMAND_TYPE::HELP;
	}
	else if (commandTypeString == "add") {
		return COMMAND_TYPE::ADD_TASK;
	}
	else if (commandTypeString == "update" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_UPDATE) {
		return COMMAND_TYPE::UPDATE;
	}
	else if (commandTypeString == "delete" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_DELETE) {
		return COMMAND_TYPE::DELETE_TASK;
	}
	else if (commandTypeString == "search" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_SEARCH) {
		return COMMAND_TYPE::SEARCH;
	}
	else if (commandTypeString == "display" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_DISPLAY) {
		return COMMAND_TYPE::DISPLAY_TASKS;
	}
	else if (commandTypeString == "done") {
		return COMMAND_TYPE::MARK_DONE;
	}
	else if (commandTypeString == "set"){
		return COMMAND_TYPE::SET_PRIORITY;
	}
	else if (commandTypeString == "archive" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_DISPLAY) {
		return COMMAND_TYPE::ARCHIVE;
	}
	else if (commandTypeString == "save") {
		if (taskString == "done") {
			return COMMAND_TYPE::SAVE_DONE;
		}
		else if (taskString == "progress") {
			return COMMAND_TYPE::SAVE_IN_PROGRESS;
		}
		else {
			return COMMAND_TYPE::OTHERS;
		}
	}
	else if (commandTypeString == "clear") {
		if (taskString == "all") {
			return COMMAND_TYPE::CLEAR_FILE;
		}
		else if (taskString == "") {
			return COMMAND_TYPE::OTHERS;
		}
		else {
			return COMMAND_TYPE::CLEAR_ARCHIVE;
		}
	}
	else if (commandTypeString == "undo" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_UNDO) {
		return COMMAND_TYPE::UNDO;
	}
	else if (commandTypeString == "redo" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_REDO) {
		return COMMAND_TYPE::REDO;
	}
	else if (commandTypeString == "exit" || commandTypeString == InterfaceInput::SHORTENED_COMMAND_EXIT) {
		return COMMAND_TYPE::EXIT;
	}
	else{
		return COMMAND_TYPE::OTHERS;
	}
}

string InterfaceInput::getFirstWord(string userCommand) {
	return userCommand.substr(0, userCommand.find(' '));
}

string InterfaceInput::removeFirstWord(string userCommand) {
	return userCommand.substr(userCommand.find_first_of(" ") + 1);
}

string InterfaceInput::displayToday() {
	string displayText;

	cout << MagicString::MESSAGE_TODAY_TASK << endl;
	displayText = TaskList::display(STRING_TODAY);
	if (displayText != MagicString::TASK_EMPTY2) {
		DisplayColor::displayColor(displayText);
		return STRING_EMPTY;
	}
	else {
		return MagicString::MESSAGE_NO_TASK_TODAY;
	}
}

// for unit test only
// to call private functions
string InterfaceInput::testGetFirstWord(string testString) {
	return InterfaceInput::getFirstWord(testString);
}

string InterfaceInput::testRemoveFirstWord(string testString){
	return InterfaceInput::removeFirstWord(testString);
}
