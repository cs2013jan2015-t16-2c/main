#include "Interface.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"

int main() {
	Interface::showToUser(Interface::displayWelcome());
	cout << "================================================================================\n";
	while (true) {
		string userCommand;
		string output;

		userCommand = Interface::getUserCommand();
		output = Interface::executeUserCommand(userCommand);
		Interface::showToUser(output);
		cout << "\n================================================================================\n";
    }

	return 0;
}