#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class LocalFile {

	string nev;
	int meret;
	string datum;

public:

	LocalFile(string f_nev, int f_meret, string f_datum);

	string getNev();

	string getNevKiterjesztesNelkul();

	int getMeret();
	
	string getDatum();
};
