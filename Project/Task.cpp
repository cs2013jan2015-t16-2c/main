#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
//#include "TaskList.cpp"
//#include "concol.h""
#include "InterfaceOutput.h"

using namespace std;
//using namespace eku;
const int TASK_LEN = 256;

//@Yu Pui Yin A0135141W
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
//@Yu Pui Yin A0135141W
Task::Task(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find(MagicString::LABEL_SCHEDULED_FORMAT_1);
		std::size_t deadlined_task = input.find(MagicString::LABEL_SCHEDULED_FORMAT_3);

		std::size_t get_group = input.find("#");
		std::size_t get_place = input.find("@");
		if (timed_task != std::string::npos){
			std::size_t ending_time = input.find(MagicString::LABEL_SCHEDULED_FORMAT_2);
			task_type = MagicString::LABEL_SCHEDULED_TASK;
			taskname = input.substr(0, timed_task - 1);

			string timeInfo = input.substr(timed_task);
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
			else if (get_start_date != std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = InterfaceOutput::returnTodayDate();
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date == std::string::npos && get_end_date == std::string::npos){
				if (timeInfo != "" && endTimeInfo != ""){
					scheduled_start_date = getDate(timeInfo);
					scheduled_end_date = getDate(endTimeInfo);
				}
				else{
					scheduled_start_date = InterfaceOutput::returnTodayDate();
					scheduled_end_date = scheduled_start_date;
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
			status = MagicString::LABEL_PROCESSING_TASK;
		}
		else if (deadlined_task != std::string::npos){
			task_type = MagicString::LABEL_DEADLINE_TASK;
			taskname = input.substr(0, deadlined_task - 1);
			
			string timeInfo = input.substr(deadlined_task);
			std::size_t get_date = timeInfo.find("/");
			std::size_t get_time = timeInfo.find(":");

			if (get_date != std::string::npos){
				deadline_date = timeInfo.substr(get_date - 2, 5);
			}
			else{
				deadline_date = InterfaceOutput::returnTodayDate();
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
			status = MagicString::LABEL_PROCESSING_TASK;
		}
		else{
			task_type = MagicString::LABEL_FLOATING_TASK;
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_start_date = "";
			scheduled_end_date = "";
			deadline_date = "";
			priority = "";
			status = MagicString::LABEL_PROCESSING_TASK;
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
		//V0.4
		std::size_t repeat = input.find(MagicString::LABEL_SCHEDULED_FORMAT_4);
		if (repeat != std::string::npos){
			//task repeat every day
			int repeat_time = 0;
			string repeat_type = "";
			input = input.substr(repeat + 6);
			std::size_t repeat_format = input.find(MagicString::LABEL_REPEAT_FORMAT_1);
			//repeat every day
			if (repeat_format != std::string::npos){
				repeat_type = MagicString::LABEL_REPEAT_FORMAT_1;
				repeat_time = atoi(input.substr(repeat_format + 3).c_str());
				addRepeatTask(repeat_time, repeat_type);
			}
			else{
			//repeat every month
				std::size_t repeat_format = input.find(MagicString::LABEL_REPEAT_FORMAT_2);
				if (repeat_format != std::string::npos){
					repeat_type = MagicString::LABEL_REPEAT_FORMAT_2;
					repeat_time = atoi(input.substr(repeat_format + 5).c_str());
					addRepeatTask(repeat_time, repeat_type);
				}
				else{
			//repeat every week
					std::size_t repeat_format = input.find(MagicString::LABEL_REPEAT_FORMAT_3);
					if (repeat_format != std::string::npos){
						repeat_type = MagicString::LABEL_REPEAT_FORMAT_3;
						repeat_time = atoi(input.substr(repeat_format + 5).c_str());
						addRepeatTask(repeat_time, repeat_type);
					}
				}
			}
		}
		checkTimeClash();
	}
	//checkInputValidation();
}

Task::~Task(){}

//@Yu Pui Yin A0135141W
Task::Task(string task, string input){
	if (!task.empty()){
		//store status
		std::size_t find_status = task.find(MagicString::LABEL_PROCESSING_TASK);
		if (find_status != std::string::npos){
			status = MagicString::LABEL_PROCESSING_TASK;
		}
		else{
			std::size_t find_status = task.find(MagicString::LABEL_FINISHED_TASK);
			if (find_status != std::string::npos){
				status = MagicString::LABEL_FINISHED_TASK;
			}
			else{
				status = "";
			}
		}

		std::size_t get_priority = task.find("(");
		
		if (get_priority != std::string::npos){
			priority = task.substr(get_priority + 1, 1);
			
		}
		else{
			priority = "";
		}

		std::size_t get_taskname = task.find(")") + 2;
		std::size_t get_starting_timeInfo = task.find("[");
		std::size_t get_ending_timeInfo = task.find("to", get_starting_timeInfo);
		std::size_t get_group = task.find("#");
		std::size_t get_place = task.find("@");
		
		if (get_starting_timeInfo != std::string::npos){
			taskname = task.substr(get_taskname, get_starting_timeInfo - get_taskname - 1);
			if (get_ending_timeInfo != std::string::npos){
				task_type = MagicString::LABEL_SCHEDULED_TASK;
				std::size_t get_start_date = task.find("/", get_starting_timeInfo);
				scheduled_start_date = task.substr(get_start_date - 2, 5);
				std::size_t get_end_date = task.find("/", get_ending_timeInfo);
				scheduled_end_date = task.substr(get_end_date - 2, 5);

				std::size_t get_start_time = task.find(":", get_starting_timeInfo);
				std::size_t get_end_time = task.find(":", get_ending_timeInfo);
				if (get_start_time != std::string::npos && get_end_time != std::string::npos){
					start_time = task.substr(get_start_time - 2, 5);
					end_time = task.substr(get_end_time - 2, 5);
				}
				else if (get_start_time != std::string::npos){
					start_time = task.substr(get_start_time - 2, 5);
					end_time = "";
				}
				else if (get_end_time != std::string::npos){
					start_time = "";
					end_time = task.substr(get_end_time - 2, 5);
				}
				else{
					start_time = "";
					end_time = "";
				}
			}
			else{
				task_type = MagicString::LABEL_DEADLINE_TASK;
				std::size_t get_deadline_date = task.find("/", get_starting_timeInfo);
				deadline_date = task.substr(get_deadline_date - 2, 5);

				std::size_t get_deadline_time = task.find(":", get_starting_timeInfo);
				if (get_deadline_time != std::string::npos){
					deadline_time = task.substr(get_deadline_date - 2, 5);
				}
				else{
					deadline_time = "";
				}
			}
		}
		else{
			task_type = MagicString::LABEL_FLOATING_TASK;
			if ((get_group != std::string::npos) && (get_place != std::string::npos)){
				taskname = task.substr(0, get_group - 1);
			}
			else if (get_group != std::string::npos){
				taskname = task.substr(0, get_group - 1);
			}
			else if (get_place != std::string::npos){
				taskname = task.substr(0, get_place - 1);
			}
			else{
				taskname = task.substr(0, find_status-1);
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
			place = task.substr(get_place + 1);
		}
		else if (get_group != std::string::npos){
			task_group = task.substr(get_group + 1);
			place = "";
		}
		else if (get_place != std::string::npos){
			place = task.substr(get_place + 1);
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
	if (priority == "A" || priority == "B" || priority == "C"){
		strcpy_s(task, "(");
		strcpy_s(task, priority.c_str());
		strcpy_s(task, ") ");
	}

	strcpy_s(task, taskname.c_str());
	if (task_type == MagicString::LABEL_DEADLINE_TASK){
		strcat_s(task, " [");
		strcat_s(task, deadline_date.c_str());
		strcat_s(task, " ");
		if (deadline_time != ""){
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
	else if (task_type == MagicString::LABEL_SCHEDULED_TASK){
		strcat_s(task, " [");
		strcat_s(task, scheduled_start_date.c_str());
		strcat_s(task, " ");
		if (start_time != ""){
			strcat_s(task, start_time.c_str());
		}
		strcat_s(task, "] to [");
		strcat_s(task, scheduled_end_date.c_str());
		strcat_s(task, " ");
		if (end_time != ""){
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
	else if (task_type == MagicString::LABEL_FLOATING_TASK){
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

//@Yu Pui Yin A0135141W
string Task::getTaskname(){
	return taskname;
}

//@Yu Pui Yin A0135141W
void Task::UpdateTask(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find(MagicString::LABEL_SCHEDULED_FORMAT_1);
		std::size_t deadlined_task = input.find(MagicString::LABEL_SCHEDULED_FORMAT_3);

		if (timed_task != std::string::npos){
			std::size_t ending_time = input.find(MagicString::LABEL_SCHEDULED_FORMAT_2);

			task_type = MagicString::LABEL_SCHEDULED_TASK;

			string timeInfo = input.substr(timed_task);
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
			else if (get_start_date != std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = InterfaceOutput::returnTodayDate();
				scheduled_end_date = endTimeInfo.substr(get_end_date - 2, 5);
			}
			else if (get_start_date == std::string::npos && get_end_date == std::string::npos){
				scheduled_start_date = InterfaceOutput::returnTodayDate();
				scheduled_end_date = scheduled_start_date;
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
			task_type = MagicString::LABEL_DEADLINE_TASK;

			string timeInfo = input.substr(deadlined_task);
			std::size_t get_date = timeInfo.find("/");
			std::size_t get_time = timeInfo.find(":");

			if (get_date != std::string::npos){
				deadline_date = timeInfo.substr(get_date - 2, 5);
			}
			else{
				deadline_date = InterfaceOutput::returnTodayDate();
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

//@Yu Pui Yin A0135141W
void Task::markAsDone(){
	status = MagicString::LABEL_FINISHED_TASK;
}

//@Yu Pui Yin A0135141W
void Task::markAsUndone(){
	status = MagicString::LABEL_PROCESSING_TASK;
}

//@Yu Pui Yin A0135141W
void Task::setPriority(string input){
	priority = input;
}

//@Yu Pui Yin A0135141W
string Task::getPriority(){
	return priority;
}

//@Yu Pui Yin A0135141W
/*void Task::checkInputValidation(){
	concolinit();
	//check for valid time frame
	bool valid_time = false;
	int start_hour; //deadline task use this to store time
	int start_mins; //deadline task use this to store time
	int end_hour;
	int end_mins;

	//check time frame in scheduled task
	while ((task_type == MagicString::LABEL_SCHEDULED_TASK) && (!valid_time)){
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
				cout << red << MagicString::MESSAGE2_INVALID_TIME << endl;
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
			errorlog << MagicString::MESSAGE_INVALID_TIME << endl;
			errorlog.close();
			cout << red << MagicString::MESSAGE_INVALID_TIME << endl;
			settextcolor(deftextcol);
			cout << "starting time:";
			cin >> start_time;
			cout << "ending time:";
			cin >> end_time;
		}
	}

	//check time frame in deadline task
	while ((task_type == MagicString::LABEL_DEADLINE_TASK) && (!valid_time)){
		std::size_t get_time = deadline_time.find(":");
		start_hour = atoi(deadline_time.substr(0, get_time).c_str());
		start_mins = atoi(deadline_time.substr(get_time + 1, 2).c_str());
		if ((start_hour >= 0 && start_hour <= 24) && (start_mins >= 0 && start_mins <= 60)){
			valid_time = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << MagicString::MESSAGE_INVALID_TIME << endl;
			errorlog.close();
			cout << red << MagicString::MESSAGE_INVALID_TIME << endl;
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
	while ((task_type == MagicString::LABEL_DEADLINE_TASK) && (!valid_date)){
		std::size_t get_date = deadline_date.find("/");
		date = atoi(deadline_date.substr(0, get_date).c_str());
		month = atoi(deadline_date.substr(get_date + 1, 2).c_str());
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << MagicString::MESSAGE_INVALID_DATE << endl;
			errorlog.close();
			cout << red << MagicString::MESSAGE_INVALID_DATE << endl;
			settextcolor(deftextcol);
			cin >> deadline_date;
		}
	}

	//check date for schedule task
	while ((task_type == MagicString::LABEL_SCHEDULED_TASK) && (!valid_date)){
		std::size_t get_date = scheduled_date.find("/");
		date = atoi(scheduled_date.substr(0, get_date).c_str());
		month = atoi(scheduled_date.substr(get_date + 1, 2).c_str());
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			ofstream errorlog;
			errorlog.open("errorlog.txt");
			errorlog << MagicString::MESSAGE_INVALID_DATE << endl;
			errorlog.close();
			cout << red << MagicString::MESSAGE_INVALID_DATE << endl;
			settextcolor(deftextcol);
			cin >> scheduled_date;
		}
	}
}*/

//@Yu Pui Yin A0135141W
int Task::charToASCII(char c){
	return int(c);
}

//@Yu Pui Yin A0135141W
char Task::ASCIIToChar(int c){
	return char(c);
}

//@Yu Pui Yin A0135141W
string Task::getTaskType(){
	return task_type;
}

//@Yu Pui Yin A0135141W
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
		
	//check priority first
	if (priority > b.priority){
		return true;
	}
	else if (priority < b.priority){
		return false;
	}

	// floating task rank always at last
	if (type_a == MagicString::LABEL_FLOATING_TASK && type_b==MagicString::LABEL_FLOATING_TASK){ 
		if (taskname <= b.taskname){
			return true;
		}
		else{
			return false;
		}
	}
	else if (type_b == MagicString::LABEL_FLOATING_TASK && type_a != MagicString::LABEL_FLOATING_TASK){
		return true;
	}
	else if (type_a == MagicString::LABEL_FLOATING_TASK && type_b != MagicString::LABEL_FLOATING_TASK){
		return false;
	}

	//check a
	string sortingDate_a;
	string sortingTime_a;
	if (type_a == MagicString::LABEL_SCHEDULED_TASK){ // for scheduled task, we sort with the starting time
		sortingDate_a = scheduled_start_date;
		sortingTime_a = start_time;
	}
	else if (type_a == MagicString::LABEL_DEADLINE_TASK){
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
	if (type_b == MagicString::LABEL_SCHEDULED_TASK){ // for scheduled task, we sort with the starting time
		sortingDate_b = b.scheduled_start_date;
		sortingTime_b = b.start_time;
	}
	else if (type_b == MagicString::LABEL_DEADLINE_TASK){
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

//@Yu Pui Yin A0135141W
string Task::getTaskGroup(){
	return task_group;
}

//@Yu Pui Yin A0135141W
string Task::getPlace(){
	return place;
}

//@Yu Pui Yin A0135141W
bool Task::taskDone(){
	if (status == MagicString::LABEL_FINISHED_TASK){
		return true;
	}
	return false;
}

//@Yu Pui Yin A0135141W
int Task::getDay(){
	time_t rawtime;
	tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int wday = timeinfo->tm_wday;
	return MagicString::DAY[wday];
}

//@Yu Pui Yin A0135141W
int Task::getDayDiff(string day){
	for (int i = 0; i < 7; i++){
		if (day == MagicString::DAY_S[i]){
			return i;
		}
	}
}

//@Yu Pui Yin A0135141W
string Task::getDate(int add){
	{
		time_t rawtime;
		tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		int mon = 1 + timeinfo->tm_mon;
		int day = add + timeinfo->tm_mday;
		string mon_s = to_string(mon);
		string day_s = to_string(day);
		return day_s + "/" + mon_s;

	}
}

//@Yu Pui Yin A0135141W
string Task::getDate(string input){
	std::size_t getdate = input.find("today");
	if (getdate != std::string::npos){
		return getDate(0);
	}
	getdate = input.find("tmr");
	if (getdate != std::string::npos){
		return getDate(1);
	}
	getdate = input.find("this");
	if (getdate != std::string::npos){
		string day = input.substr(getdate+5,3);
		int daydiff = getDayDiff(day) - getDay();
		return getDate(daydiff);
	}
	getdate = input.find("next");
	if (getdate != std::string::npos){
		string day = input.substr(getdate + 5, 3);
		int daydiff = getDayDiff(day) - getDay();
		return getDate(daydiff+7);
	}
}

//@Yu Pui Yin A0135141W
void Task::addRepeatTask(int repeat_time, string repeat_type){
	string add_task;
	if (repeat_type == MagicString::LABEL_REPEAT_FORMAT_1){
		for (int i = 0; i < repeat_time - 1 ; i++){
			string input = taskname + " " + MagicString::LABEL_SCHEDULED_FORMAT_1 + " " + start_time + " " + addDay(scheduled_start_date, 1 + i) + " " + MagicString::LABEL_SCHEDULED_FORMAT_2 + " " + end_time + " " + addDay(scheduled_end_date, 1 + i);
			TaskList::addTask(input);
		}
	}
	else if (repeat_type == MagicString::LABEL_REPEAT_FORMAT_2){
		for (int i = 1; i <= repeat_time - 1; i++){
			string input = taskname + " " + MagicString::LABEL_SCHEDULED_FORMAT_1 + " " + start_time + " " + addDay(scheduled_start_date, 30 * i) + " " + MagicString::LABEL_SCHEDULED_FORMAT_2 + " " + end_time + " " + addDay(scheduled_end_date, 30 * i);
			TaskList::addTask(input);
		}
	}
	else if (repeat_type == MagicString::LABEL_REPEAT_FORMAT_3){
		for (int i = 1; i <= repeat_time - 1; i++){
			string input = taskname + " " + MagicString::LABEL_SCHEDULED_FORMAT_1 + " " + start_time + " " + addDay(scheduled_start_date, 7 * i) + " " + MagicString::LABEL_SCHEDULED_FORMAT_2 + " " + end_time + " " + addDay(scheduled_end_date, 7 * i);
			TaskList::addTask(input);
		}
	}
}

//@Yu Pui Yin A0135141W
string Task::addDay(string date, int day){
	std::size_t getdate = date.find("/");
	int mon = atoi(date.substr(getdate + 1).c_str());
	int mday = atoi(date.substr(0, getdate).c_str());
	int y = 2015, m = mon, d = mday;

	std::tm t = {};
	t.tm_year = y - 1900;
	t.tm_mon = m - 1;
	t.tm_mday = d;
	// modify
	if (day % 30 == 0){
		t.tm_mon += (day/30) - 1;
	}
	else{
		t.tm_mday += day;
	}
	std::mktime(&t);
	// show result
	mon = 1 + t.tm_mon;
	mday = t.tm_mday;
	string mon_s = to_string(mon);
	string day_s = to_string(mday);
	return day_s + "/" + mon_s;
}

//@Yu Pui Yin A0135141W
bool Task::checkTimeClash(){
	if (!TaskList::list.empty()){
		for (int i = 0; i < TaskList::list.size(); i++){
			//for both task_type == timed, check new task starting_time / ending_time inbetween list.starting_time and ending_time
			if ((TaskList::list[i].task_type == MagicString::LABEL_SCHEDULED_TASK) && (task_type == MagicString::LABEL_SCHEDULED_TASK)){
				if ((getTaskSchedule(task_type, 1) < TaskList::list[i].getTaskSchedule(task_type, 1)) && (getTaskSchedule(task_type, 1) > TaskList::list[i].getTaskSchedule(task_type, 0))){
					cout << "clashed with task " << TaskList::list.size() - i << " : " << TaskList::list[i].taskname << endl;
					return true;
				}
				else if((getTaskSchedule(task_type, 0) >= TaskList::list[i].getTaskSchedule(task_type, 0)) && (getTaskSchedule(task_type, 1) <= TaskList::list[i].getTaskSchedule(task_type, 1))){
					cout << "clashed with task " << TaskList::list.size() - i << " : " << TaskList::list[i].taskname << endl;
					return true;
				}
				else if ((getTaskSchedule(task_type, 0) > TaskList::list[i].getTaskSchedule(task_type, 0)) && (getTaskSchedule(task_type, 0) < TaskList::list[i].getTaskSchedule(task_type, 1))){
					cout << "clashed with task " << TaskList::list.size() - i << " : " << TaskList::list[i].taskname << endl;
					return true;
				}
			}
		}
	}
	return false;
}

//@Yu Pui Yin A0135141W
time_t Task::getTaskSchedule(string task_type, int i){ //i = 0 for schedule start date and start time
	time_t taskdate;
	int y, mon, mday, hr, min;
	if (task_type == MagicString::LABEL_SCHEDULED_TASK){
		if (i == 0){
			std::size_t symbol = scheduled_start_date.find("[");
			if (symbol != std::string::npos){
				scheduled_start_date = scheduled_start_date.substr(symbol+1);
			}
			std::size_t getdate = scheduled_start_date.find("/");
			std::size_t gettime = start_time.find(":");
			mon = atoi(scheduled_start_date.substr(getdate + 1).c_str());
			mday = atoi(scheduled_start_date.substr(0, getdate).c_str());
			hr = atoi(start_time.substr(0, gettime).c_str());
			min = atoi(start_time.substr(gettime + 1).c_str());
			y = 2015;
		}
		else{
			std::size_t symbol = scheduled_end_date.find("[");
			if (symbol != std::string::npos){
				scheduled_end_date = scheduled_end_date.substr(symbol+1);
			}
			std::size_t getdate = scheduled_end_date.find("/");
			std::size_t gettime = end_time.find(":");
			mon = atoi(scheduled_end_date.substr(getdate + 1).c_str());
			mday = atoi(scheduled_end_date.substr(0, getdate).c_str());
			hr = atoi(end_time.substr(0, gettime).c_str());
			min = atoi(end_time.substr(gettime + 1).c_str());
			y = 2015;
		}
	}
	else if (task_type == MagicString::LABEL_DEADLINE_TASK){
		std::size_t symbol = deadline_date.find("[");
		if (symbol != std::string::npos){
			deadline_date = deadline_date.substr(symbol+1);
		}
		std::size_t getdate = deadline_date.find("/");
		std::size_t gettime = deadline_time.find(":");
		mon = atoi(deadline_date.substr(getdate + 1).c_str());
		mday = atoi(deadline_date.substr(0, getdate).c_str());
		hr = atoi(deadline_time.substr(0, gettime).c_str());
		min = atoi(deadline_time.substr(gettime + 1).c_str());
		y = 2015;

	}
	struct std::tm * t = {};
	time(&taskdate);
	t = localtime(&taskdate);
	t->tm_year = y - 1900;
	t->tm_mon = mon - 1;
	t->tm_mday = mday;
	t->tm_hour = hr;
	t->tm_min = min;

	taskdate = std::mktime(t);
	//cout << asctime(t) << endl;
	return taskdate;
}
