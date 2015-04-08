#define _CRT_SECURE_NO_WARNINGS
#include "InterfaceOutput.h"
#include "MagicString.h"

string InterfaceOutput::TodayDate;

//@Cai Yu A0093586N
string InterfaceOutput::displayWelcome() {
	return MagicString::MESSAGE_WELCOME;
}

//@Cai Yu A0093586N
void InterfaceOutput::displayTime() {
	cout << MagicString::TODAY;

	time_t t = time(0);
	struct tm * now = localtime(&t);
	int month = now->tm_mon + 1;
	int day = now->tm_mday;
	
	ostringstream mon;
	if (month < 10){
		mon << "0" << month;
	}
	else{
		mon << month;
	}
	string month_s = mon.str();
	
	ostringstream date;
	if (day < 10){
		date << "0" << day;
	}
	else{
		date << day;
	}
	string day_s = date.str();

	TodayDate = day_s + "/" + month_s;
	cout << now->tm_mday << '-' << now->tm_mon + 1 << '-' << now->tm_year + 1900 << endl;
}

//@Cai Yu A0093586N
string InterfaceOutput::returnTodayDate(){
	return TodayDate;
}

//@Cai Yu A0093586N
string InterfaceOutput::displayTip() {
	return MagicString::MESSAGE_TIP;
}

//@Cai Yu A0093586N
void InterfaceOutput::showToUser(string text) {
	cout << text << endl;
}

