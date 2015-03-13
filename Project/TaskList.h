#ifndef TASKLIST_H_
#define TASKLIST_H_

#include <vector>
#include <string>
#include "Task.h"
#include "Storage.h"
using namespace std;

class TaskList
{
private:
	static vector<Task> list;
	static string lastCommandType;
	static int lastChangedTaskIndex;
	static Task lastUnchangedTask;
	static Task lastChangedTask;

	static string getFirstWord(string input);
	static string removeFirstWord(string input);
	static vector<string> splitText(string text);
	static string printVector(vector<string> output);

public:
	static void copyFromStorage();
	static void copyToStorage();

	static string addTask(string input);
	static string updateTask(string input);
	static string deleteTask(string input);
	static string search(string input);
	static string display();
	static string markAsDone(string input);
	
	static string undo();
	static string redo();
};

#endif