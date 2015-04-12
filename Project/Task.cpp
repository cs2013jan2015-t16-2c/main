#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
#include <ctime>

using namespace std;
//using namespace eku;

const int TASK_LEN = 256;
const string SCHEDULED_TASK_LABEL = "timed";
const string DEADLINE_TASK_LABEL = "deadline";
const string FLOATING_TASK_LABEL = "floating";
const string PROCESSING_TASK_LABEL = "in progress";
const string FINISHED_TASK_LABEL = "done";
const string INVALID_DATE_MSG = "invalid date, please input a valid one";
const string INVALID_TIME_MSG = "invalid time, please enter a valid one";
const string INVALID_TIME_MSG2 = "invalid time frame, ending time cannot be earlier than starting time, please enter a valid one";

Task::Task(){
	taskname = "";
	task_type = "";
	start_time = "";
	end_time = "";
	deadline_time = "";
	scheduled_start_date = "";
	scheduled_end_date = "";
	deadline_date = "";
	status = "";
	priority = "";
	task_group = "";
	place = "";
}

Task::Task(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");

		std::size_t get_group = input.find("#");
		std::size_t get_place = input.find("@");
		if (timed_task != std::string::npos){
			std::size_t ending_time = input.find("-to");
			task_type = SCHEDULED_TASK_LABEL;
			taskname = input.substr(0, timed_task - 1);

			string timeInfo = input.substr(timed_task, ending_time-timed_task-1);
			string endTimeInfo = input.substr(ending_time);

			std::size_t get_start_date = timeInfo.find("/");
			std::size_t get_end_date = endTimeInfo.find("/");
			if (get_start_date != std::string::npos && get_end_date != std::string::npos){
				scheduled_start_date = timeInfo.substr(get_start_date - 2, 5);
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date != std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = timeInfo.substr(get_start_date - 2, 5);
				scheduled_end_date = scheduled_start_date;
			}
			else if (get_start_date == std::string::npos && get_end_date != std::string::npos){
				scheduled_start_date = getDate(timeInfo);
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date == std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = getDate(timeInfo);
				string temp_end_date = getDate(endTimeInfo);
				if (temp_end_date == getDate(0)){
					scheduled_end_date = scheduled_start_date;
				}
				else{
					scheduled_end_date = temp_end_date;
				}
			}

			std::size_t get_start_time = timeInfo.find(":");
			std::size_t get_end_time = endTimeInfo.find(":");
			if (get_start_time != std::string::npos && get_end_time != std::string::npos){
				start_time = timeInfo.substr(get_start_time - 2, 5);
				end_time = endTimeInfo.substr(get_end_time - 2, 5);
			}
			else if (get_start_time != std::string::npos){
				start_time = timeInfo.substr(get_start_time - 2, 5);
				end_time = "";
			}
			else if (get_end_time != std::string::npos){
				start_time = "";
				end_time = endTimeInfo.substr(get_end_time - 2, 5);
			}
			else{
				start_time = "";
				end_time = "";
			}
			
			deadline_time = "";
			deadline_date = "";
			priority = "";
			status = PROCESSING_TASK_LABEL;
		}
		else if (deadlined_task != std::string::npos){
			task_type = DEADLINE_TASK_LABEL;
			taskname = input.substr(0, deadlined_task - 1);
			
			string timeInfo = input.substr(deadlined_task);
			std::size_t get_date = timeInfo.find("/");
			std::size_t get_time = timeInfo.find(":");

			if (get_date != std::string::npos){
				deadline_date = timeInfo.substr(get_date - 2, 5);
			}
			else{
				deadline_date = getDate(timeInfo);
			}
			
			if (get_time != std::string::npos){
				deadline_time = timeInfo.substr(get_time - 2, 5);
			}
			else{
				deadline_time = "";
			}
			
			start_time = "";
			end_time = "";
			scheduled_start_date = "";
			scheduled_end_date = "";
			priority = "";
			status = PROCESSING_TASK_LABEL;
		}
		else{
			task_type = FLOATING_TASK_LABEL;
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_start_date = "";
			scheduled_end_date = "";
			deadline_date = "";
			priority = "";
			status = PROCESSING_TASK_LABEL;
			if ((get_group != std::string::npos) && (get_place != std::string::npos)){
				taskname = input.substr(0, get_group - 1);
			}
			else if (get_group != std::string::npos){
				taskname = input.substr(0, get_group - 1);
			}
			else if (get_place != std::string::npos){
				taskname = input.substr(0, get_place - 1);
			}
			else{
				taskname = input;
			}			
		}

		//V0.2 add task_gp and places
		//assume at current stage there can be only one places and group added for each task
		if ((get_group != std::string::npos) && (get_place != std::string::npos)){
			task_group = input.substr(get_group + 1, get_place - get_group - 2);
			place = input.substr(get_place + 1);
		}
		else if (get_group != std::string::npos){
			task_group = input.substr(get_group + 1);
			place = "";
		}
		else if (get_place != std::string::npos){
			place = input.substr(get_place + 1);
			task_group = "";
		}
		else{
			place = "";
			task_group = "";
		}
	}
	//checkInputValidation();
}

Task::~Task(){}

Task::Task(string task, string input){
	if (!task.empty()){
		//store status
		std::size_t find_status = task.find(PROCESSING_TASK_LABEL);
		if (find_status != std::string::npos){
			status = PROCESSING_TASK_LABEL;
		}
		else{
			std::size_t find_status = task.find(FINISHED_TASK_LABEL);
			if (find_status != std::string::npos){
				status = FINISHED_TASK_LABEL;
			}
			else{
				status = "";
			}
		}

		std::size_t get_priority = task.find("(");
		std::size_t get_taskname;
		if (get_priority != std::string::npos){
			priority = task.substr(get_priority + 1, 1);
			get_taskname = task.find(")") + 2;
		}
		else{
			priority = "";
			get_taskname = 0;
		}

		std::size_t get_starting_timeInfo = task.find("[");
		std::size_t get_ending_timeInfo = task.find("to", get_starting_timeInfo);
		std::size_t get_group = task.find("#");
		std::size_t get_place = task.find("@");
		
		if (get_starting_timeInfo != std::string::npos){
			taskname = task.substr(get_taskname, get_starting_timeInfo - get_taskname - 1);
			if (get_ending_timeInfo != std::string::npos){
				task_type = SCHEDULED_TASK_LABEL;
				string startTimeInfo = task.substr(get_starting_timeInfo, get_ending_timeInfo - get_starting_timeInfo - 1);
				string endTimeInfo = task.substr(get_ending_timeInfo);
				std::size_t get_start_date = startTimeInfo.find("/");
				scheduled_start_date = startTimeInfo.substr(get_start_date - 2, 5);
				std::size_t get_end_date = endTimeInfo.find("/");
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);

				std::size_t get_start_time = startTimeInfo.find(":");
				std::size_t get_end_time = endTimeInfo.find(":");
				if (get_start_time != std::string::npos && get_end_time != std::string::npos){
					start_time = startTimeInfo.substr(get_start_time - 2, 5);
					end_time = endTimeInfo.substr(get_end_time - 2, 5);
				}
				else if (get_start_time != std::string::npos){
					start_time = startTimeInfo.substr(get_start_time - 2, 5);
					end_time = "";
				}
				else if (get_end_time != std::string::npos){
					start_time = "";
					end_time = endTimeInfo.substr(get_end_time - 2, 5);
				}
				else{
					start_time = "";
					end_time = "";
				}
			}
			else{
				task_type = DEADLINE_TASK_LABEL;
				string timeInfo = task.substr(get_starting_timeInfo);
				std::size_t get_deadline_date = timeInfo.find("/");
				deadline_date = timeInfo.substr(get_deadline_date - 2, 5);

				std::size_t get_deadline_time = timeInfo.find(":");
				if (get_deadline_time != std::string::npos){
					deadline_time = timeInfo.substr(get_deadline_time - 2, 5);
				}
				else{
					deadline_time = "";
				}
			}
		}
		else{
			task_type = FLOATING_TASK_LABEL;
			if ((get_group != std::string::npos) && (get_place != std::string::npos)){
				taskname = task.substr(get_taskname, get_group - get_taskname - 1);
			}
			else if (get_group != std::string::npos){
				taskname = task.substr(get_taskname, get_group - get_taskname - 1);
			}
			else if (get_place != std::string::npos){
				taskname = task.substr(get_taskname, get_place - get_taskname - 1);
			}
			else{
				taskname = task.substr(get_taskname, find_status - get_taskname - 1);
			}
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_start_date = "";
			scheduled_end_date = "";
			deadline_date = "";
		}

		if ((get_group != std::string::npos) && (get_place != std::string::npos)){
			task_group = task.substr(get_group + 1, get_place - get_group - 2);
			place = task.substr(get_place + 1, find_status - get_place - 2);
		}
		else if (get_group != std::string::npos){
			task_group = task.substr(get_group + 1, find_status - get_group - 2);
			place = "";
		}
		else if (get_place != std::string::npos){
			place = task.substr(get_place + 1, find_status - get_place - 2);
			task_group = "";
		}
		else{
			place = "";
			task_group = "";
		}
	}
}

string Task::ToString(){
	char task[TASK_LEN];

	if (priority != ""){
		strcpy_s(task, "(");
		strcat_s(task, priority.c_str());
		strcat_s(task, ") ");
		strcat_s(task, taskname.c_str());
	}
	else{
		strcpy_s(task, taskname.c_str());
	}
		
	if (task_type == DEADLINE_TASK_LABEL){
		strcat_s(task, " [");
		strcat_s(task, deadline_date.c_str());
		if (deadline_time != ""){
			strcat_s(task, " ");
			strcat_s(task, deadline_time.c_str());
		}
		strcat_s(task, "] ");
		if (task_group != ""){
			strcat_s(task, "#");
			strcat_s(task, task_group.c_str());
			strcat_s(task, " ");
		}
		if (place != ""){
			strcat_s(task, "@");
			strcat_s(task, place.c_str());
			strcat_s(task, " ");
		}
	}
	else if (task_type == SCHEDULED_TASK_LABEL){
		strcat_s(task, " [");
		strcat_s(task, scheduled_start_date.c_str());
		if (start_time != ""){
			strcat_s(task, " ");
			strcat_s(task, start_time.c_str());
		}
		strcat_s(task, "] to [");
		strcat_s(task, scheduled_end_date.c_str());
		if (end_time != ""){
			strcat_s(task, " ");
			strcat_s(task, end_time.c_str());
		}
		strcat_s(task, "] ");

		if (task_group != ""){
			strcat_s(task, "#");
			strcat_s(task, task_group.c_str());
			strcat_s(task, " ");
		}
		if (place != ""){
			strcat_s(task, "@");
			strcat_s(task, place.c_str());
			strcat_s(task, " ");
		}
	}
	else if (task_type == FLOATING_TASK_LABEL){
		strcat_s(task, " ");
		if (task_group != ""){
			strcat_s(task, "#");
			strcat_s(task, task_group.c_str());
			strcat_s(task, " ");
		}
		if (place != ""){
			strcat_s(task, "@");
			strcat_s(task, place.c_str());
			strcat_s(task, " ");
		}
	}

	strcat_s(task, status.c_str());

	return task;
}

string Task::getTaskname(){
	return taskname;
}

void Task::UpdateTask(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");

		if (timed_task != std::string::npos){
			task_type = SCHEDULED_TASK_LABEL;
			std::size_t ending_time = input.find("-to");

			string timeInfo = input.substr(timed_task, ending_time - timed_task - 1);
			string endTimeInfo = input.substr(ending_time);

			std::size_t get_start_date = timeInfo.find("/");
			std::size_t get_end_date = endTimeInfo.find("/");
			if (get_start_date != std::string::npos && get_end_date != std::string::npos){
				scheduled_start_date = timeInfo.substr(get_start_date - 2, 5);
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date != std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = timeInfo.substr(get_start_date - 2, 5);
				scheduled_end_date = scheduled_start_date;
			}
			else if (get_start_date == std::string::npos && get_end_date != std::string::npos){
				scheduled_start_date = getDate(timeInfo);
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date == std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = getDate(timeInfo);
				string temp_end_date = getDate(endTimeInfo);
				if (temp_end_date == getDate(0)){
					scheduled_end_date = scheduled_start_date;
				}
				else{
					scheduled_end_date = temp_end_date;
				}
			}

			std::size_t get_start_time = timeInfo.find(":");
			std::size_t get_end_time = endTimeInfo.find(":");
			if (get_start_time != std::string::npos && get_end_time != std::string::npos){
				start_time = timeInfo.substr(get_start_time - 2, 5);
				end_time = endTimeInfo.substr(get_end_time - 2, 5);
			}
			else if (get_start_time != std::string::npos){
				start_time = timeInfo.substr(get_start_time - 2, 5);
				end_time = "";
			}
			else if (get_end_time != std::string::npos){
				start_time = "";
				end_time = endTimeInfo.substr(get_end_time - 2, 5);
			}
			else{
				start_time = "";
				end_time = "";
			}

			deadline_time = "";
			deadline_date = "";
		}
		else if (deadlined_task != std::string::npos){
			task_type = DEADLINE_TASK_LABEL;

			string timeInfo = input.substr(deadlined_task);
			std::size_t get_date = timeInfo.find("/");
			std::size_t get_time = timeInfo.find(":");

			if (get_date != std::string::npos){
				deadline_date = timeInfo.substr(get_date - 2, 5);
			}
			else{
				deadline_date = getDate(timeInfo);
			}

			if (get_time != std::string::npos){
				deadline_time = timeInfo.substr(get_time - 2, 5);
			}
			else{
				deadline_time = "";
			}

			start_time = "";
			end_time = "";
			scheduled_start_date = "";
			scheduled_end_date = "";
		}
	}
	//checkInputValidation();
}

void Task::markAsDone(){
	status = FINISHED_TASK_LABEL;
}

void Task::markAsUndone(){
	status = PROCESSING_TASK_LABEL;
}

void Task::setPriority(string input){
	priority = input;
}

string Task::getPriority(){
	return priority;
}

/*void Task::checkInputValidation(){
	concolinit();
	//check for valid time frame
	bool valid_time = false;
	int start_hour; //deadline task use this to store time
	int start_mins; //deadline task use this to store time
	int end_hour;
	int end_mins;

	//check time frame in scheduled task
	while ((task_type == SCHEDULED_TASK_LABEL) && (!valid_time)){
		std::size_t get_start_time = start_time.find(":");
		std::size_t get_end_time = end_time.find(":");
		start_hour = atoi(start_time.substr(0, get_start_time).c_str());
		start_mins = atoi(start_time.substr(get_start_time + 1, 2).c_str());
		end_hour = atoi(end_time.substr(0, get_end_time).c_str());
		end_mins = atoi(end_time.substr(get_end_time + 1, 2).c_str());
		if ((start_hour >= 0 && start_hour <= 24) && (start_mins >= 0 && start_mins <= 60) && (end_hour >= 0 && end_hour <= 24) && (end_mins >= 0 && end_mins <= 60)){
			if (start_hour < end_hour){
				valid_time = true;
			}
			else{
				cout << red << INVALID_TIME_MSG2 << endl;
				settextcolor(deftextcol);
				cout << "starting time:";
				cin >> start_time;
				cout << "ending time:";
				cin >> end_time;
			}
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << INVALID_TIME_MSG << endl;
			errorlog.close();
			cout << red << INVALID_TIME_MSG << endl;
			settextcolor(deftextcol);
			cout << "starting time:";
			cin >> start_time;
			cout << "ending time:";
			cin >> end_time;
		}
	}

	//check time frame in deadline task
	while ((task_type == DEADLINE_TASK_LABEL) && (!valid_time)){
		std::size_t get_time = deadline_time.find(":");
		start_hour = atoi(deadline_time.substr(0, get_time).c_str());
		start_mins = atoi(deadline_time.substr(get_time + 1, 2).c_str());
		if ((start_hour >= 0 && start_hour <= 24) && (start_mins >= 0 && start_mins <= 60)){
			valid_time = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << INVALID_TIME_MSG << endl;
			errorlog.close();
			cout << red << INVALID_TIME_MSG << endl;
			settextcolor(deftextcol);
			cout << "deadline time:";
			cin >> deadline_time;
		}
	}

	//check for valid date
	bool valid_date = false;
	int month;
	int date;

	//check date for deadline task
	while ((task_type == DEADLINE_TASK_LABEL) && (!valid_date)){
		std::size_t get_date = deadline_date.find("/");
		date = atoi(deadline_date.substr(0, get_date).c_str());
		month = atoi(deadline_date.substr(get_date + 1, 2).c_str());
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << INVALID_DATE_MSG << endl;
			errorlog.close();
			cout << red << INVALID_DATE_MSG << endl;
			settextcolor(deftextcol);
			cin >> deadline_date;
		}
	}

	//check date for schedule task
	while ((task_type == SCHEDULED_TASK_LABEL) && (!valid_date)){
		std::size_t get_date = scheduled_date.find("/");
		date = atoi(scheduled_date.substr(0, get_date).c_str());
		month = atoi(scheduled_date.substr(get_date + 1, 2).c_str());
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << INVALID_DATE_MSG << endl;
			errorlog.close();
			cout << red << INVALID_DATE_MSG << endl;
			settextcolor(deftextcol);
			cin >> scheduled_date;
		}
	}
}*/

int Task::charToASCII(char c){
	return int(c);
}

char Task::ASCIIToChar(int c){
	return char(c);
}

string Task::getTaskType(){
	return task_type;
}

//return true if a is before b
bool Task::isEarlier(const Task b){
	int mon_a; //storing month for a
	int mon_b; // storing month for b
	int date_a; // date for a
	int date_b; // date for b
	int hr_a; // hr for a
	int hr_b; // hr for b
	int min_a; // mins for a
	int min_b; // mins for b
	string type_a = task_type;
	string type_b = b.task_type;

	const string SCHEDULED_TASK_LABEL = "timed";
	const string DEADLINE_TASK_LABEL = "deadline";
	
	//check priority first
	if (priority != "" && b.priority == ""){
		return true;
	}
	else if (priority == "" && b.priority != ""){
		return false;
	}
	else{
		if (priority < b.priority){
			return true;
		}
		else if (priority > b.priority){
			return false;
		}
	}
	
	// floating task rank always at last
	if (type_a == FLOATING_TASK_LABEL && type_b==FLOATING_TASK_LABEL){ 
		if (taskname <= b.taskname){
			return true;
		}
		else{
			return false;
		}
	}
	else if (type_b == FLOATING_TASK_LABEL && type_a != FLOATING_TASK_LABEL){
		return true;
	}
	else if (type_a == FLOATING_TASK_LABEL && type_b != FLOATING_TASK_LABEL){
		return false;
	}

	//check a
	string sortingDate_a;
	string sortingTime_a;
	if (type_a == SCHEDULED_TASK_LABEL){ // for scheduled task, we sort with the starting time
		sortingDate_a = scheduled_start_date;
		sortingTime_a = start_time;
	}
	else if (type_a == DEADLINE_TASK_LABEL){
		sortingDate_a = deadline_date;
		sortingTime_a = deadline_time;
	}
			
	std::size_t get_date_a = sortingDate_a.find("/");
	mon_a = atoi(sortingDate_a.substr(get_date_a + 1, 2).c_str());
	date_a = atoi(sortingDate_a.substr(0, 2).c_str());
	if (sortingTime_a == ""){
		hr_a = 24;
		min_a = 0;
	}
	else{
		std::size_t get_start_time_a = sortingTime_a.find(":");
		hr_a = atoi(sortingTime_a.substr(0, 2).c_str());
		min_a = atoi(sortingTime_a.substr(get_start_time_a + 1, 2).c_str());
	}

	//check b
	string sortingDate_b;
	string sortingTime_b;
	if (type_b == SCHEDULED_TASK_LABEL){ // for scheduled task, we sort with the starting time
		sortingDate_b = b.scheduled_start_date;
		sortingTime_b = b.start_time;
	}
	else if (type_b == DEADLINE_TASK_LABEL){
		sortingDate_b = b.deadline_date;
		sortingTime_b = b.deadline_time;
	}

	std::size_t get_date_b = sortingDate_b.find("/");
	mon_b = atoi(sortingDate_b.substr(get_date_b + 1, 2).c_str());
	date_b = atoi(sortingDate_b.substr(0, 2).c_str());
	if (sortingTime_b == ""){
		hr_b = 24;
		min_b = 0;
	}
	else{
		std::size_t get_start_time_b = sortingTime_b.find(":");
		hr_b = atoi(sortingTime_b.substr(0, 2).c_str());
		min_b = atoi(sortingTime_b.substr(get_start_time_b + 1, 2).c_str());
	}

	//compare a & b
	if (mon_b < mon_a){
		return false;
	}
	else if (mon_b > mon_a){
		return true;
	}
	else {
		if (date_b < date_a){
			return false;
		}
		else if (date_b > date_a){
			return true;
		}
		else{
			if (hr_b < hr_a){
				return false;
			}
			else if (hr_b > hr_a){
				return true;
			}
			else{
				if (min_b < min_a){
					return false;
				}
				else if (mon_b > min_a){
					return true;
				}
				else{
					return true;
				}
			}
		}
	}
}

string Task::getTaskGroup(){
	return task_group;
}

string Task::getPlace(){
	return place;
}

string Task::getDate(){
	if (task_type == SCHEDULED_TASK_LABEL){
		return scheduled_start_date;
	}
	else if (task_type == DEADLINE_TASK_LABEL){
		return deadline_date;
	}
	else{
		return "";
	}
}
bool Task::taskDone(){
	if (status == FINISHED_TASK_LABEL){
		return true;
	}
	return false;
}

int Task::getDay(){
	const int DAY[] = { 0, 1, 2, 3, 4, 5, 6 };
	time_t rawtime;
	tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int wday = timeinfo->tm_wday;
	return DAY[wday];
}

int Task::getDayDiff(string day){
	const string DAY[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	for (int i = 0; i < 7; i++){
		if (day == DAY[i]){
			return i;
		}
	}
}

string Task::getDate(int add){
	time_t rawtime;
	tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int mon = 1 + timeinfo->tm_mon;
	int day = add + timeinfo->tm_mday;
	
	return returnDate(mon, day);
}

string Task::getDate(string input){
	std::size_t get_tmr = input.find("tmr");
	if (get_tmr != std::string::npos){
		return getDate(1);
	}
	std::size_t get_this = input.find("this");
	if (get_this != std::string::npos){
		string day = input.substr(get_this + 5, 3);
		int daydiff = getDayDiff(day) - getDay();
		return getDate(daydiff);
	}
	std::size_t get_next = input.find("next");
	if (get_next != std::string::npos){
		string day = input.substr(get_next + 5, 3);
		int daydiff = getDayDiff(day) - getDay();
		return getDate(daydiff+7);
	}

	if (get_tmr == std::string::npos && get_this == std::string::npos && get_next == std::string::npos){
		return getDate(0);
	}
}

//@author A0113624R
void Task::recurringAdd(string repeat_type){
	if (task_type == SCHEDULED_TASK_LABEL){
		int mon_start = atoi((scheduled_start_date.substr(3, 2)).c_str());
		int day_start = atoi((scheduled_start_date.substr(0, 2)).c_str());
		int mon_end = atoi((scheduled_end_date.substr(3, 2)).c_str());
		int day_end = atoi((scheduled_end_date.substr(0, 2)).c_str());

		if (repeat_type == "day"){
			day_start++;
			day_end++;
		}
		else if (repeat_type == "week"){
			day_start = day_start + 7;
			day_end = day_end + 7;
		}
		else if (repeat_type == "month"){
			mon_start++;
			mon_end++;
		}
		scheduled_start_date = returnDate(mon_start, day_start);
		scheduled_end_date = returnDate(mon_end, day_end);
	}
	else if (task_type == DEADLINE_TASK_LABEL){
		int mon = atoi((deadline_date.substr(3, 2)).c_str());
		int day = atoi((deadline_date.substr(0, 2)).c_str());
		
		if (repeat_type == "day"){
			day++;
		}
		else if (repeat_type == "week"){
			day = day + 7;
		}
		else if (repeat_type == "month"){
			mon++;
		}
		deadline_date = returnDate(mon, day);
	}
}

string Task::returnDate(int month, int day){
	if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12){
		if (day > 30){
			month = month + day / 31;
			day = day % 31 + 1;
		}
	}
	else if (month == 4 || 6 || 9 || 11){
		if (day > 31){
			month = month + day / 32; 
			day = day % 32 + 1;
		}
	}
	else{
		if (day > 28){
			month = month + day / 29; 
			day = day % 29 + 1;
		}
	}

	if (month > 12){
		return "-1";
	}

	ostringstream mon;
	if (month < 10){
		mon << "0" << month;
	}
	else{
		mon << month;
	}
	string month_s = mon.str();

	ostringstream date;
	if (day < 10){
		date << "0" << day;
	}
	else{
		date << day;
	}
	string day_s = date.str();
	return day_s + "/" + month_s;
}

bool Task::checkInputValidation(){
	if (task_type == FLOATING_TASK_LABEL){
		return true;
	}
	else if (task_type == SCHEDULED_TASK_LABEL){
		int mon_s = atoi(scheduled_start_date.substr(3, 2).c_str());
		int day_s = atoi(scheduled_start_date.substr(0, 2).c_str());
		int hour_s = atoi(start_time.substr(0, 2).c_str());
		int min_s = atoi(start_time.substr(3, 2).c_str());

		int mon_e = atoi(scheduled_end_date.substr(3, 2).c_str());
		int day_e = atoi(scheduled_end_date.substr(0, 2).c_str());
		int hour_e = atoi(end_time.substr(0, 2).c_str());
		int min_e = atoi(end_time.substr(3, 2).c_str());

		if (!isWithinLimit(mon_s, day_s, hour_s, min_s) || !isWithinLimit(mon_e, day_e, hour_e, min_e)){
			return false;
		}

		if (mon_s > mon_e){
			return false;
		}
		else if (mon_s == mon_e){
			if (day_s > day_e){
				return false;
			}
			else if (day_s == day_e){
				if (hour_s > hour_e){
					return false;
				}
				else if (hour_s == hour_e){
					if (min_s > min_e){
						return false;
					}
				}
			}
		}
	}
	else{
		int mon = atoi(deadline_date.substr(3, 2).c_str());
		int day = atoi(deadline_date.substr(0, 2).c_str());
		int hour = atoi(deadline_time.substr(0, 2).c_str());
		int min = atoi(deadline_time.substr(3, 2).c_str());

		if (!isWithinLimit(mon, day, hour, min)){
			return false;
		}
	}

	return true;
}

bool Task::isWithinLimit(int month, int day, int hour, int min){
	if (month < 1 || month>12){
		return false;
	}

	if (day < 1 || day>31){
		return false;
	}

	if (hour < 0 || hour >= 24){
		return false;
	}

	if (min < 0 || min >= 60){
		return false;
	}

	return true;
}