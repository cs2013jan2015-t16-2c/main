#ifndef MagicString_H_
#define MagicString_H_

#include <iostream>

using namespace std;

class MagicString{
public:
	//display taskList
	static const string MESSAGE_EMPTY;
	//interfaceinput
	static const string MESSAGE_USER_COMMAND;
	static const string MESSAGE_NO_TASK_TODAY;
	static const string MESSAGE_TODAY_TASK;
	static const string MESSAGE_WARNING_1;
	static const string MESSAGE_WARNING_2;
	static const string ERROR_TYPE_AGAIN;
	//interfaceoutput
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_TIP;
	static const string MESSAGE_GOODBYE;
	static const string ERROR_INVALID_COMMAND;
	static const string TODAY;
	//storage
	static const string PROGRAM_START;
	static const string SUCCESS_ARCHIVE;
	static const string FILE_RUBBISH;
	static const string FILE_CHECK;
	static const string DONE_TASK_SAVED;
	static const string IN_PROGRESS_TASK_SAVED;
	static const string STORAGE_CLEARED;
	static const string ARCHIVE_CLEARED;
	//task
	static const string LABEL_SCHEDULED_TASK;
	static const string LABEL_DEADLINE_TASK;
	static const string LABEL_FLOATING_TASK;
	static const string LABEL_PROCESSING_TASK;
	static const string LABEL_FINISHED_TASK;
	static const string MESSAGE_INVALID_DATE;
	static const string MESSAGE_INVALID_TIME;
	static const string MESSAGE2_INVALID_TIME;
	//taskList
	static const string FLOATING_CANNOT_RECUR;
	static const string RECURRING_TASK_ADDED;
	static const string INVALID_TIME_INPUT;
	static const string TASK_ADDED;
	static const string TASK_EMPTY;
	static const string SEARCH_NOT_FOUND;
	static const string INVALID_DISPLAY;
	static const string TASK;
	static const string NON_EXISTENCE;
	static const string UPDATE;
	static const string DELETE;
	static const string TASK_EMPTY2;
	static const string MARK_AS_DONE;
	static const string SET_PRIORITY;
	static const string INVALID_PRIORITY;
	static const string ADD_UNDO;
	static const string UPDATE_UNDO;
	static const string DELETE_UNDO;
	static const string MARK_UNDO;
	static const string PRIORITY_UNDO;
	static const string UNDO_UNABLE;
	static const string ADD_REDO;
	static const string UPDATE_REDO;
	static const string DELETE_REDO;
	static const string MARK_REDO;
	static const string PRIORITY_REDO;
	static const string REDO_UNABLE;

	//keepTrack
	static const string DIVIDER;
	//help
	static const string HELP_MAIN_L1;
	static const string HELP_MAIN_L2;
	static const string HELP_MAIN_L3;
	static const string HELP_MAIN_L4;
	static const string HELP_MAIN_L5;
	static const string HELP_MAIN_L6;
	static const string HELP_MAIN_L7;
	static const string HELP_MAIN_L8;
	static const string HELP_MAIN_L9;
	static const string HELP_MAIN_L10;
	static const string HELP_MAIN_L11;

	static const string ADD_HELP_PAGE_INDEX;
	static const string DISPLAY_HELP_PAGE_INDEX;
	static const string SET_PRIORITY_HELP_PAGE_INDEX;
	static const string DELETE_HELP_PAGE_INDEX;
	static const string UPDATE_HELP_PAGE_INDEX;
	static const string UNDO_REDO_HELP_PAGE_INDEX;
	static const string ARCHIVE_HELP_PAGE_INDEX;
	static const string CLEAR_HELP_PAGE_INDEX;
	static const string EXIT_HELP_PAGE_INDEX;
	static const string REUTRN_TO_MAIN_HELP_PAGE;
	static const string EXIT_HELP;
	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_NEXT_ACTION;
	static const string MESSAGE_RETURN_TO_MAIN;
	static const string MESSAGE_EXIT_HELP;
	static const string MESSAGE_COMMAND;

	static const string INSTRUCTION_ADD;
	static const string INSTRUCTION_ADD_FLOATING;
	static const string INSTRUCTION_ADD_DEADLINE;
	static const string INSTRUCTION_ADD_TIMED_1;
	static const string INSTRUCTION_ADD_TIMED_2;
	static const string INSTRUCTION_ADD_TAG;
	static const string INSTRUCTION_ADD_VENUE;
	static const string INSTRUCTION_ADD_BOTH_1;
	static const string INSTRUCTION_ADD_BOTH_2;
	static const string INSTRUCTION_ADD_RECUR_1;
	static const string INSTRUCTION_ADD_RECUR_2;

	static const string INSTRUCTION_DISPLAY;
	static const string INSTRUCTION_DISPLAY_TODAY;
	static const string INSTRUCTION_DISPLAY_FLOATING;
	static const string INSTRUCTION_DISPLAY_DEADLINE;
	static const string INSTRUCTION_DISPLAY_TIMED;
	static const string INSTRUCTION_DISPLAY_DONE;
	static const string INSTRUCTION_DISPLAY_CLASS;
	static const string INSTRUCTION_DISPLAY_VENUE;
	static const string INSTRUCTION_DISPLAY_ALL;

	static const string INSTRUCTION_COMMON;
	
	static const string INSTRUCTION_SET_PRIORITY;
	static const string INSTRUCTION_SET_PRIORITY_REMINDER;
	static const string INSTRUCTION_SET_PRIORITY_EXP1;
	static const string INSTRUCTION_SET_PRIORITY_EXP2;

	static const string INSTRUCTION_DELETE;
	static const string INSTRUCTION_DELETE_EXP;

	static const string INSTRUCTION_UPDATE;
	static const string INSTRUCTION_UPDATE_EXP;

	static const string INSTRUCTION_UNDO;
	static const string INSTRUCTION_REDO;

	static const string INSTRUCTION_ARCHIVE;
	static const string INSTRUCTION_ARCHIVE_EXP1;
	static const string INSTRUCTION_ARCHIVE_EXP2;

	static const string INSTRUCTION_CLEAR_EXP1;
	static const string INSTRUCTION_CLEAR_EXP2;

	static const string INSTRUCTION_EXIT;

	static const string HELP_INDEX;

};

#endif
