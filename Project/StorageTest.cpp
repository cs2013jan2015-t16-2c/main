#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepTrackTest 
{	
	//@author A0114792A
	TEST_CLASS(TestStorage) {
	public:

		TEST_METHOD(TestStarting) {
			//to test the data has been successfully transferred into tempStorage
			string expectedOutput = MagicString::PROGRAM_START;
			string actualOutput = storage::starting();

			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(TestArchive) {
			//to test the file has been successfully archived 
			string testString = "testFile";
			string expectedOutput = MagicString::SUCCESS_ARCHIVE;
			string actualOutput = storage::archive(testString);

			Assert::AreEqual(expectedOutput, actualOutput);
		}
	};
}
