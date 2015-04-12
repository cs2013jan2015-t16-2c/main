#define _CRT_SECURE_NO_WARNINGS
#include "InterfaceOutput.h"
#include "MagicString.h"

//@author A0093586N
//to display welcome message to the user when KeepTrack is opened
string InterfaceOutput::displayWelcome() {
	return MagicString::MESSAGE_WELCOME;
}

//to display today's date to the user
void InterfaceOutput::displayDate() {
	cout << MagicString::TODAY;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	cout << now->tm_mday << '-' << now->tm_mon + 1 << '-' << now->tm_year + 1900 << endl;
}

//to display a tip to the user
string InterfaceOutput::displayTip() {
	return MagicString::MESSAGE_TIP;
}

//to display information to the user
void InterfaceOutput::showToUser(string text) {
	cout << text << endl;
}