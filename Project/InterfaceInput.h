// Header File
// Interface.h

#ifndef INTERFACEINPUT_H_
#define INTERFACEINPUT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <sstream>
#include "Help.h"
#include "Storage.h"
#include "TaskList.h"
#include "InterfaceOutput.h"
#include "MagicString.h"
#include "DisplayColor.h"

using namespace std;


class InterfaceInput {
public:
	enum COMMAND_TYPE {
		HELP, ADD_TASK, UPDATE, DELETE_TASK, SEARCH, DISPLAY_TASKS, MARK_DONE, SET_PRIORITY, 
		ARCHIVE, SAVE_DONE, SAVE_IN_PROGRESS, CLEAR_FILE, CLEAR_ARCHIVE, UNDO, REDO, EXIT, OTHERS
	};

private:
	static const string SHORTENED_COMMAND_UPDATE;
	static const string SHORTENED_COMMAND_DELETE;
	static const string SHORTENED_COMMAND_DISPLAY;
	static const string SHORTENED_COMMAND_SEARCH;
	static const string SHORTENED_COMMAND_ARCHIVE;
	static const string SHORTENED_COMMAND_UNDO;
	static const string SHORTENED_COMMAND_REDO;
	static const string SHORTENED_COMMAND_EXIT;
	
	static const string STRING_TODAY;
	static const string STRING_EMPTY;
	static const string STRING_DO_NOT_EXIST;

	static const string MESSAGE_ABORT_CLEAR;
	static const string SYMBOL_YES;
	static const string SYMBOL_NO;

	static COMMAND_TYPE determineCommandType(string commandTypeString, string taskString);

	static string getFirstWord(string userCommand);
	static string removeFirstWord(string userCommand);

public:
	static string executeUserCommand(string userCommand);
	static bool isValidDisplayChoice(string taskString);
	static string getUserCommand();
	static string displayToday();
	static bool isConfirmedToClear();

	//These are for unit test
	static string TEST_OUTPUT_EXECUTE;
	static string TEST_OUTPUT_TODAY;
	static string testGetFirstWord(string testString);
	static string testRemoveFirstWord(string testString);
};
#endif
