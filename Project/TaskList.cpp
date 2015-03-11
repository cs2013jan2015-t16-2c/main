#include <sstream>
#include "TaskList.h"

string TaskList::addTask(string input){
	lastCommandType = "add";

	Task newTask(input);
	list.push_back(newTask);
	string output = "Task added";

	lastChangedTask = newTask;

	return output;
}

string TaskList::updateTask(string input){
	string taskIndex = getFirstWord(input);
	string taskInfo = removeFirstWord(input);

	int index;
	istringstream in(taskIndex);
	in >> index;

	string output;
	if (index > list.size() || index <= 0){
		output = "Task " + taskIndex + " does not exit";
		return output;
	}
	else{
		lastCommandType = "update";
		lastChangedTaskIndex = index - 1;
		lastUnchangedTask = list[index - 1];

		list[index-1].update(taskInfo);

		lastChangedTask = list[index - 1];

		output = "Task " + taskIndex + " updated";
		return output;
	}
}

string TaskList::deleteTask(string input){
	int index;
	istringstream in(input);
	in >> index;

	string output;
	if (index > list.size() || index <= 0){
		output = "Task " + input + " does not exit";
		return output;
	}
	else{
		lastCommandType = "delete";
		lastChangedTaskIndex = index;
		lastUnchangedTask = list[index - 1];

		list.erase(list.begin() + index - 1);
		string output = "Task " + input + " deleted";
		return output;
	}
}

string TaskList::search(string input){	
	if (list.empty()){
		return "Task list is empty";
	}
	else{
		lastCommandType = "search";

		vector<string> output;
		for (int i = 0; i < list.size(); i++){
			string taskName = (list[i]).getTaskName();
			vector<string> contents = splitText(taskName);

			for (int j = 0; j < contents.size(); j++){
				if (input == contents[j]){
					ostringstream oss;
					oss << i + 1 << "." << list[i].toString() << endl;
					string taskDisplay = oss.str();
					output.push_back(taskDisplay);
				}
			}
		}

		return printVector(output);
	}
}

string TaskList::display(){
	if (list.empty()){
		return "Task list is empty";
	}
	else{
		lastCommandType = "display";

		ostringstream overallOss;
		for (int i = 0; i < list.size(); i++){
			ostringstream oss;
			oss << i + 1 << "." << list[i].toString() << endl;
			string taskDisplay = oss.str();
			overallOss << taskDisplay;
		}
		return overallOss.str();
	}
}

string TaskList::markAsDone(string input){
	int index;
	istringstream in(input);
	in >> index;

	lastCommandType = "done";
	lastChangedTaskIndex = index;

	list[index].markAsDone;
	string output = "Task " + input + " marked as done";
}

void TaskList::copyFromStorage(Storage startingStorage){
	vector<string> taskList = startingStorage.returnTaskString;

	for (int i = 0; i < taskList.size(); i++){
		Task newTask(taskList[i]);
		list.push_back(newTask);
	}
}

string TaskList::undo(){
	if (lastCommandType == "display" || "search"){
		return "Previous command cannot be undoed";
	}
	else if (lastCommandType == "add"){
		list.pop_back();
		return "Adding command is undoed";
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		return "Updating command is undoed";
	}
	else if (lastCommandType == "delete"){
		list.insert(list.begin() + lastChangedTaskIndex - 1, lastUnchangedTask);
		return "Deleting command is undoed";
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsUndone();
		return "MarkasDone command is undoed";
	}
}

string TaskList::redo(){
	if (lastCommandType == "display" || "search"){
		return "Previous command has not been undoed";
	}
	else if (lastCommandType == "add"){
		list.push_back(lastChangedTask);
		return "Adding command is redoed";
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastChangedTask;
		return "Updating command is redoed";
	}
	else if (lastCommandType == "delete"){
		list.erase(list.begin() + lastChangedTaskIndex - 1);
		return "Deleting command is redoed";
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsDone();
		return "MarkasDone command is redoed";
	}
}

string TaskList::getFirstWord(string input)
{
	size_t start = input.find_first_not_of(" \f\n\r\t\v");
	size_t end = input.find_first_of(" \f\n\r\t\v");
	string output = input.substr(start, end - start);
	return output;
}

string TaskList::removeFirstWord(string input)
{
	size_t firstspace = input.find_first_of(" \f\n\r\t\v");
	size_t start = input.find_first_not_of(" \f\n\r\t\v", firstspace);
	size_t end = input.find_last_not_of(" \f\n\r\t\v");
	string output = input.substr(start, end + 1 - start);
	return output;
}

vector<string> TaskList::splitText(string text){
	vector<string> words;
	string word;
	istringstream in(text);
	copy(istream_iterator<string>(in),
		istream_iterator<string>(),
		back_inserter<vector<string>>(words));

	return words;
}

string TaskList::printVector(vector<string> output){
	ostringstream oss;
	for (int i = 0; i < output.size(); i++){
		oss << output[i];
	}
	return oss.str();
}

int main(){
	TaskList::addTask("tutorial A 11/03 -from 1400 -to 1600");
	cout << TaskList::display();
}