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
	}
	else if (task_type == "timed"){
		strcat(task, " ");
		strcat(task, scheduled_date);
		strcat(task, " ");
		strcat(task, start_time);
		strcat(task, end_time);
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
	// check for validation for time frame in scheduled task
	while ((start_time != "") && ((start_time > 2400) || (start_time < 0000))){
		cout << "invalid starting time, please enter again." << endl;
		cin >> start_time;
	}
	while ((end_time != "") && ((end_time > 2400) || (end_time < 0000))){
		cout << "invalid ending time, please enter again." << endl;
		cin >> end_time;
	}
	if (start_time > end_time){
		string temp_time;
		cout << "invalid time frame, please enter again" << endl;
		cin >> temp_time;
		std::size_t get_time = temp_time.find("-");
		start_time = str.copy(temp_time, 0, get_time - 1);
		end_time = str.copy(temp_time, get_time + 1, get_time + 5);
	}
	//check for valid date
	if (deadline_date != ""){
		//
	}
}
