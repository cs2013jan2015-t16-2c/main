#ifndef HELP_H_
#define HELP_H_

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//@author A0093586N
class Help {
private:
	static void mainHelpPage();
	static void addHelpPage();
	static void displayHelpPage();
	static void setPriorityHelpPage();
	static void deleteHelpPage();
	static void updateHelpPage();
	static void undoRedoHelpPage();
	static void archiveHelpPage();
	static void clearHelpPage();
	static void exitHelpPage();
	static bool isDigit(string userInput);

	static bool isInMainHelpPage;

	static const string STRING_EMPTY;
public:
	static void showHelp(string helpText);
	static string executeHelpCommand();
};
#endif