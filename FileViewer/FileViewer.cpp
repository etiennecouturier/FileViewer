#include "FileOps.h"

using namespace std;

function<string(LocalFile)> getFunc(int criteria) {
	switch (criteria) {
	case 1:
		return [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();};
	case 2:
		return [](LocalFile f) -> string {return f.getMeretMertekEgyseggel();};
	case 3:
		return [](LocalFile f) -> string {return f.getDatum();};
	default:
		return [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();};
	}
}

int main()
{
	string folder = "C:\\Users\\istvan\\Downloads\\*";
	int criteria;
	cin >> criteria;

	vector<LocalFile> files = FileOps::get_file_list(folder);
	FileOps::writeToFiles(FileOps::groupFiles<string>(files, getFunc(criteria)));
}