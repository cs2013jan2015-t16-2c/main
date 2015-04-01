#include <sstream>
#include <assert.h>
#include "TaskList.h"
#include "MagicString"

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

	return MagicString::TASK_ADDED; //change to magic string
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
		output = MagicString::TASK + taskIndex + MagicString::NON_EXISTENCE; //change to magic string
		return output;
	}
	else{
		lastCommandType = "update";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list[lastChangedTaskIndex].UpdateTask(taskInfo);

		lastChangedTask = list[lastChangedTaskIndex];
		output = MagicString::TASK + taskIndex + MagicString::UPDATE; //change to magic string
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
		output = MagicString::TASK  + input + MagicString::NON_EXISTENCE; //change to magic string
		return output;
	}
	else{
		lastCommandType = "delete";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list.erase(list.begin() + lastChangedTaskIndex);
		string output = MagicString::TASK + input + MagicString::DELETE; //change to magic string
		return output;
	}
}

string TaskList::search(string input){
	if (list.empty()){
		return MagicString::TASK_EMPTY; //change to magic string
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
			return MagicString::SEARCH_NOT_FOUND; //change to magic string
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
		return MagicString::TASK_EMPTY2; //change to magic string
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
	string output = MagicString::TASK + input + MagicString::MARK_AS_DONE; //change to magic string
	return output;
}

string TaskList::undo(){
	if (lastCommandType == "add"){
		list.pop_back();
		return MagicString::ADD_UNDO; //change to magic string
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		return MagicString::UPDATE_UNDO; //change to magic string
	}
	else if (lastCommandType == "delete"){
		list.insert(list.begin() + lastChangedTaskIndex, lastUnchangedTask);
		return MagicString::DELETE_UNDO; //change to magic string
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsUndone();
		return MagicString::MARK_UNDO; //change to magic string
	}
	else{
		return MagicString::UNDO_INABLE; //change to magic string
	}
}

string TaskList::redo(){
	if (lastCommandType == "add"){
		list.push_back(lastChangedTask);
		return MagicString::ADD_REDO; //change to magic string
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastChangedTask;
		return MagicString::UPDATE_REDO; //change to magic string
	}
	else if (lastCommandType == "delete"){
		list.erase(list.begin() + lastChangedTaskIndex);
		return MagicString::DELETE_REDO; //change to magic string
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsDone();
		return MagicString::MARK_REDO; //change to magic string
	}
	else{
		return MagicString::REDO_INABLE; //change to magic string
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