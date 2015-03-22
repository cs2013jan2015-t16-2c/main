#include "InterfaceInput.h"
#include "InterfaceOutput.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"

int main() {
	InterfaceOutput::showToUser(InterfaceOutput::displayWelcome());
    cout << "                       Today is ";
    
    time_t currentTime;
    time (&currentTime);
    struct tm * today= localtime(&currentTime);
    cout << today -> tm_year+1900 << ' ' << m_months[today -> tm_mon + 1] << ' ' << today -> tm_mday << ".\n";
	
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