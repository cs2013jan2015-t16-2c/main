// Header File
// BasicUI.h

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <sstream>
#include <time.h>
#include "TaskList.h"
//#include 'Task class' header file

using namespace std;

class Interface {
public:
	enum COMMAND_TYPE {
		HELP, ADD_FLOATING, ADD_STATIC, ADD_DEADLINE, UPDATE, DELETE_TASK, SEARCH,
		DISPLAY_ALL, DISPLAY_SATIC, DISPLAY_DEADLINE, DISPLAY_FLOATING, DISPLAY_UNFINISHED, DISPLAY_FINISHED, DISPLAY_TODAY,
		MARK_DONE, UNDO, REDO, EXIT
	};

	enum TASK_TYPE {
		STATIC_TASK, DEADLINE, FLOATING_TASK
	};

private:
	static string MESSAGE_WELCOME;
	static const string MESSAGE_ADDED;
	static const string MESSAGE_DELETED;
	static const string MESSAGE_GOODBYE;

	static const string ERROR_INVALID_COMMAND;

	static string displayWelcome();
	static void showToUser(string text);

	static void startUp(vector<string> tempStorage, string fileName);

	static string getUserCommand();
	static TASK_TYPE determineTaskType(string taskString);
	static COMMAND_TYPE determineCommandType(string commandTypeString, string taskString);

	static string getFirstWord(string userCommand);
	static string removeFirstWord(string userCommand);
	static string getTaskMessage(string taskString);

	static void help();

public:
	static string executeUserCommand(string fileName, string userCommand);
};
#endif