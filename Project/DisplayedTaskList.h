#ifndef DISPLAYTASKLIST_H_
#define DISPLAYTASKLIST_H_

#include <vector>
#include "Task.h"
#include "MagicString.h"

//@author A0113624R
class DisplayedTaskList
{
private:
	static vector<Task> displayedTaskList;

public:
	static void addTask(Task input);
	static string display();
	static bool isEmpty();
	static int returnListSize();
	static Task resturnTask(int index);
	static void emptyList();
	static void sort();
};
#endif