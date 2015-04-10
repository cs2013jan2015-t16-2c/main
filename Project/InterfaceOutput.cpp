#define _CRT_SECURE_NO_WARNINGS
#include "InterfaceOutput.h"
#include "MagicString.h"

string InterfaceOutput::displayWelcome() {
	return MagicString::MESSAGE_WELCOME;
}

void InterfaceOutput::displayDate() {
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

