#define _CRT_SECURE_NO_WARNINGS // to avoid warnings due to 'localtime'
#include "InterfaceInput.h"
#include "InterfaceOutput.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"
#include <ctime>

int main() {
	InterfaceOutput::showToUser(InterfaceOutput::displayWelcome());
    cout << "                       Today is ";
    
    time_t t = time(0);
    struct tm * now = localtime(&t);
    cout << now -> tm_year + 1900 << '-' << now -> tm_mon + 1 << '-' << now -> tm_mday << endl;
	
    cout << "================================================================================\n";
    
	while (true) {
		string userCommand;
		string output;

		userCommand = InterfaceInput::getUserCommand();
		output = InterfaceInput::executeUserCommand(userCommand);
		InterfaceOutput::showToUser(output);
		cout << "\n================================================================================\n";
    }

	return 0;
}