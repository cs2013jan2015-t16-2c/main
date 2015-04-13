#include "storage.h"
#include "MagicString.h"
#include "TaskList.h"
#include <assert.h>

vector<string> storage::task;
const string storage::FILENAME = "storage.txt";
const string storage::TEMP = "temp.txt";
const string storage::DONE = "done.txt";
const string storage::PROGRESS = "progress.txt";
const string storage::LOGFILE = "log.txt";

//@author A0114792A
void storage::ending() {
	ofstream file;
	string content;

	remove(FILENAME.c_str());

	file.open(FILENAME);
	content = TaskList::display("all");
	
	try {
		if (content != MagicString::TASK_EMPTY2){
			throw 1;
		}
	}
	catch (int){
		file << content;
	}

	content = TaskList::display("done");
	
	try{
		if(content != MagicString::TASK_EMPTY2)
			throw 'a';
	}
	catch(char){
		file << endl;
		file << content;
	}

	file.close();
}

string storage::starting() {
	ifstream file;
	string currentLine;

	task.clear();
	file.open(FILENAME);

	while(getline(file,currentLine)) {
		task.push_back(currentLine);
	}
	file.close();

	return MagicString::PROGRAM_START;
}

string storage::deletePer(){
	remove(FILENAME.c_str());
	TaskList::empty();
	return MagicString::STORAGE_CLEARED;
}

vector<string> storage::returnTask() {
	return task;
}

string storage::saveDone(){
	ofstream file;
	string content;

	remove(DONE.c_str());

	file.open(DONE);
	content = TaskList::display("done");
	if (content != MagicString::TASK_EMPTY2){
		file << content;
	}
	file.close();

	return MagicString::DONE_TASK_SAVED;
}

string storage::saveProgress(){
	ofstream file;
	string content;

	remove(PROGRESS.c_str());

	file.open(PROGRESS);
	content = TaskList::display("all");
	if (content != MagicString::TASK_EMPTY2){
		file << content;
	}
	file.close();

	return MagicString::IN_PROGRESS_TASK_SAVED;
}

string storage::archive(string fileName){
	assert(fileName.size() > 4); 
	
	try{
		if (fileName.find(".txt") == string::npos) {
			throw 1;
		}
	}
	catch (int){
		return MagicString::FORMAT_INCORRECT;
	}
	
	ofstream file;
	string content;

	file.open(fileName);
	content = TaskList::display("all");
	if (content != MagicString::TASK_EMPTY2){
		file << content;
	}

	content = TaskList::display("done");
	if (content != MagicString::TASK_EMPTY2){
		file << endl;
		file << content;
	}
	file.close();
	
	return MagicString::SUCCESS_ARCHIVE;
} 

string storage::archiveDelete(string location){
	remove(location.c_str());
	return MagicString::ARCHIVE_CLEARED;
}

void storage::checkRubbish(){
	ifstream file;
	string firstLine;

	file.open(FILENAME);
	getline(file,firstLine);

	if (firstLine.substr(0,1) != "1"){
		remove(FILENAME.c_str());
	}
}

void storage::tempFile(){ //call by every command
	ofstream temporary;
	string content;

	remove(TEMP.c_str());
	temporary.open(TEMP);
	content = TaskList::display("all");
	if (content != MagicString::TASK_EMPTY2){
		temporary << content;
	}

	content = TaskList::display("done");
	if (content != MagicString::TASK_EMPTY2){
		temporary << endl;
		temporary << content;
	}
	temporary.close();
}

void storage::deleteTemp(){ //call if exit is exeucited
	remove(TEMP.c_str());
}

void storage::backup(){ //call before starting function
	ifstream temporary;
	ofstream file;
	string tempLine;
	string line;

	temporary.open(TEMP);
	getline(temporary,line);

	if(line.size()!= 0){
		remove(FILENAME.c_str());
		file.open(FILENAME);
		
		file << line << endl;

		while(!temporary.eof()){
			getline(temporary,tempLine);
			file << tempLine << endl;
		}
		file.close();
		temporary.close();
		remove(TEMP.c_str());
	}
	else{
		temporary.close();
		remove(TEMP.c_str());
	}
}

void storage::logging(string input){
	ifstream readFile;
	ofstream writeFile;
	string line;
	string content;

	readFile.open(LOGFILE);
	
	while (getline(readFile, line)) {
		content = content + line;
		content = content + '\n';
	}
	readFile.close();

	content += input;
	writeFile.open(LOGFILE);
	writeFile << content <<endl;
	writeFile.close();
}