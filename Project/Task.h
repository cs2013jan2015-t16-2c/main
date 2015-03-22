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
	void UpdateTask(string input);
	void markAsDone();
	void markAsUndone();
	void checkInputValidation();
	//V0.2
	string getTaskType();
	void setPriority(string input);
	char gerPriority();
	void changePriority(string request);
	int charToASCII(char c);
	char ASCIIToChar(int c);

private:
	string taskname;
	string task_type;
	string start_time;
	string end_time;
	string deadline_time;
	string scheduled_date;
	string deadline_date;
	string status;
	char priority[1];
	string task_group;
	string place;
};

#endif