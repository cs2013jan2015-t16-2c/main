// Source File
// Interface.cpp

#include "InterfaceInput.h"
#include <assert.h>

//@author A0093586N
//These are the shortened commands
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

//These are the output information for 'clear all' action
const string InterfaceInput::MESSAGE_ABORT_CLEAR = "Clear action aborted";
const string InterfaceInput::SYMBOL_YES = "Y";
const string InterfaceInput::SYMBOL_NO = "N";

//These are for unit testing only
string InterfaceInput::TEST_OUTPUT_EXECUTE;
string InterfaceInput::TEST_OUTPUT_TODAY;

//to 'cin' user's command and pass it to 'executeUserCommand' function
//for further processing
string InterfaceInput::getUserCommand() {
	string userCommand;

	cout << MagicString::MESSAGE_USER_COMMAND;
	getline(cin, userCommand);

	return userCommand;
}

//to receive user's command, process it,
//and return the corresponding feedback to the user
string InterfaceInput::executeUserCommand(string userCommand) {
	assert(userCommand != "");
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
		if (displayText == MagicString::FLOATING_CANNOT_RECUR) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText == MagicString::RECURRING_TASK_ADDED) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		else if (displayText == MagicString::INVALID_TIME_INPUT) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText == MagicString::TASK_ADDED) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		else {
			//displayText is MagicString::INVALID_TIME_INPUT
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();

	case SEARCH:
		displayText = TaskList::search(taskString);
		if (displayText == MagicString::TASK_EMPTY) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText);
		}
		else if (displayText == MagicString::SEARCH_NOT_FOUND) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText);
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayColor(displayText); //For unit testing
		}
		return STRING_EMPTY;
	
	case UPDATE:
		displayText = TaskList::updateTask(taskString);
		if (displayText == MagicString::MESSAGE_INVALID_INDEX) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText.find(MagicString::NON_EXISTENCE) != string::npos) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText == MagicString::INVALID_TIME_INPUT) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			cout << TaskList::updateTask(taskString) << endl;
		}
		cout << endl;
		cout << endl;
		return displayToday();
	
	case DELETE_TASK:
		displayText = TaskList::deleteTask(taskString);
		if (displayText == MagicString::MESSAGE_INVALID_INDEX) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText.find(MagicString::NON_EXISTENCE) != string::npos) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();
	
	case DISPLAY_TASKS:
		displayText = TaskList::display(taskString);
		if (displayText == MagicString::INVALID_DISPLAY) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText == MagicString::TASK_EMPTY2){
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayColor(displayText); //For unit testing
		}
		return STRING_EMPTY;
	
	case MARK_DONE:
		displayText = TaskList::markAsDone(taskString);
		if (displayText == MagicString::MESSAGE_INVALID_INDEX) {
			TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText.find(MagicString::NON_EXISTENCE) != string::npos) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();
	
	case SET_PRIORITY:
		displayText = TaskList::setPriority(taskString);
		if (displayText == MagicString::MESSAGE_INVALID_INDEX) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText.find(MagicString::NON_EXISTENCE) != string::npos) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else if (displayText == MagicString::INVALID_PRIORITY) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			//displayText is MagicString::SET_PRIORITY
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();
	
	case ARCHIVE:
		displayText = storage::archive(taskString);
		TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		return STRING_EMPTY;
	
	case SAVE_DONE:
		displayText = storage::saveDone();
		TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		return STRING_EMPTY;
	
	case SAVE_IN_PROGRESS:
		displayText = storage::saveProgress();
		TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		return STRING_EMPTY;
	
	case CLEAR_FILE:
		if (isConfirmedToClear()) {
			displayText = storage::deletePer();
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
			return STRING_EMPTY;
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(MESSAGE_ABORT_CLEAR); //For unit testing
			return STRING_EMPTY;
		}
	
	case CLEAR_ARCHIVE:
		displayText = storage::archiveDelete(taskString);
		TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		return STRING_EMPTY;
	
	case UNDO:
		displayText = TaskList::undo();
		if (displayText == MagicString::UNDO_UNABLE) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();
	
	case REDO:
		displayText = TaskList::redo();
		if (displayText == MagicString::REDO_UNABLE) {
			InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(displayText); //For unit testing
		}
		else {
			TEST_OUTPUT_EXECUTE = DisplayColor::displaySuccess(displayText); //For unit testing
		}
		cout << endl;
		cout << endl;
		return displayToday();

	case EXIT:
		TaskList::copyToStorage();
		cout << MagicString::MESSAGE_GOODBYE << endl;
		exit(0);
	
	case OTHERS:
	default:
		InterfaceInput::TEST_OUTPUT_EXECUTE = DisplayColor::displayError(MagicString::ERROR_INVALID_COMMAND); //For unit testing
		return STRING_EMPTY;
	}
}

//to determine which command type the user command belongs to
//and to return the command type to the 'executeUserCommand' function
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

//to display today's task list to the user
string InterfaceInput::displayToday() {
	string displayText;

	cout << MagicString::MESSAGE_TODAY_TASK << endl;
	displayText = TaskList::display(STRING_TODAY);
	if (displayText != MagicString::TASK_EMPTY2) {
		TEST_OUTPUT_TODAY = DisplayColor::displayColor(displayText); //For unit testing
		return STRING_EMPTY;
	}
	else {
		TEST_OUTPUT_TODAY = DisplayColor::displayError(MagicString::MESSAGE_NO_TASK_TODAY); //For unit testing
		return STRING_EMPTY;
	}
}

//when the user decides to 'clear all' function,
//the following function is used to confirm the above action
//as 'clear all' action cannot be undone.
bool InterfaceInput::isConfirmedToClear(){
	DisplayColor::displayError(MagicString::MESSAGE_WARNING_1);
	cout << MagicString::MESSAGE_WARNING_2;
	string userInput;
	while (true){
		getline(cin, userInput);
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		cout << MagicString::DIVIDER;
		if (userInput == SYMBOL_YES) {
			return true;
		}
		else if (userInput == SYMBOL_NO) {
			return false;
		}
		else{
			DisplayColor::displayError(MagicString::ERROR_INVALID_COMMAND);
			cout << '\n' << MagicString::ERROR_TYPE_AGAIN;
		}
	}
}

// These are for unit test only
// to call private functions
string InterfaceInput::testGetFirstWord(string testString) {
	return InterfaceInput::getFirstWord(testString);
}

string InterfaceInput::testRemoveFirstWord(string testString){
	return InterfaceInput::removeFirstWord(testString);
}