#include "FileOps.h"

using namespace std;

void getInput(string& inFolder, string& outFolder, int& criteria)
{
	cout << "A program a megadott konyvtarban megkeresi a megadott kriterium alapjan azonos fajlokat es fajlokba irja azokat.\n\n";
	cout << "################### Adj meg egy bemeneti konyvtarat ###################\n\n";
	cin >> inFolder;
	cout << "\n################### Adj meg egy kimeneti konyvtarat ###################\n\n";
	cin >> outFolder;
	cout << "\n################### Valassz kriteriumoit (add meg az opcio szamat) ###################\n\n";
	cout << "1 - nev\n";
	cout << "2 - meret\n";
	cout << "3 - datum\n";
	cin >> criteria;
}

function<string(LocalFile)> criteriaFunc(int criteria) {
	switch (criteria) {
		case 1:	return [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();};
		case 2:	return [](LocalFile f) -> string {return f.getMeretMertekEgyseggel();};
		case 3:	return [](LocalFile f) -> string {return f.getDatum();};
		default: return [](LocalFile f) -> string {return f.getNevKiterjesztesNelkul();};
	}
}

int main()
{
	string inFolder;
	string outFolder;
	int criteria;

	getInput(inFolder, outFolder, criteria);

	//string inFolder = "C:\\Users\\istvan\\Downloads\\leggyakoribb\\";
	//string outFolder = "C:\\Temp\\";
	
	vector<LocalFile> files;
	FileOps::get_file_list(inFolder, files);
	FileOps::writeToFiles(
		FileOps::groupFiles<string>(files, criteriaFunc(criteria)), 
		outFolder
	);
}