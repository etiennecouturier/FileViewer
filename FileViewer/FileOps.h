#pragma once
#include "LocalFile.h"
#include <Windows.h>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>

class FileOps
{
public:

	static void get_file_list(string DATA_DIR, vector<LocalFile>& files);

	template <typename T>
	static map<T, vector<LocalFile>> groupFiles(vector<LocalFile> files, function<T(LocalFile)> attr);

	template <typename T>
	static void printFiles(map<T, vector<LocalFile>> groupedFiles);

	static void writeToFiles(map<string, vector<LocalFile>> groupedFiles, string outFolder);

};

template <typename T>
static map<T, vector<LocalFile>> FileOps::groupFiles(vector<LocalFile> files, function<T(LocalFile)> attr) {
	map<T, vector<LocalFile>> groupedFiles;
	for (LocalFile file : files) groupedFiles[attr(file)].push_back(file);
	return groupedFiles;
}

template <typename T>
static void FileOps::printFiles(map<T, vector<LocalFile>> groupedFiles) {
	for (auto group : groupedFiles) {
		cout << group.first << "\n-----------------\n";
		for (auto file : group.second) {
			cout << file.getNev() << " " << file.getMeret() << "KB " << file.getDatum() << "\n";
		}
		cout << "\n";
	}
}

