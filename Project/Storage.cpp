#include "storage.h"
#include "MagicString.h"

vector<string> storage::task;
const string storage::FILENAME = "storage.txt";
const string storage::TEMP = "temp.txt";

void storage::ending() {
	ofstream file;
	string content;

	remove(FILENAME.c_str());

	file.open(FILENAME);
	content = TaskList::display("all");
	file << content << endl;	

	content = TaskList::display("done");
	file << content << endl;
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

vector<string> storage::returnTask() {
	return task;
}

string storage::archive(string fileName){
	ofstream file;
	string content;

	file.open(fileName);
	content = TaskList::display("all");
	file << content << endl;

	content = TaskList::display("done");
	file << content << endl;

	file.close();
	
	return MagicString::SUCCESS_ARCHIVE;
} 

string storage::checkRubbish(){
	ifstream file;
	string firstLine;

	file.open(FILENAME);
	getline(file,firstLine);

	if (firstLine.substr(0,1) != 1){
		remove(FILENAME.c_str);
		return MagicString::FILE_RUBBISH;
	}
	else {
		return MagicString::FILE_CHECK;
	}
}

void storage::tempFile(){ //call by every command
	ofstream temporary;
	string content;

	temporary.open(TEMP);
	content = TaskList::display("all");
	temporary << content << endl;	

	content = TaskList::display("done");
	temporary << content << endl;

	temporary.close();
}

void storage::deleteTemp(){ //call if exit is exeucited
	remove(TEMP.c_str);
}

void storage::backup(){ //call before startin function
	ifstream temporary;
	ofstream file;
	string line;
	string tempLine;

	temporary.open(TEMP);
	getline(temporary,line);

	if(line.size()!= 0){
		remove(FILENAME.c_str());
		file.open(FILENAME);
		
		while(!temporary.eof()){
			getline(temporary,tempLine);
			file << tempLine << endl;
		}
		file.close();
		temporary.close();
		remove(TEMP.c_str);
	}
	else{
		temporary.close();
		remove(TEMP.c_str);
	}
}











