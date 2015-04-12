#include <sstream>
#include <assert.h>
#include "TaskList.h"
#include "MagicString.h"

vector<Task> TaskList::list;
vector<string> TaskList::taskGroup;
vector<string> TaskList::taskPlace;
bool TaskList::isLastCommandUndo = false;
string TaskList::lastCommandType;
int TaskList::lastChangedTaskIndex;
Task TaskList::lastChangedTask;
Task TaskList::lastUnchangedTask;

//@author A0113624R
void TaskList::copyFromStorage(){
	vector<string> taskList = storage::returnTask();

	for (unsigned int i = 0; i < taskList.size(); i++){
		string task = removeFirstWord(taskList[i]);
		Task newTask(task, "copy");

		list.push_back(newTask);
		addTaskGroup(newTask);
		addPlace(newTask);
	}
}

void TaskList::copyToStorage(){
	storage::deleteTemp();
	storage::ending();
}

string TaskList::addTask(string input){
	std::size_t repeat = input.find("-every");
	if (repeat != std::string::npos){
		string taskInfo = input.substr(0, repeat - 1);
		Task newTask(taskInfo);
		if (newTask.checkInputValidation()){
			if (newTask.getTaskType() == "floating"){
				return MagicString::FLOATING_CANNOT_RECUR;
			}
			else{
				string repeatInfo = input.substr(repeat + 6);
				string repeat_type = getFirstWord(repeatInfo);
				int repeat_time = atoi((removeFirstWord(repeatInfo)).c_str());
				addRepeatTask(taskInfo, repeat_type, repeat_time);
				storage::tempFile();
				return MagicString::RECURRING_TASK_ADDED;
			}
		}
		else{
			return MagicString::INVALID_TIME_INPUT;
		}
		
	}
	else{
		Task newTask(input);
		if (newTask.checkInputValidation()){
			list.push_back(newTask);
			lastCommandType = "add";
			lastChangedTask = newTask;

			addTaskGroup(newTask);
			addPlace(newTask);
			storage::tempFile();
			return MagicString::TASK_ADDED;
		}
		else{
			return MagicString::INVALID_TIME_INPUT;
		}
	}
}

void TaskList::addRepeatTask(Task newTask, string repeat_type, int repeat_time){
	Task *newPtr = new Task;
	*newPtr = newTask;
	list.push_back(*newPtr);

	for (int i = 1; i < repeat_time; i++){
		Task *ptr = new Task;
		newTask.recurringAdd(repeat_type);
		*ptr = newTask;
		if ((*ptr).getDate() != "-1"){
			list.push_back(*ptr);
		}
		else{
			break;
		}
	}
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
		output = MagicString::TASK + taskIndex + MagicString::NON_EXISTENCE;
		return output;
	}
	else{
		int listIndex = findTargetedTaskIndex(index);
		Task temp = list[listIndex];
		list[listIndex].UpdateTask(taskInfo);

		if (list[listIndex].checkInputValidation()){
			lastCommandType = "update";
			lastChangedTaskIndex = listIndex;
			lastUnchangedTask = temp;
			lastChangedTask = list[lastChangedTaskIndex];
			output = MagicString::TASK + taskIndex + MagicString::UPDATE;
		}
		else{
			list[lastChangedTaskIndex] = temp;
			output = MagicString::INVALID_TIME_INPUT;		
		}
		
		storage::tempFile();
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
		output = MagicString::TASK + input + MagicString::NON_EXISTENCE; 
		return output;
	}
	else{
		lastCommandType = "delete";
		lastChangedTaskIndex = findTargetedTaskIndex(index);
		lastUnchangedTask = list[lastChangedTaskIndex];

		list.erase(list.begin() + lastChangedTaskIndex);
		string output = MagicString::TASK + input + MagicString::DELETE; 

		storage::tempFile();
		return output;
	}
}

string TaskList::search(string input){
	if (list.empty()){
		return MagicString::TASK_EMPTY; 
	}
	else{
		DisplayedTaskList::emptyList();
		for (unsigned int i = 0; i < list.size(); i++){
			string taskName = (list[i]).getTaskname();
			vector<string> contents = splitText(taskName);

			for (unsigned int j = 0; j < contents.size(); j++){
				if (input == contents[j]){
					DisplayedTaskList::addTask(list[i]);
					break;
				}
			}
		}
		
		if (DisplayedTaskList::isEmpty()){
			return MagicString::SEARCH_NOT_FOUND;
		}
		else{
			string output = DisplayedTaskList::display();
			return output;
		}
	}
}

string TaskList::display(string displayType){
	DisplayedTaskList::emptyList();
	
	if (addToDisplayedTaskList(displayType) == MagicString::INVALID_DISPLAY){
		return MagicString::INVALID_DISPLAY;
	}
	else if (DisplayedTaskList::isEmpty()){
		return MagicString::TASK_EMPTY2;
	}
	else{
		return DisplayedTaskList::display();
	}
}

string TaskList::addToDisplayedTaskList(string displayType){
	size_t findTimeBy = displayType.find("-by");
	if (displayType == "all"){
		for (unsigned int i = 0; i < list.size(); i++){
			if (!list[i].taskDone()){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (displayType == "done"){
		for (unsigned int i = 0; i < list.size(); i++){
			if (list[i].taskDone()){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (displayType == "timed" || displayType == "deadline" || displayType == "floating"){
		for (unsigned int i = 0; i < list.size(); i++){
			if ((list[i]).getTaskType() == displayType){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (displayType == "today"){
		for (unsigned int i = 0; i < list.size(); i++){
			if (list[i].getDate() == list[i].getDate(0)){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (isExist(taskGroup, displayType)){
		for (unsigned int i = 0; i < list.size(); i++){
			if ((list[i]).getTaskGroup() == displayType){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (isExist(taskPlace, displayType)){
		for (unsigned int i = 0; i < list.size(); i++){
			if ((list[i]).getPlace() == displayType){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		return "";
	}
	else if (findTimeBy != string::npos){
		size_t displayBy = displayType.find("/", findTimeBy);
		string displayByDate;
		if (displayBy != string::npos){
			displayByDate = displayType.substr(displayBy - 2, 5);
		}
		else{
			Task a;
			string dateInfo = removeFirstWord(displayType);
			displayByDate = a.getDate(dateInfo);
		}

		for (unsigned int i = 0; i < list.size(); i++){
			string taskDate = list[i].getDate();
			if (isEariler(taskDate, displayByDate)){
				DisplayedTaskList::addTask(list[i]);
			}
		}
		
		return "";
	}
	else{
		return MagicString::INVALID_DISPLAY;
	}
}

string TaskList::markAsDone(string input){
	int index;
	istringstream in(input);
	in >> index;

	string output;
	int size = DisplayedTaskList::returnListSize();
	if (index > size || index <= 0){
		output = MagicString::TASK + input + MagicString::NON_EXISTENCE;
		return output;
	}
	else{
		lastCommandType = "done";
		lastChangedTaskIndex = findTargetedTaskIndex(index);

		list[lastChangedTaskIndex].markAsDone();
		string output = MagicString::TASK + input + MagicString::MARK_AS_DONE;

		storage::tempFile();
		return output;
	}	
}

string TaskList::setPriority(string input){
	string taskIndex = getFirstWord(input);
	string taskInfo = removeFirstWord(input);

	int index;
	istringstream in(taskIndex);
	in >> index;

	string output;
	int size = DisplayedTaskList::returnListSize();
	if (index > size || index <= 0){
		output = MagicString::TASK + input + MagicString::NON_EXISTENCE;
		return output;
	}
	else{
		if (taskInfo == "A" || taskInfo == "B" || taskInfo == "C"){
			lastCommandType = "setPriority";
			lastChangedTaskIndex = findTargetedTaskIndex(index);
			lastUnchangedTask = list[lastChangedTaskIndex];

			list[lastChangedTaskIndex].setPriority(taskInfo);

			lastChangedTask = list[lastChangedTaskIndex];
			output = MagicString::TASK + taskIndex + MagicString::SET_PRIORITY; 

			storage::tempFile();
			return output;
		}
		else{
			return "Invalid priority type";
		}
		
	}	
}

string TaskList::undo(){
	if (lastCommandType == "add"){
		list.pop_back();
		isLastCommandUndo = true;
		storage::tempFile();
		return MagicString::ADD_UNDO;
	}
	else if (lastCommandType == "update"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		isLastCommandUndo = true;
		storage::tempFile();
		return MagicString::UPDATE_UNDO;
	}
	else if (lastCommandType == "delete"){
		list.insert(list.begin() + lastChangedTaskIndex, lastUnchangedTask);
		isLastCommandUndo = true;
		storage::tempFile();
		return MagicString::DELETE_UNDO;
	}
	else if (lastCommandType == "done"){
		list[lastChangedTaskIndex].markAsUndone();
		isLastCommandUndo = true;
		storage::tempFile();
		return MagicString::MARK_UNDO;
	}
	else if (lastCommandType == "setPriority"){
		list[lastChangedTaskIndex] = lastUnchangedTask;
		isLastCommandUndo = true;
		storage::tempFile();
		return MagicString::PRIORITY_UNDO;
	}
	else{
		return MagicString::UNDO_UNABLE;
	}
}

string TaskList::redo(){
	if (isLastCommandUndo){
		isLastCommandUndo = false;
		if (lastCommandType == "add"){
			list.push_back(lastChangedTask);
			storage::tempFile();
			return MagicString::ADD_REDO;
		}
		else if (lastCommandType == "update"){
			list[lastChangedTaskIndex] = lastChangedTask;
			storage::tempFile();
			return MagicString::UPDATE_REDO;
		}
		else if (lastCommandType == "delete"){
			list.erase(list.begin() + lastChangedTaskIndex);
			storage::tempFile();
			return MagicString::DELETE_REDO;
		}
		else if (lastCommandType == "done"){
			list[lastChangedTaskIndex].markAsDone();
			storage::tempFile();
			return MagicString::MARK_REDO;
		}
		else{
			list[lastChangedTaskIndex] = lastChangedTask;
			storage::tempFile();
			return MagicString::PRIORITY_REDO;
		}
	}
	else{
		return MagicString::REDO_UNABLE;
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

void TaskList::addTaskGroup(Task newTask){
	string group = newTask.getTaskGroup();
	if (group != ""){
		if (!isExist(taskGroup, group)){
			taskGroup.push_back(group);
		}
	}
}

void TaskList::addPlace(Task newTask){
	string place = newTask.getPlace();
	if (place != ""){
		if (!isExist(taskPlace, place)){
			taskPlace.push_back(place);
		}
	}
}

bool TaskList::isExist(vector<string> list, string input){
	if (list.empty()){
		return false;
	}
	
	for (unsigned int i = 0; i < list.size(); i++){
		if (input == list[i]){
			return true;
		}
	}

	return false;
}

bool TaskList::isEariler(string taskDate, string displayByDate){
	int month_by = atoi(displayByDate.substr(3, 2).c_str());
	int day_by = atoi(displayByDate.substr(0, 2).c_str());

	int month_task = atoi(taskDate.substr(3, 2).c_str());
	int day_task = atoi(taskDate.substr(0, 2).c_str());

	if (month_task < month_by){
		return true;
	}
	else if (month_task > month_by){
		return false;
	}
	else{
		if (day_task <= day_by){
			return true;
		}
		else{
			return false;
		}
	}
}