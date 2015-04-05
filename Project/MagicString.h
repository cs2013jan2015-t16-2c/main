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
	static const string TODAY;
	//storage
	static const string PROGRAM_START;
	static const string SUCCESS_ARCHIVE;
	//task
	static const string LABEL_SCHEDULED_LABEL;
	static const string LABEL_DEADLINE_TASK;
	static const string LABEL_FLOATING_TASK;
	static const string LABEL_PROCESSING_TASK;
	static const string LABEL_FINISHED_TASK;
	static const string MESSAGE_INVALID_DATE;
	static const string MESSAGE_INVALID_TIME;
	static const string MESSAGE2_INVALID_TIME;
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

	static const string INSTRUCTION_ADD;
	static const string INSTRUCTION_ADD_FLOATING;
	static const string INSTRUCTION_ADD_DEADLINE;
	static const string INSTRUCTION_ADD_TIMED;

	static const string INSTRUCTION_DISPLAY;
	static const string INSTRUCTION_DISPLAY_ALL;
	static const string INSTRUCTION_DISPLAY_FLOATING;
	static const string INSTRUCTION_DISPLAY_DEADLINE;
	static const string INSTRUCTION_DISPLAY_TIMED;

	static const string INSTRUCTION_COMMON;
	
	static const string INSTRUCTION_DELETE;
	static const string INSTRUCTION_DELETE_EXP;

	static const string INSTRUCTION_UPDATE;
	static const string INSTRUCTION_UPDATE_EXP;

	static const string INSTRUCTION_UNDO;
	static const string INSTRUCTION_REDO;

	static const string INSTRUCTION_ARCHIVE;
	static const string INSTRUCTION_ARCHIVE_EXP1;
	static const string INSTRUCTION_ARCHIVE_EXP2;

	static const string INSTRUCTION_EXIT;

	static const string HELP_INDEX;

};

#endif
