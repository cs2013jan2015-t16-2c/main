#include <sstream>
#include <assert.h>
#include "TaskList.h"


vector<Task> TaskList::list;
string TaskList::lastCommandType;
int TaskList::lastChangedTaskIndex;
Task TaskList::lastChangedTask;
Task TaskList::lastUnchangedTask;

void TaskList::copyFromStorage(){
	vector<string> taskList = storage::returnTask();

	for (unsigned int i = 0; i < taskList.size(); i++){
		string task = removeFirstWord(taskList[i]);
		Task newTask(task, "copy");
		list.push_back(newTask);
	}
}

void TaskList::copyToStorage(){
	storage::ending();
}

string TaskList::addTask(string input){	
	lastCommandType = "add";

	Task newTask(input);
	list.push_back(newTask);

	lastChangedTask = newTask;

	return "Task added";
}

string TaskList::updateTask(string input){
	string taskIndex = getFirstWord(input);
	string taskInfo = removeFirstWord(input);

	int index;
	istringstream in(taskIndex);
	in >> index;

	string output;
	int size = DisplayedTaskList::returnListSize();
	if (index > size|| index <= 0){
		output = "Task " + taskIndex + " does not exit";
		return output;
	}
	else{
		lastCommandType = "update";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list[lastChangedTaskIndex].UpdateTask(taskInfo);

		lastChangedTask = list[lastChangedTaskIndex];
		output = "Task " + input + " updated";
		return output;
	}
}

string TaskList::deleteTask(string input){
	int index;
	istringstream in(input);
	in >> index;

	string output;
	int size = DisplayedTaskList::returnListSize();
	if (index > size || index <= 0){
		output = "Task " + input + " does not exit";
		return output;
	}
	else{
		lastCommandType = "delete";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list.erase(list.begin() + lastChangedTaskIndex);
		string output = "Task " + input + " deleted";
		return output;
	}
}

string TaskList::search(string input){
	if (list.empty()){
		return "Task list is empty";
	}
	else{
		vector<string> output;
		for (unsigned int i = 0; i < list.size(); i++){
			string taskName = (list[i]).getTaskname();
			vector<string> contents = splitText(taskName);

			for (unsigned int j = 0; j < contents.size(); j++){
				if (input == contents[j]){
					ostringstream oss;
					oss << i + 1 << "." << list[i].ToString() << endl;
					string taskDisplay = oss.str();
					output.push_back(taskDisplay);
				}
			}
		}

		return printVector(output);
	}
}

string TaskList::display(){
	DisplayedTaskList::emptyList();
	int size = list.size();
	for (int i = 0; i < size; i++){
		DisplayedTaskList::addTask(list[i]);
	}

	if (DisplayedTaskList::display() == "-1"){
		return "TaskList is empty";
	}
	else{
		return DisplayedTaskList::display();
	}
}

string TaskList::markAsDone(string input){
	int index;
	istringstream in(input);
	in >> index;

	lastCommandType = "done";
	lastChangedTaskIndex = findTargetedTaskIndex(index);

	list[lastChangedTaskIndex].markAsDone();
	string output = "Task " + input + " marked as done";
	return output;
}

string TaskList::undo(){
	if (lastCommandType == "add"){
		list.pop_back();
		return "Adding command is undone";
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		return "Updating command is undone";
	}
	else if (lastCommandType == "delete"){
		list.insert(list.begin() + lastChangedTaskIndex, lastUnchangedTask);
		return "Deleting command is undone";
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsUndone();
		return "MarkasDone command is undone";
	}
	else{
		return "Previous action cannot be undo";
	}
}

string TaskList::redo(){
	if (lastCommandType == "add"){
		list.push_back(lastChangedTask);
		return "Adding command is redone";
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastChangedTask;
		return "Updating command is redone";
	}
	else if (lastCommandType == "delete"){
		list.erase(list.begin() + lastChangedTaskIndex);
		return "Deleting command is redone";
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsDone();
		return "MarkasDone command is redone";
	}
	else{
		return "previous action cannot be redo";
	}
}

string TaskList::getFirstWord(string input)
{
	return input.substr(0, input.find(' '));
}

string TaskList::removeFirstWord(string input)
{
	return input.substr(input.find_first_of(" ") + 1);
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
	for (unsigned int i = 0; i < output.size(); i++){
		oss << output[i];
	}
	return oss.str();
}

int TaskList::findTargetedTaskIndex(int displayedIndex){
	int size = list.size();
	for (int i = 0; i < size; i++){
		if (list[i].ToString()==(DisplayedTaskList::resturnTask(displayedIndex)).ToString()){
			return i;
		}
	}
	return -1;
}