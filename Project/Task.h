#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Task
{
public:
	Task();
	Task(string input); // for basic input fomat e.g. add hw1 -from 12:00 -to 13:00 13/3
	~Task();
	Task(string task, string input); // for advance format e.g. hw1 13/3 12:00 13:00
	string ToString();
	string getTaskname();
	string getTaskGroup();
	string getPlace();
	void UpdateTask(string input);
	void markAsDone();
	void markAsUndone();
	void checkInputValidation();
	//V0.2
	string getTaskType();
	void setPriority(string input);
	string getPriority();
	//void changePriority(string request);
	int charToASCII(char c);
	char ASCIIToChar(int c);
	//operator
	bool isEarlier(const Task b);
	//V0.3
	bool taskDone(); // return true if task status is done
	string getTodayDate();
	

private:
	string taskname;
	string task_type;
	string start_time;
	string end_time;
	string deadline_time;
	string scheduled_start_date;
	string scheduled_end_date;
	string deadline_date;
	string status;
	string priority;
	string task_group;
	string place;
	//V0.4
	int getDay();
	string getDate(string input);
	string getDate(int add);
	int getDayDiff(string day);
	void addRepeatTask(int repeat_time, string repeat_type);
};

#endif
