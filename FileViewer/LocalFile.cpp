#include "LocalFile.h"

LocalFile::LocalFile(string f_nev, int f_meret) :nev(f_nev), meret(f_meret) {}

string LocalFile::getNev()
{
	return nev;
}

int LocalFile::getMeret()
{
	return meret;
}