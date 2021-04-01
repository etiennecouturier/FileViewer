#include "FileOps.h"
#include <string>
#include <iostream>

using namespace std;

// https://docs.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa
vector<LocalFile> FileOps::get_file_list(string DATA_DIR)
{
	vector<LocalFile> files;
	HANDLE hFind;
	WIN32_FIND_DATAA data;

	hFind = FindFirstFileA(DATA_DIR.c_str(), &data);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			string fileName = data.cFileName;
			int fileSize = (data.nFileSizeHigh * (MAXDWORD + 1) + data.nFileSizeLow) / 1024;
			FILETIME fileTime = data.ftCreationTime;
			SYSTEMTIME sysTime;
			FileTimeToSystemTime(&fileTime, &sysTime);

			int year = sysTime.wYear;
			int month = sysTime.wMonth;
			int day = sysTime.wDay;
			LocalFile file(fileName, fileSize, to_string(year) + "-" + to_string(month) + "-" + to_string(day));
			files.push_back(file);
			//printf("%s %d %d\n", fileName.c_str(), fileSize, sysTime.wYear);
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
		return files;
	}
}