#include "pch.h"
#include "CppUnitTest.h"
#include "../FileViewer/FileOps.h"
#include "../FileViewer/FileOps.cpp"
#include "../FileViewer/LocalFile.h"
#include "../FileViewer/LocalFile.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileViewerTest
{
	TEST_CLASS(FileViewerTest)
	{
	private:
		function<string(LocalFile)> orderByName = [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();};
		function<string(LocalFile)> orderByMeret = [](LocalFile f) -> string {return f.getMeretMertekEgyseggel();};
		function<string(LocalFile)> orderByDate = [](LocalFile f) -> string {return f.getDatum();};

	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<LocalFile> files;
			LocalFile file1("ibolya.txt", 3, "2020-03-04");
			LocalFile file2("ibolya.png", 3, "2020-03-05");
			files.push_back(file1);
			files.push_back(file2);

			map<string, vector<LocalFile>> result = FileOps::groupFiles<string>(files, orderByName);
			Assert::AreEqual(1, static_cast<int>(result.size()));
		}

		TEST_METHOD(TestMethod2)
		{
			vector<LocalFile> files;
			LocalFile file1("ibolya.txt", 3, "2020-03-04");
			LocalFile file2("ibolya.txt", 8, "2020-03-05");
			files.push_back(file1);
			files.push_back(file2);

			map<string, vector<LocalFile>> result = FileOps::groupFiles<string>(files, orderByMeret);
			Assert::AreEqual(2, static_cast<int>(result.size()));
		}

		TEST_METHOD(TestMethod3)
		{
			vector<LocalFile> files;
			LocalFile file1("ibolya.txt", 8, "2020-03-04");
			LocalFile file2("ibolya.txt", 8, "2020-03-05");
			files.push_back(file1);
			files.push_back(file2);

			map<string, vector<LocalFile>> result = FileOps::groupFiles<string>(files, orderByMeret);
			Assert::AreEqual(1, static_cast<int>(result.size()));
		}
	};
}
