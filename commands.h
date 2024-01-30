#pragma once
#include "directory.h"
#include "file.h"

class commands
{
public:
	directory dir(directory); 

	//STL
	const directory sortsize(directory); 
	const directory sortname(directory);

	//Other Commands
	directory mkdir();
	file mkfile();
	directory del();
	//file del();
	void exit(); 
};

