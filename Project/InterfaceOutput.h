// Header File
// InterfaceOutput.h

#define _CRT_SECURE_NO_WARNINGS // to avoid warnings due to 'localtime'

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
#include <ctime>

using namespace std;

class InterfaceOutput {
public:
	//static const string MESSAGE_WELCOME;
	//static const string MESSAGE_TIP;
	//static const string MESSAGE_GOODBYE;

	//static const string ERROR_INVALID_COMMAND;
public:
	static string displayWelcome();
	static void displayTime();
	static string displayTip();
	static void showToUser(string text);
};
#endif