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
#include "Storage.h"
#include "TaskList.h"
#include "InterfaceOutput.h"

using namespace std;

class InterfaceInput {
public:
	enum COMMAND_TYPE {
		HELP, ADD_TASK, UPDATE, DELETE_TASK, SEARCH, DISPLAY_TASKS, MARK_DONE, SORT, ARCHIVE, UNDO, REDO, EXIT, OTHERS
	};

private:
	static COMMAND_TYPE determineCommandType(string commandTypeString, string taskString);

	static string getFirstWord(string userCommand);
	static string removeFirstWord(string userCommand);

public:
	static string executeUserCommand(string userCommand);

	static string getUserCommand();
};
#endif
