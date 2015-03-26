#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaskListTest
{		
	TEST_CLASS(TaskListTest)
	{
	public:
		
		TEST_METHOD(AddTaskTest){
			TaskList::addTask("tutorial -from 14:00 -to 16:00 14/03");
			string expected = "1. tutorial 14/03 14:00 16:00 progressing";
			string output = TaskList::display("all");
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(UpdateTaskTest){
			TaskList::empty();
			TaskList::addTask("assignment");
			TaskList::addTask("lecture");
			TaskList::addTask("tut");
			TaskList::display("all");
			string output, expected;

			//Test for boundary case for negative Task Number partition
			output = TaskList::updateTask("-1 -by 14:00 14/03");
			expected = "Task -1 does not exit";
			Assert::AreEqual(expected, output);
			
			//Test for boundary case for Task Number greater than list size partition
			output = TaskList::updateTask("4 -from 14:00 -to 16:00 22/03");
			expected = "Task 4 does not exit";
			Assert::AreEqual(expected, output);

			//Test for partition of changing from floating to timed task
			TaskList::updateTask("2 -from 16:00 -to 17:00 26/03");
			output = TaskList::display("timed");
			expected = "1. lecture 26/03 16:00 17:00 progressing";
			Assert::AreEqual(expected, output);

			//Test for partition of changing from floating to deadline task
			TaskList::display("floating");
			TaskList::updateTask("1 -by 23:59 30/03");
			output = TaskList::display("deadline");
			expected = "1. assignment 30/03 23:59 progressing";
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(DeleteTaskTest){
			TaskList::empty();
			TaskList::addTask("assignment"); 
			TaskList::addTask("lecture");
			TaskList::addTask("tut");
			TaskList::display("all");
			string output, expected;

			//Test for boundary case for negative Task Number partition
			output = TaskList::deleteTask("-1");
			expected = "Task -1 does not exit";
			Assert::AreEqual(expected, output);

			//Test for boundary case for Task Number greater than list size partition
			output = TaskList::deleteTask("4");
			expected = "Task 4 does not exit";
			Assert::AreEqual(expected, output);

			//Test for Task Number within the list size
			TaskList::deleteTask("1");
			output = TaskList::display("all");
			expected = "1. lecture progressing\n2. tut progressing";
			Assert::AreEqual(expected, output);
		}
	};
}