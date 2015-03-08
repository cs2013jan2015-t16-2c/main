#ifndef STORAGE_H_
#define STORAGE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

class storage{
private:
	vector<string> task;
	string fileName;
public:
	void ending(TaskList,string);
	void starting(vector<string>,string);
	vector<string> returnTask(TaskList);
};

#endif
