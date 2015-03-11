#include "storage.h"

const string storage::FILENAME = "storage.txt";

void storage::ending() {
	ofstream file;
	string currentLine;

	remove(FILENAME.c_str());

	file.open(FILENAME);
	currentLine = TaskList::display();
	file << currentLine << endl;	
	file.close();
}

void storage::starting() {
	ifstream file;
	string currentLine;

	task.clear();
	file.open(FILENAME);

	while(getline(file,currentLine)) {
		task.push_back(currentLine);
	}
	file.close();
}

vector<string> storage::returnTask() {
	return task;
}
