#pragma once
#include <string>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = filesystem;

class file
{
private:
    int filesize_;
    int timestamp_;
    string filename_;

public:
    file(string filename) : filename_(filename), filesize_(generateFileSize(filename)), timestamp_(generateFileSize(filename)) {};
    int generateFileSize(string& filename);

    friend ostream& operator<<(ostream& os, const file& rhs);
};