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

	return "Task added"; //change to magic string
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
		output = "Task " + taskIndex + " does not exit"; //change to magic string
		return output;
	}
	else{
		lastCommandType = "update";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list[lastChangedTaskIndex].UpdateTask(taskInfo);

		lastChangedTask = list[lastChangedTaskIndex];
		output = "Task " + taskIndex + " updated"; //change to magic string
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
		output = "Task " + input + " does not exit"; //change to magic string
		return output;
	}
	else{
		lastCommandType = "delete";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list.erase(list.begin() + lastChangedTaskIndex);
		string output = "Task " + input + " deleted"; //change to magic string
		return output;
	}
}

string TaskList::search(string input){
	if (list.empty()){
		return "Task list is empty"; //change to magic string
	}
	else{
		DisplayedTaskList::emptyList();
		for (unsigned int i = 0; i < list.size(); i++){
			string taskName = (list[i]).getTaskname();
			vector<string> contents = splitText(taskName);

			for (unsigned int j = 0; j < contents.size(); j++){
				if (input == contents[j]){
					DisplayedTaskList::addTask(list[i]);
				}
			}
		}

		string output = DisplayedTaskList::display();
		if (output == "-1"){
			return "No task containes the searched word"; //change to magic string
		}
		else{
			return output;
		}
	}
}

string TaskList::display(string displayType){
	DisplayedTaskList::emptyList();
	
	addToDisplayedTaskList(displayType);
	if (DisplayedTaskList::display() == "-1"){
		return "Required task list is empty"; //change to magic string
	}
	else{
		return DisplayedTaskList::display();
	}
}

void TaskList::addToDisplayedTaskList(string displayType){
	if (displayType == "all"){
		for (unsigned int i = 0; i < list.size(); i++){
			DisplayedTaskList::addTask(list[i]);
		}
	}
	else{
		for (unsigned int i = 0; i < list.size(); i++){
			if ((list[i]).getTaskType() == displayType){
				DisplayedTaskList::addTask(list[i]);
			}
		}
	}
}

string TaskList::markAsDone(string input){
	int index;
	istringstream in(input);
	in >> index;

	lastCommandType = "done";
	lastChangedTaskIndex = findTargetedTaskIndex(index);

	list[lastChangedTaskIndex].markAsDone();
	string output = "Task " + input + " marked as done"; //change to magic string
	return output;
}

string TaskList::undo(){
	if (lastCommandType == "add"){
		list.pop_back();
		return "Adding command is undone"; //change to magic string
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		return "Updating command is undone"; //change to magic string
	}
	else if (lastCommandType == "delete"){
		list.insert(list.begin() + lastChangedTaskIndex, lastUnchangedTask);
		return "Deleting command is undone"; //change to magic string
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsUndone();
		return "MarkasDone command is undone"; //change to magic string
	}
	else{
		return "Previous action cannot be undo"; //change to magic string
	}
}

string TaskList::redo(){
	if (lastCommandType == "add"){
		list.push_back(lastChangedTask);
		return "Adding command is redone"; //change to magic string
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastChangedTask;
		return "Updating command is redone"; //change to magic string
	}
	else if (lastCommandType == "delete"){
		list.erase(list.begin() + lastChangedTaskIndex);
		return "Deleting command is redone"; //change to magic string
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsDone();
		return "MarkasDone command is redone"; //change to magic string
	}
	else{
		return "previous action cannot be redo"; //change to magic string
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

void TaskList::empty(){
	while (!list.empty()){
		list.pop_back();
	}
}