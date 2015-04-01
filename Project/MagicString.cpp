#include "MagicString.h"

//interfaceoutput
const string MESSAGE_WELCOME = "Welcome to KeepTrack";
const string MESSAGE_TIP = "Tip: enter 'help' to learn how to use KeepTrack";
const string MESSAGE_GOODBYE = "Goodbye!";
const string ERROR_INVALID_COMMAND = "Error: invalid command";
//Storage
const string PROGRAM_START = "Data has been successfully loaded";
const string ARCHIVE_SUCCESS = "Tasklist is successfully archived";
//Task
const string SCHEDULED_TASK_LABEL = "timed";
const string DEADLINE_TASK_LABEL = "deadline";
const string FLOATING_TASK_LABEL = "floating";
const string PROCESSING_TASK_LABEL = "in progress";
const string FINISHED_TASK_LABEL = "done";
const string INVALID_DATE_MSG = "invalid date, please input a valid one";
const string INVALID_TIME_MSG = "invalid time, please enter a valid one";
const string INVALID_TIME_MSG2 = "invalid time frame, ending time cannot be earlier than starting time, please enter a valid one";
//TaskList
const string TASK_ADDED = "Task added";
const string TASK_EMPTY = "Task list is empty";
const string SEARCH_NOT_FOUND = "No task containes the searched word";
const string TASK = "Task ";
const string NON_EXISTENCE = " does not exist";
const string UPDATE = " updated";
const string DELETE = " deleted";
const string TASK_EMPTY2 = "Required task list is empty";
const string MARK_AS_DONE = " marked as done";
const string ADD_UNDO = "Adding command is undone";
const string UPDATE_UNDO = "Updating command is undone";
const string DELETE_UNDO = "Deleting command is undone";
const string MARK_UNDO = "MarkasDone command is undone";
const string UNDO_INABLE = "Previous action cannot be undone";
const string ADD_REDO = "Adding command is redone";
const string UPDATE_REDO = "Updating command is redone";
const string DELETE_REDO = "Deleting command is redone";
const string MARK_REDO = "MarkasDone command is redone";
const string REDO_INABLE = "previous action cannot be redone";
//keepTrack
const string DIVIDER = "================================================================================";
//help
const string HELP_MAIN_L1 = "Please select the function you would like to know";
const string HELP_MAIN_L2 = "1.  Add a task";
const string HELP_MAIN_L3 = "2.  Display tasks";
const string HELP_MAIN_L4 =	"3.  Delete a task";
const string HELP_MAIN_L5 = "4.  Update a task";
const string HELP_MAIN_L6 = "5.  Undo the last action";
const string HELP_MAIN_L7 = "6.  Redo the last action";
const string HELP_MAIN_L8 = "7.  Archive your task list to another file";
const string HELP_MAIN_L9 = "8.  How to exit KeepTrack";
const string HELP_MAIN_L10 = "00. Get back to KeepTrack";

const string ADD_HELP_PAGE_INDEX = "1";
const string DISPLAY_HELP_PAGE_INDEX = "2";
const string DELETE_HELP_PAGE_INDEX = "3";
const string UPDATE_HELP_PAGE_INDEX = "4";
const string UNDO_HELP_PAGE_INDEX = "5";
const string REDO_HELP_PAGE_INDEX = "6";
const string ARCHIVE_HELP_PAGE_INDEX = "7";
const string EXIT_HELP_PAGE_INDEX = "8";
const string REUTRN_TO_MAIN_HELP_PAGE = "0";
const string EXIT_HELP = "00";
const string MESSAGE_INVALID_INDEX = "Error: invalid input!";
const string MESSAGE_NEXT_ACTION = "You may select the following actions";
const string MESSAGE_RETURN_TO_MAIN = "0:  return to the main help page";
const string MESSAGE_EXIT_HELP =      "00: get back to KeepTrack!";
const string MESSAGE_COMMAND = "Command: ";

const string ADD_INSTRUCTION = "You can add three types of tasks";
const string ADD_INSTRUCTION_FLOATING = "Floating task: add do assignment 1";
const string ADD_INSTRUCTION_DEADLINE = "Deadline:      add finish assignment 1 -by 14:00 13/4";
const string ADD_INSTRUCTION_TIMED = "Timed task:    add do assignment 1 -from 9:00 -to 11:00 12/4";

const string DISPLAY_INSTRUCTION = "You can display your task list in the following ways: ";
const string DISPLAY_INSTRUCTION_ALL = "All the tasks:          display all";
const string DISPLAY_INSTRUCTION_FLOATING = "All the floating tasks: display floating";
const string DISPLAY_INSTRUCTION_DEADLINE = "All the deadlines:      display deadline";
const string DISPLAY_INSTRUCTION_TIMED = "All the timed task:     display timed";

const string COMMON_INSTRUCTION = "After displaying tasks";

const string DELETE_INSTRUCTION = "you can delete a task by its index";
const string DELETE_INSTRUCTION_EXP = "Example: delete 2";

const string UPDATE_INSTRUCTION = "you can select the task by its index and input the updated task information";
const string UPDATE_INSTRUCTION_EXP = "Example: update Update 1 -from 1300 -to 1500 23/12";

const string UNDO_INSTRUCTION = "You can unoo your last action by simply entering 'undo'";
const string REDO_INSTRUCTION = "You can reoo your last action by simply entering 'redo'";

const string ARCHIVE_INSTRUCTION = "You can archive your task list in the following ways: ";
const string ARCHIVE_INSTRUCTION_EXP1 = "Archive in the program folder: archive myText.txt";
const string ARCHIVE_INSTRUCTION_EXP2 = "Archive in another folder:     archive C:/Users/USER/Desktop/myText.txt";

const string EXIT_INSTRUCTION = "You can exit KeepTrack by simply entering 'exit'";

const string HELP_INDEX = "Help Index: ";


