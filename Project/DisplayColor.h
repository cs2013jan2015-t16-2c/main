// Header File
// DisplayColor.h
#ifndef DISPLAYCOLOR_H_
#define DISPLAYCOLOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include "MagicString.h"

//@author A0093586N
using namespace std;

class DisplayColor{
private:
	static const string SYMBOL_NEW_LINE;
	static const string SYMBOL_PRIORITY_A;
	static const string SYMBOL_PRIORITY_B;
	static const string SYMBOL_PRIORITY_C;
	static const string EMPTY_STRING;
	static const string STRING_SPACE;

public:
	static string displayColor(string displayText);
	static string displaySuccess(string displayText);
	static string displayError(string displayText);

	//this is for unit testing only
	static string TEST_OUTPUT;
};
#endif