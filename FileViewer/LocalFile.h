#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class LocalFile {

	string nev;
	int meret;

public:

	LocalFile(string f_nev, int f_meret);

	string getNev();

	int getMeret();
};
