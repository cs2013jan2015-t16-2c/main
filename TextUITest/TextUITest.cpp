#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepTrackTest 
{	
	//@author A0093586N
	string temp;
	TEST_CLASS(TestInterfaceInput) {
	
	public:
		
		TEST_METHOD(TestGetFirstWord) {
			// to test if this method can return the first word of user input
			string testString = "add do homework";
			string expectedOutput = "add";
			string actualOutput = InterfaceInput::testGetFirstWord(testString);

			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(TestRemoveFirstWord) {
			// to test if this method can return the remaining part of the user input
			// after removing the first word
			string testString = "add do homework";
			string expectedOutput = "do homework";
			string actualOutput = InterfaceInput::testRemoveFirstWord(testString);

			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(TestExecuteUserCommand) {
			// to test if this method can return the correct feedback
			string testStringAdd = "add do homework -from 14:00 15/05 -to 15:00 @room #study";
			temp = InterfaceInput::executeUserCommand(testStringAdd);
			string expectedOutputAdd1 = MagicString::MESSAGE_NO_TASK_TODAY;
			string expectedOutputAdd2 = MagicString::TASK_ADDED;
			string actualOutputAdd1 = InterfaceInput::TEST_OUTPUT_TODAY;
			string actualOutputAdd2 = InterfaceInput::TEST_OUTPUT_EXECUTE;

			string testStringDelete = "delete 1";
			temp = InterfaceInput::executeUserCommand(testStringDelete);
			string expectedOutputDelete1 = MagicString::MESSAGE_NO_TASK_TODAY;
			string expectedOutputDelete2 = MagicString::TASK + "1" + MagicString::NON_EXISTENCE;
			string actualOutputDelete1 = InterfaceInput::TEST_OUTPUT_TODAY;
			string actualOutputDelete2 = InterfaceInput::TEST_OUTPUT_EXECUTE;

			string testStringInvalidCommand = "invalid command";
			temp = InterfaceInput::executeUserCommand(testStringInvalidCommand);
			string expectedOutputInvalidCommand = MagicString::ERROR_INVALID_COMMAND;
			string actualOutputInvalidCommand = InterfaceInput::TEST_OUTPUT_EXECUTE;

			string testStringDisplayToday = "display today";
			string expectedOutputDisplayToday = MagicString::MESSAGE_NO_TASK_TODAY;
			temp = InterfaceInput::executeUserCommand(testStringDisplayToday);
			string actualOutputDisplayToday = InterfaceInput::TEST_OUTPUT_EXECUTE;

			Assert::AreEqual(expectedOutputAdd1, actualOutputAdd1);
			Assert::AreEqual(expectedOutputAdd2, actualOutputAdd2);
			Assert::AreEqual(expectedOutputDelete1, actualOutputDelete1);
			Assert::AreEqual(expectedOutputDelete2, actualOutputDelete2);
			Assert::AreEqual(expectedOutputInvalidCommand, actualOutputInvalidCommand);
			Assert::AreEqual(expectedOutputDisplayToday, expectedOutputDisplayToday);
		}
	};

	TEST_CLASS(TestInterfaceOutput) {
	public:

		TEST_METHOD(TestDisplayWelcome) {
			// to test if welcome message can be shown
			string expectedOutput = MagicString::MESSAGE_WELCOME;
			string actualOutput = InterfaceOutput::displayWelcome();
			Assert::AreEqual(expectedOutput, actualOutput);
		}

	};

	TEST_CLASS(TestDisplayColor) {
	public:

		TEST_METHOD(TestDisplayColorMethod) {
			//to test if the 'displayColor' function can output the correct value
			string testStringDisplayColor = "do homework";
			string expectedOutputDisplayColor = "do homework";
			temp = DisplayColor::displayColor(testStringDisplayColor);
			string actualOutputDisplayColor = DisplayColor::TEST_OUTPUT;

			Assert::AreEqual(expectedOutputDisplayColor, actualOutputDisplayColor);
		}

		TEST_METHOD(TestDisplayError) {
			//to test if the 'displayError' function can output the correct value
			string testStringDisplayError = "error";
			string expectedOutputDisplayError = "error";
			temp = DisplayColor::displayError(testStringDisplayError);
			string actualOutputDisplayError = DisplayColor::TEST_OUTPUT;

			Assert::AreEqual(expectedOutputDisplayError, actualOutputDisplayError);
		}

		TEST_METHOD(TestDisplaySuccess) {
			//to test if the 'displaySuccess' function can output the correct value
			string testStringDisplaySuccess = "success";
			string expectedOutputDisplaySuccess = "success";
			temp = DisplayColor::displaySuccess(testStringDisplaySuccess);
			string actualOutputDisplaySuccess = DisplayColor::TEST_OUTPUT;

			Assert::AreEqual(expectedOutputDisplaySuccess, actualOutputDisplaySuccess);
		}
	};
}
