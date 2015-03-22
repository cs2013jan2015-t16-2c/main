#include "storage.h"

vector<string> storage::task;
const string storage::FILENAME = "storage.txt";

void storage::ending() {
	ofstream file;
	string content;

	remove(FILENAME.c_str());

	file.open(FILENAME);
	content = TaskList::display();
	file << content << endl;	
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

void storage::archive(string fileName){
	ofstream file;
	string content;

	file.open(fileName);
	content = TaskList::display();
	file << content << endl;	
	file.close();

} 