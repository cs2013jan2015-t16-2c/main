#ifndef MagicString_H_
#define MagicString_H_

#include <iostream>

using namespace std;

class MagicString{
public:
	//interfaceoutput
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_TIP;
	static const string MESSAGE_GOODBYE;
	static const string ERROR_INVALID_COMMAND;
	//storage
	static const string PROGRAM_START;
	static const string ARCHIVE_SUCCESS;
	//task
	static const string SCHEDULED_TASK_LABEL;
	static const string DEADLINE_TASK_LABEL;
	static const string FLOATING_TASK_LABEL;
	static const string PROCESSING_TASK_LABEL;
	static const string FINISHED_TASK_LABEL;
	static const string INVALID_DATE_MSG;
	static const string INVALID_TIME_MSG;
	static const string INVALID_TIME_MSG2;
	//taskList
	static const string TASK_ADDED;
	static const string TASK_EMPTY;
	static const string SEARCH_NOT_FOUND;
	static const string TASK;
	static const string NON_EXISTENCE;
	static const string UPDATE;
	static const string DELETE;
	static const string TASK_EMPTY2;
	static const string MARK_AS_DONE;
	static const string ADD_UNDO;
	static const string UPDATE_UNDO;
	static const string DELETE_UNDO;
	static const string MARK_UNDO;
	static const string UNDO_INABLE;
	static const string ADD_REDO;
	static const string UPDATE_REDO;
	static const string DELETE_REDO;
	static const string MARK_REDO;
	static const string REDO_INABLE;

	//keppTrack
	static const string DIVIDER;
	//help
	static const string HELP_MAIN;

};

#endif
