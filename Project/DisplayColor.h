// Header File
// DisplayColor.h
#ifndef DISPLAYCOLOR_H_
#define DISPLAYCOLOR_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DisplayColor{
private:
	static const string SYMBOL_NEW_LINE;
	static const string SYMBOL_PRIORITY_A;
	static const string SYMBOL_PRIORITY_B;
	static const string SYMBOL_PRIORITY_C;
	static const string STATUS_IN_PROGRESS;
	static const string STATUS_DONE;

public:
	static string displayColor(string displayText);
};
#endif