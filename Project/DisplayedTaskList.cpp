#include "DisplayedTaskList.h"
#include <sstream>

vector<Task> DisplayedTaskList::displayedTaskList;

void DisplayedTaskList::addTask(Task input){
	displayedTaskList.push_back(input);
}

string DisplayedTaskList::display(){
	if (!displayedTaskList.empty()){
		sort();
		ostringstream overallOss;
		for (unsigned int i = 0; i < displayedTaskList.size() - 1; i++){
			ostringstream oss;			
			oss << i + 1 << "." << displayedTaskList[i].ToString() << endl;
			string taskDisplay = oss.str();
			overallOss << taskDisplay;
		}

		int size = displayedTaskList.size();
		overallOss << size << "." << displayedTaskList[size - 1].ToString();;
		return overallOss.str();
	}
	else{
		return "";
	}
}

int DisplayedTaskList::returnListSize(){
	return displayedTaskList.size();
}

Task DisplayedTaskList::resturnTask(int index){
	return displayedTaskList[index-1];
}

void DisplayedTaskList::emptyList(){
	while (!displayedTaskList.empty()){
		displayedTaskList.pop_back();
	}
}

void DisplayedTaskList::sort(){
	int minIndex;
	int size = displayedTaskList.size();
	for (int i = 0; i < size - 1; i++){
		minIndex = i;
		for (int j = i + 1; j < size; j++){
			if ((displayedTaskList[j]).isEarlier(displayedTaskList[minIndex])){
				minIndex = j;
			}
		}

		if (minIndex != i){
			Task temp = displayedTaskList[minIndex];
			displayedTaskList[minIndex] = displayedTaskList[i];
			displayedTaskList[i] = temp;
		}
	}
}