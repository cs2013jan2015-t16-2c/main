#include "InterfaceInput.h"
#include "InterfaceOutput.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"
#include "DisplayedTaskList.h"
#include "Help.h"
#include "DisplayColor.h"

//@author A0093586N
int main() {
	storage::backup();
	DisplayColor::displaySuccess(storage::starting());
	cout << endl;
	InterfaceOutput::showToUser(InterfaceOutput::displayWelcome());
	InterfaceOutput::displayDate();
	TaskList::copyFromStorage();
	
	cout << MagicString::DIVIDER;
	InterfaceOutput::showToUser(InterfaceOutput::displayTip());
	cout << MagicString::DIVIDER;

	while (true) {
		string userCommand;
		string output;

		userCommand = InterfaceInput::getUserCommand();
		storage::logging(userCommand);
		system("cls");
		InterfaceOutput::displayDate();
		cout << MagicString::DIVIDER;
		cout << MagicString::MESSAGE_USER_COMMAND << userCommand << endl;
		output = InterfaceInput::executeUserCommand(userCommand);
		InterfaceOutput::showToUser(output);
		cout << MagicString::DIVIDER;
    }

	return 0;
}