#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <string>
using namespace std;

class Task
{
public:
	//vector<string> task;
	Task(string input);
	~Task();
	Task(string task, string input);
	string ToString();
	string getTaskname();
	string UpdateTask(string input);
	void markAsDone();
	void markAsUndone();
	void checkInputValidation();
	
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
