#include "Interface.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"

int main() {
	showToUser(welcomeMessage());
	cout << "\n============================================================================================\n";
	while (true) {
		string userCommand;
		string output;

		userCommand = getUserCommand();
		output = executeUserCommand(userCommand);
		showToUser(output);
		cout << "\n============================================================================================\n";
	}
	return 0;
}