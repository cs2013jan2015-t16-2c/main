// Header File
// InterfaceOutput.h

#ifndef INTERFACEOUTPUT_H_
#define INTERFACEOUTPUT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <sstream>
#include "TaskList.h"
#include "Storage.h"

using namespace std;

class InterfaceOutput {
public:
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_TASK_ADDED;
	static const string MESSAGE_TASK_DELETED;
	static const string MESSAGE_TASK_UPDATED;
	static const string MESSAGE_GOODBYE;

	static const string ERROR_INVALID_COMMAND;
	static const string ERROR_INVALID_DELETE;
	static const string ERROR_INVALID_UPDATE;
public:
	static string displayHelp();
	static string displayWelcome();
	static void showToUser(string text);
};
#endif