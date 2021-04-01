#include "LocalFile.h"

LocalFile::LocalFile(string f_nev, int f_meret, string f_datum) :nev(f_nev), meret(f_meret), datum(f_datum) {}

string LocalFile::getNev()
{
	return nev;
}

string LocalFile::getNevKiterjesztesNelkul()
{
	return nev.substr(0, nev.find_last_of("."));
}

int LocalFile::getMeret()
{
	return meret;
}

string LocalFile::getDatum()
{
	return datum;
}