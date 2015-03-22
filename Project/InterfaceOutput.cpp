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
	cout << " 1. Add a Task: add CS meeting -from 1200 -to 1400 23/12\n";
	cout << " 2. Display All the Tasks: display all\n";
	cout << " 3. Update a Task: Update 1 -from 1300 -to 1500 23/12\n";
	cout << " 4. Search a Word: search CS meeting\n";
	cout << " 5. Delete a Task: delete 1\n";
	cout << " 6. Display All the Floating Tasks: display floating\n";
	cout << " 7. Display All the Static Tasks: display static\n";
	cout << " 8. Display All the Deadlines: display deadline\n";
	cout << " 9. Display All the Unfinished Tasks: display unfinished\n";
	cout << "10. Display All the Finished Tasks: display finished\n";
	cout << "11. Display Today's Tasklist: display today\n";
	cout << "12. Archive the Tasklist in the Program Folder: archive myText.txt";
	cout << "13. Archive the Tasklist in user-defined location: archive C:/Users/USER/Desktop/myText.txt";
	cout << "14. Undo the Most Recent Action: undo\n";
	cout << "15. Redo the Most Recent Action: redo\n";
	cout << "16. Exit the Program: exit\n";
	
	return "";
}
void InterfaceOutput::showToUser(string text) {
	cout << text << endl;
}

