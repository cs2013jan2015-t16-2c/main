#define _CRT_SECURE_NO_WARNINGS
#include "InterfaceOutput.h"
#include "MagicString.h"

//const string InterfaceOutput::MESSAGE_WELCOME = "Welcome to KeepTrack";
//const string InterfaceOutput::MESSAGE_TIP = "Tip: enter 'help' to learn how to use KeepTrack";
//const string InterfaceOutput::MESSAGE_GOODBYE = "Goodbye!";

//const string InterfaceOutput::ERROR_INVALID_COMMAND = "Error: invalid command!";

string InterfaceOutput::displayWelcome() {
	return MagicString::MESSAGE_WELCOME;
}

void InterfaceOutput::displayTime() {
	cout << MagicString::TODAY;

	time_t t = time(0);
	struct tm * now = localtime(&t);
	cout << now->tm_mday << '-' << now->tm_mon + 1 << '-' << now->tm_year + 1900 << endl;
}

string InterfaceOutput::displayTip() {
	return MagicString::MESSAGE_TIP;
}

void InterfaceOutput::showToUser(string text) {
	cout << text << endl;
}

