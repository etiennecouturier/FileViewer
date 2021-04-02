#include "FileOps.h"

using namespace std;

void prinMenu()
{
	cout << "A program a megadott konyvtarban megkeresi a megadott kriterium alapjan azonos fajlokat es fajlokba irja azokat.\n\n";
	cout << "################### Valassz kriteriumoit (add meg az opcio szamat) ###################\n\n";
	cout << "1 - nev\n";
	cout << "2 - meret\n";
	cout << "3 - datum\n";
}

function<string(LocalFile)> criteriaFunc(int criteria) {
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
	prinMenu();
	string inFolder = "C:\\Users\\istvan\\Downloads\\leggyakoribb\\";
	string outFolder = "C:\\Temp\\";
	int criteria;
	cin >> criteria;

	vector<LocalFile> files;
	FileOps::get_file_list(inFolder, files);
	FileOps::writeToFiles(
		FileOps::groupFiles<string>(files, criteriaFunc(criteria)), 
		outFolder
	);
}