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

	static const string ADD_HELP_PAGE_INDEX;
	static const string DISPLAY_HELP_PAGE_INDEX;
	static const string DELETE_HELP_PAGE_INDEX;
	static const string UPDATE_HELP_PAGE_INDEX;
	static const string UNDO_HELP_PAGE_INDEX;
	static const string REDO_HELP_PAGE_INDEX;
	static const string ARCHIVE_HELP_PAGE_INDEX;
	static const string EXIT_HELP_PAGE_INDEX;
	static const string REUTRN_TO_MAIN_HELP_PAGE;
	static const string EXIT_HELP;
	static const string MESSAGE_INVALID_INDEX;
	static const string MESSAGE_NEXT_ACTION;
	static const string MESSAGE_RETURN_TO_MAIN;
	static const string MESSAGE_EXIT_HELP;
	static const string MESSAGE_COMMAND;

	static const string ADD_INSTRUCTION;
	static const string ADD_INSTRUCTION_FLOATING;
	static const string ADD_INSTRUCTION_DEADLINE;
	static const string ADD_INSTRUCTION_TIMED;

	static const string DISPLAY_INSTRUCTION;
	static const string DISPLAY_INSTRUCTION_ALL;
	static const string DISPLAY_INSTRUCTION_FLOATING;
	static const string DISPLAY_INSTRUCTION_DEADLINE;
	static const string DISPLAY_INSTRUCTION_TIMED;

	static const string COMMON_INSTRUCTION;
	
	static const string DELETE_INSTRUCTION;
	static const string DELETE_INSTRUCTION_EXP;

	static const string UPDATE_INSTRUCTION;
	static const string UPDATE_INSTRUCTION_EXP;

	static const string UNDO_INSTRUCTION;
	static const string REDO_INSTRUCTION;

	static const string ARCHIVE_INSTRUCTION;
	static const string ARCHIVE_INSTRUCTION_EXP1;
	static const string ARCHIVE_INSTRUCTION_EXP2;

	static const string EXIT_INSTRUCTION;

	static const string HELP_INDEX;

};

#endif
