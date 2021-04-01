#include "LocalFile.h"

LocalFile::LocalFile(string f_nev, int f_meret, string f_datum) :nev(f_nev), meret(f_meret), datum(f_datum) {}

string LocalFile::getNev()
{
	return nev;
}

int LocalFile::getMeret()
{
	return meret;
}

string LocalFile::getDatum()
{
	return datum;
}