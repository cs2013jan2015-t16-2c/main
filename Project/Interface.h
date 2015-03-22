// Header File
// Interface.h

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
#include "Storage.h"

using namespace std;

class Interface {
private:
	enum COMMAND_TYPE {
		HELP, ADD_TASK, UPDATE, DELETE_TASK, SEARCH, DISPLAY_TASKS, MARK_DONE, UNDO, REDO, EXIT, OTHERS
	};

	static const string MESSAGE_WELCOME;
	static const string MESSAGE_GOODBYE;
	static const string ERROR_INVALID_COMMAND;
	static COMMAND_TYPE determineCommandType(string commandTypeString);

	static string getFirstWord(string userCommand);
	static string removeFirstWord(string userCommand);
	static string getTaskMessage(string taskString);

	static string help();

public:
	static string executeUserCommand(string userCommand);

	static string displayWelcome();
	static void showToUser(string text);
	static string getUserCommand();
};
#endif
