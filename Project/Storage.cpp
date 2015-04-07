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
	file << content;	

	content = TaskList::display("done");
	
	if(content != MagicString::MESSAGE_EMPTY){
		file << content;
		file.close();
	}
	else{
		file.close();
	}
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
	file << content;

	content = TaskList::display("done");

	if(content != MagicString::MESSAGE_EMPTY){
	file << content;
	}
	file.close();
	
	return MagicString::SUCCESS_ARCHIVE;
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
	temporary << content;	

	content = TaskList::display("done");
	temporary << content;
	
	if (content != MagicString::MESSAGE_EMPTY) {
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











