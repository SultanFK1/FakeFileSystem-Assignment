#pragma once
#include <string>
using namespace std; 

class file
{
private:
	int filesize;
	int timestamp;
protected:
	string filename;
public:
	int generateFileSize(string filename);

};

