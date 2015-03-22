#include "task.h"

const int TASK_LEN = 256;
const string SCHEDULED_TASK_LABEL = "timed";
const string DEADLINE_TASK_LABEL = "deadline";
const string FLOATING_TASK_LABEL = "floating";
const string PROCESSING_TASK_LABEL = "progressing";
const string FINISHED_TASK_LABEL = "done";
const string INVALID_DATE_MSG = "invalid date, please input a valid one";
const string INVALID_TIME_MSG = "invalid time, please enter a valid one";
const string INVALID_TIME_MSG2 = "invalid time frame, ending time cannot be earlier than starting time, please enter a valid one";

Task::Task(){}

Task::Task(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");
		if (timed_task != std::string::npos){
			std::size_t ending_time = input.find("-to");
			std::size_t get_date = input.find("/");
			task_type = SCHEDULED_TASK_LABEL;
			taskname = input.substr(0, timed_task - 1);
			start_time = input.substr(timed_task + 6, 5);
			end_time = input.substr(ending_time + 4, 5);
			deadline_time = "";
			scheduled_date = input.substr(get_date - 2, 5);
			deadline_date = "";
			status = "progressing";
		}
		else if (deadlined_task != std::string::npos){
			std::size_t get_date = input.find("/");
			task_type = DEADLINE_TASK_LABEL;
			taskname = input.substr(0, deadlined_task - 1);
			start_time = "";
			end_time = "";
			deadline_time = input.substr(deadlined_task + 4, 5);
			scheduled_date = "";
			deadline_date = input.substr(get_date - 2, 5);
			status = "progressing";
		}
		else{
			task_type = FLOATING_TASK_LABEL;
			taskname = input;
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_date = "";
			deadline_date = "";
			status = "progressing";
		}

		//V0.2 add task_gp and places
		//assume at current stage there can be only one places and group added for each task
		std::size_t get_group = input.find("#");
		std::size_t get_place = input.find("@");
		if ((get_group != std::string::npos) && (get_place != std::string::npos)){
			task_group = input.substr(get_group + 2, get_place - 1);
			place = input.substr(get_place + 2);
		}
		else if (get_group != std::string::npos){
			task_group = input.substr(get_group + 2);
		}
		else if (get_place != std::string::npos){
			place = input.substr(get_place + 2);
		}

	}
	checkInputValidation();
}

Task::~Task(){}

Task::Task(string task, string input){
	if (!task.empty()){
		//store status
		std::size_t find_status = task.find("progressing");
		if (find_status != std::string::npos){
			status = "progressing";
		}
		else{
			std::size_t find_status = task.find("done");
			if (find_status != std::string::npos){
				status = "done";
			}
			else{
				status = " ";
			}
		}

		//classify tasks into scheduled, deadlined or floating
		std::size_t find_date = task.find("/");
		string temp_date;
		string temp;	//to store remaining part of the task arguement to check whether there is a time included there
		if (find_date != std::string::npos){	//date found, task is either scheduled or deadlined.
			//if (task[find_date - 2] == " "){	//check date is in single digit or double
				//taskname = task.substr(0, find_date - 2);
				//temp_date = task.substr(find_date - 1, 4);
			//}
			//else{
				taskname = task.substr(0, find_date - 2);
				temp_date = task.substr(find_date - 2, 5);
			//}
			std::size_t find_time = task.find(":"); 
			temp = task.substr(find_time + 2);
			std::size_t find_ending_time = temp.find(":");	//check if there's an ending time ie. seperate deadlined task and scheduled task
			if ((find_time != std::string::npos) && (find_ending_time != std::string::npos)){
				task_type = SCHEDULED_TASK_LABEL;
				start_time = task.substr(find_time - 2, 5);
				end_time = temp.substr(find_ending_time - 2, 5);
				deadline_time = "";
				scheduled_date = temp_date;
				deadline_date = "";
			}
			else if (find_time != std::string::npos){
				task_type = DEADLINE_TASK_LABEL;
				start_time = "";
				end_time = "";
				deadline_time = task.substr(find_time - 2, 5);
				scheduled_date = "";
				deadline_date = temp_date;
			}

		}
		else{
			task_type = FLOATING_TASK_LABEL;
			taskname = task.substr(0, find_status - 1);
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_date = "";
			deadline_date = "";
		}
	}
	std::size_t get_group = input.find("#");
	std::size_t get_place = input.find("@");
	if ((get_group != std::string::npos) && (get_place != std::string::npos)){
		task_group = input.substr(get_group + 2, get_place - 1);
		place = input.substr(get_place + 2);
	}
	else if (get_group != std::string::npos){
		task_group = input.substr(get_group + 2);
	}
	else if (get_place != std::string::npos){
		place = input.substr(get_place + 2);
	}
	checkInputValidation();
}

string Task::ToString(){
	char task[TASK_LEN];
	strcpy_s(task, taskname.c_str());
	if (task_type == DEADLINE_TASK_LABEL){
		strcat_s(task, " ");
		strcat_s(task, deadline_date.c_str());
		strcat_s(task, " ");
		strcat_s(task, deadline_time.c_str());
		strcat_s(task, " ");
		strcat_s(task, status.c_str());
	}
	else if (task_type == SCHEDULED_TASK_LABEL){
		strcat_s(task, " ");
		strcat_s(task, scheduled_date.c_str());
		strcat_s(task, " ");
		strcat_s(task, start_time.c_str());
		strcat_s(task, " ");
		strcat_s(task, end_time.c_str());
		strcat_s(task, " ");
		strcat_s(task, status.c_str());
	}
	else if (task_type == FLOATING_TASK_LABEL){
		strcat_s(task, " ");
		strcat_s(task, status.c_str());
	}
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
			std::size_t ending_time = input.find("-to");
			std::size_t get_date = input.find("/");
			task_type = SCHEDULED_TASK_LABEL;
			start_time = input.substr(timed_task + 6, 5);
			end_time = input.substr(ending_time + 4, 5);
			if (get_date != std::string::npos){
				scheduled_date = input.substr(get_date - 2, 5);
			}
		}
		else if (deadlined_task != std::string::npos){
			std::size_t get_date = input.find("/");
			task_type = DEADLINE_TASK_LABEL;
			deadline_time = input.substr(deadlined_task + 4, 5);
			if (get_date != std::string::npos){
				deadline_date = input.substr(get_date - 2, 5);
			}
		}
	}
	//checkInputValidation();
}

void Task::markAsDone(){
	status = "done";
}

void Task::markAsUndone(){
	status = "processing";
}

void Task::setPriority(string input){
	string tmp_priority = "";
	std::size_t find_priority = input.find("priority");
	if (find_priority != std::string::npos){
		tmp_priority = input.substr(find_priority + 9, find_priority + 10);
		strncpy_s(priority, tmp_priority.c_str(), 1);
	}
}

char Task::getPriority(){
	return priority[1];
}

void Task::changePriority(string request){
	int temp; //stroe the ASCII value of current priority
	char temp_char[1];
	std::size_t first_priority = request.find("++");
	std::size_t higher_priority = request.find("+");
	std::size_t lower_priority = request.find("-");
	if (first_priority != std::string::npos){
		strncpy_s(priority, "A", 1);
	}
	else if (higher_priority != std::string::npos){
		temp = charToASCII(priority[1]);
		temp--;
		temp_char[1] = ASCIIToChar(temp);
		priority[1] = temp_char[1];
	}
	else if (lower_priority != std::string::npos){
		temp = charToASCII(priority[1]);
		temp++;
		temp_char[1] = ASCIIToChar(temp);
		priority[1] = temp_char[1];
	}
}

void Task::checkInputValidation(){
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
				cout << INVALID_TIME_MSG2 << endl;
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
			cout << INVALID_TIME_MSG << endl;
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
			cout << INVALID_TIME_MSG << endl;
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
			cout << INVALID_DATE_MSG << endl;
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
			cout << INVALID_DATE_MSG << endl;
			cin >> scheduled_date;
		}
	}
}

int Task::charToASCII(char c){
	return int(c);
}

char Task::ASCIIToChar(int c){
	return char(c);
}

string Task::getTaskType(){
	return task_type;
}

bool Task::operator <(const Task &b){
	int temp; //storing month, date, hr or min that was currently comparing
	int temp_b; // storing information for b
	string type_a;
	string type_b;
	std::size_t get_date = deadline_date.find("/");
	std::size_t get_date_b = b.deadline_date.find("/");
	if (( get_date  == std::string::npos ) && ( get_date_b  == std::string::npos )){
		return true;
	}else if( get_date_b  == std::string::npos ){
		return false;
	}
	if (get_date != std::string::npos){
		//check month
		temp = atoi(deadline_date.substr(get_date + 1, 2).c_str());
		temp_b = atoi(b.deadline_date.substr(get_date_b + 1, 2).c_str());
		if ( temp_b < temp ){
			return false;
		}
		//check date
		temp = atoi(deadline_date.substr(0, get_date).c_str());
		temp_b = atoi(b.deadline_date.substr(0, get_date_b).c_str());
		if ( temp_b < temp ){
			return false;
		}

		std::size_t get_start_time = start_time.find(":");
		std::size_t get_start_time_b = b.start_time.find(":");

		if (( get_start_time  == std::string::npos ) && ( get_start_time_b  == std::string::npos )){
			return true;
		}else if( get_start_time_b  == std::string::npos ){
			return false;
		}
		if (get_start_time != std::string::npos){
			//check hr
			temp = atoi(start_time.substr(0, get_start_time).c_str());
			temp_b = atoi(b.start_time.substr(0, get_start_time_b).c_str());
			if ( temp_b < temp ){
				return false;
			}
			//check mins
			temp = atoi(start_time.substr(get_start_time + 1, 2).c_str());
			temp_b = atoi(b.start_time.substr(get_start_time_b + 1, 2).c_str());
			if ( temp_b < temp ){
				return false;
			}
		}
	}
	return true;
	
}
