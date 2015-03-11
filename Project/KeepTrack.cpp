#include "Interface.h"
#include "Task.h"
#include "storage.h"
#include "TaskList.h"

int main() {
	showToUser(welcomeMessage());
	while (true) {
		string userCommand;
		string output;

		userCommand = getUserCommand();
		output = executeUserCommand(userCommand);
		showToUser(output);
	}
	return 0;
}