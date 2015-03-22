#include "InterfaceOutput.h"


const string InterfaceOutput::MESSAGE_WELCOME = "Welcome to KeepTrack";
const string InterfaceOutput::MESSAGE_GOODBYE = "Goodbye!";

const string InterfaceOutput::ERROR_INVALID_COMMAND = "Error: invalid command!";

string InterfaceOutput::displayWelcome() {
	storage::starting();
	TaskList::copyFromStorage();
	return InterfaceOutput::MESSAGE_WELCOME;
}

string InterfaceOutput::displayHelp() {
	cout << "Here are some instructions for you to follow:\n";
	cout << " 1. Add Function: add CS meeting -from 1200 -to 1400 23/12\n";
	cout << " 2. Display All Tasks Function: display all\n";
	cout << " 3. Update Function: Update 1 -from 1300 -to 1500 23/12\n";
	cout << " 4. Search Function: search CS meeting\n";
	cout << " 5. Delete Function: delete 1\n";
	cout << " 6. Display Floating Tasks Function: display floating\n";
	cout << " 7. Display Static Tasks Function: display static\n";
	cout << " 8. Display Deadline Tasks Function: display deadline\n";
	cout << " 9. Display Unfinished Tasks Function: display unfinished\n";
	cout << "10. Display Finished Tasks Function: display finished\n";
	cout << "11. Display Today's Tasks Function: display today\n";
	cout << "12. Undo Function: undo\n";
	cout << "13. Redo Function: redo\n";
	cout << "14. Exit Function: exit\n";

	return "";
}
void InterfaceOutput::showToUser(string text) {
	cout << text << endl;
}

