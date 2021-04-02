#include "FileOps.h"

using namespace std;

int main()
{
	string folder = "C:\\Users\\istvan\\Downloads\\*";
	int criteria;
	cin >> criteria;

	vector<LocalFile> files = FileOps::get_file_list(folder);

	switch (criteria) {
	case 1:
		FileOps::writeToFiles(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();}));
		break;
	case 2:
		FileOps::writeToFiles(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getMeretMertekEgyseggel();}));
		break;
	case 3:
		FileOps::writeToFiles(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getDatum();}));
		break;
	default:
		cout << "Invalid option!";
	}

	return 0;
}