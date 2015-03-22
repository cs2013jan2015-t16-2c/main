#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Task
{
public:
	//vector<string> task;
	Task();
	Task(string input);
	Task(string task, string input);
	~Task();
	string ToString();
	string getTaskname();
	void UpdateTask(string input);
	void markAsDone();
	void markAsUndone();
	bool isSame(Task input);
	//void checkInputValidation();
	
private:
	string taskname;
	string task_type;
	string start_time;
	string end_time;
	string deadline_time;
	string scheduled_date;
	string deadline_date;
	string status;
};

#endif