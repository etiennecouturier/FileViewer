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
		FileOps::writeToFiles<string>(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();}));
		break;
	case 2:
		FileOps::writeToFiles<int>(FileOps::groupFiles<int>(files, [](LocalFile f) -> int {return f.getMeret();}));
		break;
	case 3:
		FileOps::writeToFiles<string>(FileOps::groupFiles<string>(files, [](LocalFile f) -> string {return f.getDatum();}));
		break;
	default:
		cout << "Invalid option!";
	}

	return 0;
}