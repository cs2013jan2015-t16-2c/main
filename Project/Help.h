#ifndef HELP_H_
#define HELP_H_

#include <iostream>
#include <string>
using namespace std;

class Help {
private:
	static void mainHelpPage();
	static void addHelpPage();
	static void displayHelpPage();
	static void deleteHelpPage();
	static void updateHelpPage();
	static void undoHelpPage();
	static void redoHelpPage();
	static void archiveHelpPage();
	static void exitHelpPage();

	static bool isInMainHelpPage;

public:
	static void showHelp(string helpText);
	static string executeHelpCommand();
};

#endif