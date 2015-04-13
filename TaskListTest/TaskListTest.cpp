#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//Ma Zhuoyuan A0113624R
namespace TaskListTest
{		
	TEST_CLASS(TaskListTest)
	{
	public:		
		TEST_METHOD(addTest)
		{
			//Test for invalid time input with ending time eariler than starting time
			string actual = TaskList::addTask("tut -from 10:00 -to 08:00");
			string expected = MagicString::INVALID_TIME_INPUT;
			Assert::AreEqual(expected, actual);

			//Test for invalid time input with time over the limit
			actual = TaskList::addTask("assignment -by 25:00");
			expected = MagicString::INVALID_TIME_INPUT;
			Assert::AreEqual(expected, actual);

			//Test for valid time input
			actual = TaskList::addTask("assignment -by 23:59");
			expected = MagicString::TASK_ADDED;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(deleteTest){
			TaskList::empty();
			//Test for empty list
			string actual = TaskList::deleteTask("1");
			string expected = MagicString::TASK + "1" + MagicString::NON_EXISTENCE;
			Assert::AreEqual(expected, actual);

			//Adding tasks for further testing
			TaskList::addTask("tut");
			TaskList::display("all");
			
			//Test for invalid taskIndex with non digit input
			actual = TaskList::deleteTask("2asa");
			expected = MagicString::MESSAGE_INVALID_INDEX;
			Assert::AreEqual(expected, actual);

			//Test for invalid taskIndex with digit input large than the size
			actual = TaskList::deleteTask("2");
			expected = MagicString::TASK + "2" + MagicString::NON_EXISTENCE;
			Assert::AreEqual(expected, actual);

			//Test for valid taskIndex
			actual = TaskList::deleteTask("1");
			expected = MagicString::TASK + "1" + MagicString::DELETE;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(displayTest){
			TaskList::empty();
			TaskList::addTask("study @UT");
			TaskList::addTask("tut -from 13/04 14:00 -to 16:00 #CS");
			TaskList::addTask("assignment -by 15/04 #CS");

			string task1 = "study @UT in progress";
			string task2 = "tut [13/04 14:00] to [13/04 16:00] #CS in progress";
			string task3 = "assignment [15/04] #CS in progress";

			//Test for invalid display type
			string actual = TaskList::display("asda");
			string expected = MagicString::INVALID_DISPLAY;
			Assert::AreEqual(expected, actual);

			//Test for display all
			actual = TaskList::display("all");
			expected = "1. " + task2 + "\n" + "2. " + task3 + "\n" + "3. " + task1;
			Assert::AreEqual(expected, actual);

			//Test for display based on task type
			actual = TaskList::display("timed");
			expected = "1. " + task2;
			Assert::AreEqual(expected, actual);

			//Test for display based on task group
			actual = TaskList::display("CS");
			expected = "1. " + task2 + "\n" + "2. " + task3;
			Assert::AreEqual(expected, actual);

			//Test for empty displayList
			TaskList::empty();
			actual = TaskList::display("all");
			expected = MagicString::TASK_EMPTY2;
			//Assert::AreEqual(expected, actual);
		}
	};
}