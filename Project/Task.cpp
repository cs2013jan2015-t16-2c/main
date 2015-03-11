#include "task.h"

const int TASK_LEN = 256;

Task::Task(string input){
	if (!input.empty()){
		std::size_t timed_task = input.find("-from");
		std::size_t deadlined_task = input.find("-by");
		if (timed_task != std::string::npos){
			std::size_t end_time = input.find("-to");
			std::size_t get_date = input.find("/");
			task_type = "timed";
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
			task_type = "deadline";
			taskname = str.copy(input, 0, deadlined_task - 2);
			start_time = "";
			end_time = "";
			deadline_time = str.copy(input, deadlined_task + 4, 4);
			scheduled_date = "";
			deadline_date = (input, get_date - 2, get_date + 2);
			status = "progressing";
		}
		else{
			task_type = "floating";
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

string Task::ToString(){
	char task[TASK_LEN];
	strcpy(task, taskname);
	if (task_type == "deadline"){
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
			task_type = "timed";
			start_time = str.copy(input, timed_task + 6, 4);
			end_time = str.copy(input, end_time + 4, 4);
			if (get_date != std::string::npos){
				scheduled_date = str.copy(input, get_date - 2, get_date + 2);
			}
		}
		else if (deadlined_task != std::string::npos){
			std::size_t get_date = input.find("/");
			task_type = "deadline";
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
	while ((task_type == "timed") && (!valid_time)){
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
	while ((task_type == "deadline") && (!valid_time)){
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
	while ((task_type == "deadline") && (!valid_date)){
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
	while ((task_type == "timed") && (!valid_date)){
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
