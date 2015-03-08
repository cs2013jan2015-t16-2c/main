#include "storage.h"

void storage::ending(TaskList taskList, string fileName) {
	ofstream file;
	string currentLine;

	remove(fileName.c_str());

	file.open(fileName);
	currentLine = taskList.display();
	file << currentLine << endl;	
	file.close();
}

void storage::starting(vector<string> task, string fileName) {
	ifstream file;
	string currentLine;

	task.clear();
	file.open(fileName);

	while(getline(file,currentLine)) {
		task.push_back(currentLine);
	}
	file.close();
}
vector<string> storage::returnTask(TaskList taskList) {
	return  taskList.display();  //convert TaskList to vector string
}

