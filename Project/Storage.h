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
	static const string TEMP;
	static const string DONE;
	static const string PROGRESS;

public:
	static string starting();
	static void ending();
	static string deletePer();
	static vector<string> returnTask();
	static string saveDone();
	static string saveProgress();
	static string archive(string fileName);
	static string archiveDelete(string location);
	static void checkRubbish();
	static void tempFile();
	static void deleteTemp();
	static void backup();
	static void logging(string input, string fileName);
	static const string LOGFILE;
	static string logTime();
};

#endif