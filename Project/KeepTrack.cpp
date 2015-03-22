#include "InterfaceInput.h"
#include "InterfaceOutput.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"

int main() {
	InterfaceOutput::showToUser(InterfaceOutput::displayWelcome());
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