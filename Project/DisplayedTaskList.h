#ifndef DISPLAYTASKLIST_H_
#define DISPLAYTASKLIST_H_

#include <vector>
#include "Task.h"
#include "MagicString.h"

class DisplayedTaskList
{
private:
	static vector<Task> displayedTaskList;

public:
	static void addTask(Task input);
	static string display();
	static int returnListSize();
	static Task resturnTask(int index);
	static void emptyList();
	static void sort();
};

#endif