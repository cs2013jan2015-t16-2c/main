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

//@author A0093586N
class InterfaceOutput {
public:
	static string displayWelcome();
	static void displayDate();
	static string displayTip();
	static void showToUser(string text);
};
#endif