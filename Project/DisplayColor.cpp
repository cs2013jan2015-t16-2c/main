// Header File
// DisplayColor.cpp

#include "DisplayColor.h"
#include "concol.h"
using namespace eku;

//@author A0093586N
const string DisplayColor::SYMBOL_NEW_LINE = "\n";
const string DisplayColor::SYMBOL_PRIORITY_A = "(A)";
const string DisplayColor::SYMBOL_PRIORITY_B = "(B)";
const string DisplayColor::SYMBOL_PRIORITY_C = "(C)";
const string DisplayColor::STATUS_IN_PROGRESS = "in progress";
const string DisplayColor::STATUS_DONE = "done";

//this is for unit testing only
string DisplayColor::TEST_OUTPUT;

//to display a task list in a colored form
string DisplayColor::displayColor(string displayText) {
	concolinit();

	size_t foundNewLineStart = 0;
	size_t foundNewLineEnd = 0;
	size_t foundTag = 0;
	size_t foundAt = 0;
	size_t foundSpace = 0;
	size_t foundInProcessOrDone = 0;

	while (foundNewLineEnd != string::npos) {
		foundNewLineEnd = displayText.find(DisplayColor::SYMBOL_NEW_LINE, foundNewLineStart);
		string currentLine = displayText.substr(foundNewLineStart, foundNewLineEnd - foundNewLineStart);

		if (currentLine.find(DisplayColor::SYMBOL_PRIORITY_A) != string::npos) {
			settextcolor(red);
		}
		else if (currentLine.find(DisplayColor::SYMBOL_PRIORITY_B) != string::npos) {
			settextcolor(yellow);
		}
		else if (currentLine.find(DisplayColor::SYMBOL_PRIORITY_C) != string::npos) {
			settextcolor(cyan);
		}
		else {
			settextcolor(white);
		}

		if (currentLine.find('#') != string::npos && currentLine.find('@') != string::npos) {
			foundTag = currentLine.find('#');
			cout << currentLine.substr(0, foundTag - 0);
			TEST_OUTPUT = currentLine.substr(0, foundTag - 0);
			foundSpace = currentLine.find(" ", foundTag);
			settextcolor(dark_aqua);

			foundAt = currentLine.find('@');
			cout << currentLine.substr(foundTag, foundAt - foundTag);
			TEST_OUTPUT += currentLine.substr(foundTag, foundAt - foundTag);
			foundSpace = currentLine.find(" ", foundAt);
			settextcolor(dark_green);
			cout << currentLine.substr(foundAt, foundSpace - foundAt) << endl;
			TEST_OUTPUT += currentLine.substr(foundAt, foundSpace - foundAt);
		}
		else if (currentLine.find('#') != string::npos && currentLine.find('@') == string::npos) {
			foundTag = currentLine.find('#');
			cout << currentLine.substr(0, foundTag - 0);
			TEST_OUTPUT = currentLine.substr(0, foundTag - 0);
			foundSpace = currentLine.find(" ", foundTag);
			settextcolor(dark_aqua);
			cout << currentLine.substr(foundTag, foundSpace - foundTag) << endl;
			TEST_OUTPUT += currentLine.substr(foundTag, foundSpace - foundTag);
		}
		else if (currentLine.find('#') == string::npos && currentLine.find('@') != string::npos) {
			foundAt = currentLine.find('@');
			cout << currentLine.substr(0, foundAt - 0);
			TEST_OUTPUT = currentLine.substr(0, foundAt - 0);
			foundSpace = currentLine.find(" ", foundAt);
			settextcolor(dark_green);
			cout << currentLine.substr(foundAt, foundSpace - foundAt) << endl;
			TEST_OUTPUT += currentLine.substr(foundAt, foundSpace - foundAt);
		}
		else {
			if (currentLine.find(DisplayColor::STATUS_DONE) != string::npos) {
				foundInProcessOrDone = currentLine.find(DisplayColor::STATUS_DONE);
				cout << currentLine.substr(0, foundInProcessOrDone) << endl;
				TEST_OUTPUT = currentLine.substr(0, foundInProcessOrDone);
			}
			else {
				foundInProcessOrDone = currentLine.find(DisplayColor::STATUS_IN_PROGRESS);
				cout << currentLine.substr(0, foundInProcessOrDone) << endl;
				TEST_OUTPUT = currentLine.substr(0, foundInProcessOrDone);
			}
		}

		//if (currentLine.find(DisplayColor::)

		foundNewLineStart = foundNewLineEnd + 1;
	}
	settextcolor(deftextcol);
	return TEST_OUTPUT;
}

//to display a message after a successful action in 'green'
string DisplayColor::displaySuccess(string displayText) {
	concolinit();
	settextcolor(dark_green);
	cout << displayText;
	TEST_OUTPUT = displayText;
	settextcolor(deftextcol);
	return TEST_OUTPUT;
}

//to display an error message 'red'
string DisplayColor::displayError(string displayText) {
	concolinit();
	settextcolor(red);
	cout << displayText;
	DisplayColor::TEST_OUTPUT = displayText;
	settextcolor(deftextcol);
	return TEST_OUTPUT;
}