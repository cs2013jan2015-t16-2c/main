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

	static const string ADD_HELP_PAGE_INDEX;
	static const string DISPLAY_HELP_PAGE_INDEX;
	static const string DELETE_HELP_PAGE_INDEX;
	static const string UPDATE_HELP_PAGE_INDEX;
	static const string UNDO_HELP_PAGE_INDEX;
	static const string REDO_HELP_PAGE_INDEX;
	static const string ARCHIVE_HELP_PAGE_INDEX;
	static const string EXIT_HELP_PAGE_INDEX;
	static const string REUTRN_TO_MAIN_HELP_PAGE;
	static const string EXIT_HELP;

	static bool isInMainHelpPage;

	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_NEXT_ACTION;
	static const string MESSAGE_RETURN_TO_MAIN;
	static const string MESSAGE_EXIT_HELP;
	static const string MESSAGE_COMMAND;
public:
	static void showHelp(string helpText);
	static string executeHelpCommand();
};

#endif