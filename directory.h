#pragma once
#include "file.h"
#include <string>
#include <vector>

using namespace std;

class directory
{
private:

	string directoryName; //
	vector <file> files; // vector of files
	vector <directory> directories; // vector of directories


public:
	directory(string directoryName, vector<file> files, vector<directory> directories) : directoryName(directoryName), directories(directories), files(files) {}

};

