#include "FileOps.h"

using namespace std;

int main()
{
	string folder = "C:\\Users\\istvan\\Downloads\\leggyakoribb\\*";
	int criteria = 3;

	vector<LocalFile> files = FileOps::get_file_list(folder);

	switch (criteria) {
	case 1:
		FileOps::printFiles<string>(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getNev();}));
		break;
	case 2:
		FileOps::printFiles<int>(FileOps::groupFiles<int>(files, [](LocalFile f) -> int {return f.getMeret();}));
		break;
	case 3:
		FileOps::printFiles<string>(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getDatum();}));
		break;
	default:
		cout << "Invalid option!";
	}

	return 0;
}