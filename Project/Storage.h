#ifndef STORAGE_H_
#define STORAGE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include "TaskList.h"

using namespace std;

class storage{
private:
	static vector<string> task;
	static const string FILENAME;

public:
	static void ending();
	static void starting();
	static vector<string> returnTask();
};

#endif
