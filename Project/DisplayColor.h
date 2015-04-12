// Header File
// DisplayColor.h
#ifndef DISPLAYCOLOR_H_
#define DISPLAYCOLOR_H_

#include <iostream>
#include <sstream>
#include <string>

//@author A0093586N
using namespace std;

class DisplayColor{
private:
	static const string SYMBOL_NEW_LINE;
	static const string SYMBOL_PRIORITY_A;
	static const string SYMBOL_PRIORITY_B;
	static const string SYMBOL_PRIORITY_C;
	static const string STATUS_IN_PROGRESS;
	static const string STATUS_DONE;
	static const string EMPTY_STRING;

public:
	static string displayColor(string displayText);
	static string displaySuccess(string displayText);
	static string displayError(string displayText);

	//this is for unit testing only
	static string TEST_OUTPUT;
};
#endif