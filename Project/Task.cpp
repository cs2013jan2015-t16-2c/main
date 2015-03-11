#include "task.h"

const int TASK_LEN = 256;
const string SCHEDULED_TASK_LABEL = "timed";
const string DEADLINE_TASK_LABEL = "deadline";
const string FLOATING_TASK_LABEL = "floating";
const string PROCESSING_TASK_LABEL = "progressing";
const string FINISHED_TASK_LABEL = "done";

Task::Task(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");
		if (timed_task != std::string::npos){
			std::size_t end_time = input.find("-to");
			std::size_t get_date = input.find("/");
			task_type = SCHEDULED_TASK_LABEL;
			taskname = str.copy(input, 0, timed_task - 2);
			start_time = str.copy(input, timed_task + 6, 4);
			end_time = str.copy(input, end_time + 4, 4);
			deadline_time = "";
			scheduled_date = str.copy(input, get_date - 2, get_date + 2);
			deadline_date = "";
			status = "progressing";
		}
		else if (deadlined_task != std::string::npos){
			std::size_t get_date = input.find("/");
			task_type = DEADLINE_TASK_LABEL;
			taskname = str.copy(input, 0, deadlined_task - 2);
			start_time = "";
			end_time = "";
			deadline_time = str.copy(input, deadlined_task + 4, 4);
			scheduled_date = "";
			deadline_date = (input, get_date - 2, get_date + 2);
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
	}
}

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
			if (task[find_date - 2] == " "){	//check date is in single digit or double
				taskname = str.copy(task, 0, find_date - 2);
				temp_date = str.copy(task, find_date - 1, find_date + 2);
			}
			else{
				taskname = str.copy(task, 0, find_date - 3);
				temp_date = str.copy(task, find_date - 2, find_date + 2);
			}
			std::size_t find_time = task.find(":"); 
			temp = str.substr(find_time + 2);
			std::size_t find_ending_time = temp.find(":");	//check if there's an ending time ie. seperate deadlined task and scheduled task
			if ((find_time != std::string::npos) && (find_ending_time != std::string::npos)){
				task_type = SCHEDULED_TASK_LABEL;
				start_time = str.copy(task, find_time - 2, find_time + 2);
				end_time = str.copy(temp, find_ending_time - 2, find_ending_time + 2);
				deadline_time = "";
				scheduled_date = temp_date;
				deadline_date = "";
			}
			else if (find_time != std::string::npos){
				task_type = DEADLINE_TASK_LABEL;
				start_time = "";
				end_time = "";
				deadline_time = str.copy(task, find_time - 2, find_time + 2);
				scheduled_date = "";
				deadline_date = temp_date;
			}

		}
		else{
			task_type = FLOATING_TASK_LABEL;
			taskname = str.copy(task, 0, find_status - 1);
			start_time = "";
			end_time = "";
			deadline_time = "";
			scheduled_date = "";
			deadline_date = "";
		}
	}
}

string Task::ToString(){
	char task[TASK_LEN];
	strcpy(task, taskname);
	if (task_type == DEADLINE_TASK_LABEL){
		strcat(task, " ");
		strcat(task, deadline_date);
		strcat(task, " ");
		strcat(task, deadline_time);
		strcat(task, " ");
		strcat(task, status);
	}
	else if (task_type == "timed"){
		strcat(task, " ");
		strcat(task, scheduled_date);
		strcat(task, " ");
		strcat(task, start_time);
		strcat(task, " ");
		strcat(task, end_time);
		strcat(task, " ");
		strcat(task, status);
	}
	return task;
}

string Task::getTaskname(){
	return taskname;
}

string Task::UpdateTask(){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");
		if (timed_task != std::string::npos){
			std::size_t end_time = input.find("-to");
			std::size_t get_date = input.find("/");
			task_type = SCHEDULED_TASK_LABEL;
			start_time = str.copy(input, timed_task + 6, 4);
			end_time = str.copy(input, end_time + 4, 4);
			if (get_date != std::string::npos){
				scheduled_date = str.copy(input, get_date - 2, get_date + 2);
			}
		}
		else if (deadlined_task != std::string::npos){
			std::size_t get_date = input.find("/");
			task_type = DEADLINE_TASK_LABEL;
			deadline_time = str.copy(input, deadlined_task + 4, 4);
			if (get_date != std::string::npos){
				deadline_date = str.copy(input, get_date - 2, get_date + 2);
			}
		}
	}
}

void Task::markAsDone(){
	status = "done";
}

void Task::markAsUndone(){
	status = "processing";
}

void Task::checkInputValidation(){
	//check for valid time frame
	bool valid_time = false;
	string start_hour; //deadline task use this to store time
	string start_mins; //deadline task use this to store time
	string end_hour;
	string end_mins;

	//check time frame in scheduled task
	while ((task_type == SCHEDULED_TASK_LABEL) && (!valid_time)){
		std::size_t get_start_time = start_time.find(":");
		std::size_t get_end_time = end_time.find(":");
		start_hour = str.copy(start_time, 0, get_start_time - 1);
		start_mins = str.copy(start_time, get_start_time + 1, get_start_time.end());
		end_hour = str.copy(end_time, 0, get_end_time - 1);
		end_mins = str.copy(end_time, get_end_time + 1, end_time.end());
		if ((start_hour >= 0 && start_hour <= 24) && (start_mins >= 0 && start_mins <= 60) && (end_hour >= 0 && end_hour <= 24) && (end_mins >= 0 && end_mins <= 60)){
			if (start_hour < end_hour){
				valid_time = true;
			}
			else{
				cout << "invalid time frame, ending time cannot be earlier than starting time, please enter a valid one" << endl;
				cout << "starting time:";
				cin >> start_time;
				cout << "ending time";
				cin >> end_time;
			}
		}
		else{
			cout << "invalid time, please enter a valid one" << endl;
			cout << "starting time:";
			cin >> start_time;
			cout << "ending time";
			cin >> end_time;
		}
	}

	//check time frame in deadline task
	while ((task_type == DEADLINE_TASK_LABEL) && (!valid_time)){
		std::size_t get_time = deadline_time.find(":");
		start_hour = str.copy(deadline_time, 0, get_time - 1);
		start_mins = str.copy(deadline_time, get_time + 1, get_time.end());
		if ((start_hour >= 0 && start_hour <= 24) && (start_mins >= 0 && start_mins <= 60)){
			valid_time = true;
		}
		else{
			cout << "invalid time, please enter a valid one" << endl;
			cout << "deadline time:";
			cin >> deadline_time;
		}
	}

	//check for valid date
	bool valid_date = false;
	string month;
	string date;

	//check date for deadline task
	while ((task_type == DEADLINE_TASK_LABEL) && (!valid_date)){
		std::size_t get_date = deadline_date.find("/");
		date = str.copy(deadline_date, 0, get_date - 1);
		month = str.copy(deadline_date, get_date + 1, get_date + 3);
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			cout << "invalid date, please input a valid one" << endl;
			cin >> deadline_date;
		}
	}

	//check date for schedule task
	while ((task_type == SCHEDULED_TASK_LABEL) && (!valid_date)){
		std::size_t get_date = scheduled_date.find("/");
		date = str.copy(scheduled_date, 0, get_date - 1);
		month = str.copy(scheduled_date, get_date + 1, get_date + 3);
		if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12)){
			valid_date = true;
		}
		else{
			cout << "invalid date, please input a valid one" << endl;
			cin >> scheduled_date;
		}
	}
}
