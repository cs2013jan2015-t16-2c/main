#include "InterfaceInput.h"
#include "InterfaceOutput.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"
#include "DisplayedTaskList.h"
#include "Help.h"
#include "MagicString.h"

int main() {
	storage::backup();
	InterfaceOutput::showToUser(storage::starting());
	InterfaceOutput::showToUser(InterfaceOutput::displayWelcome());
	InterfaceOutput::displayTime();
	TaskList::copyFromStorage();
	
    cout << MagicString::DIVIDER;
	InterfaceOutput::showToUser(InterfaceOutput::displayTip());
	cout << MagicString::DIVIDER;

	while (true) {
		string userCommand;
		string output;

		userCommand = InterfaceInput::getUserCommand();
		output = InterfaceInput::executeUserCommand(userCommand);
		InterfaceOutput::showToUser(output);
		cout << MagicString::DIVIDER;
    }

	return 0;
}