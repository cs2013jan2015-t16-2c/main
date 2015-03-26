#include "storage.h"

vector<string> storage::task;
const string storage::FILENAME = "storage.txt";

void storage::ending() {
	ofstream file;
	string content;

	remove(FILENAME.c_str());

	file.open(FILENAME);
	content = TaskList::display("all");
	file << content << endl;	
	file.close();
}

string storage::starting() {
	ifstream file;
	string currentLine;
	string outputString;

	task.clear();
	file.open(FILENAME);

	while(getline(file,currentLine)) {
		task.push_back(currentLine);
	}
	file.close();

	outputString = "Programme started!";
	return outputString;
}

vector<string> storage::returnTask() {
	return task;
}

string storage::archive(string fileName){
	ofstream file;
	string content;

	file.open(fileName);
	content = TaskList::display("all");
	file << content << endl;	
	file.close();
	
	string str = "Tasklist is successfully archived.";
	return str;

} 