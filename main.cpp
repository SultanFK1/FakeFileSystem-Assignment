/*
 * This is the starting project for the Advanced Programming assessment - 2023-4
 * This project enumerates just the directory specified and does not descend into subdirectories
*/

#include <crtdbg.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <filesystem>  // file system needs cpp standard 17 or above.  This is enabled in this project, but if you recreated from scratch, set -std=c++17 flags
#include "FileManager.h"
#include "FileEntity.h"
#include"file.h"
#include"directory.h"

#include <memory>
#include<string.h>
#include <ctime>
#include <unordered_map>
#include <functional>
#include <sstream>

using namespace std;

// function prototype of a helper method to convert timestamps
const tm convertTime(const filesystem::file_time_type& timestamp);


void initializeFileSystem(const std::string& path, Directory* currentDir) {
    for (const auto& item : filesystem::directory_iterator(path)) {
        tm timestamp = convertTime(item.last_write_time());
        string name = item.path().filename().string();

        if (item.is_directory()) {
            Directory* newDir = FileManager::parseDirectory(name, timestamp, currentDir);
            initializeFileSystem(item.path().string(), newDir); // Recursive call for subdirectories
        }
        else {
            __int64 filesize = item.file_size();
            FileManager::ParseFile(name, static_cast<int>(filesize), currentDir);
        }
    }
    cout << "Initializing..." << endl;
}



int main() {


#ifdef _DEBUG
    // make sure we are checking for memory leaks when the application ends, but only in the _DEBUG variant
    _onexit(_CrtDumpMemoryLeaks);
#endif
    std::srand(static_cast<unsigned int>(std::time(0)));
    const char* path = "C:\\Users\\s\\Desktop\\FakeFileSystem - C2026900\\TestEnvironment";
    Directory* rootDirectory = new Directory("Root", {});
    FileManager::setCurrentDirectory(rootDirectory); // Set current directory to root at the start
    initializeFileSystem(path, rootDirectory); // Initialize file system starting from root
    cout << "Complete..." << endl;



    unordered_map<string, function<void()>> noArgCommands = {
          {"dir", []() { FileManager::dirCommand(); }}
    };

    unordered_map<string, function<void(const string&)>> singleArgCommands = {
        {"mkfile", [](const string& arg) { FileManager::GenerateFile(arg, FileManager::getCurrentDirectory()); }},
        {"mkdir", [](const string& arg) { FileManager::GenerateDirectory(arg, FileManager::getCurrentDirectory()); }},
        {"cd", [](const string& arg) { FileManager::changeDirectory(arg); }},
        {"del", [](const string& arg) { FileManager::deleteEntity(arg); }}
    };

    unordered_map<string, function<void()>> sortCommands = {
        {"sortsize", []() { FileManager::sortSizeCommand(FileManager::getCurrentDirectory()); }},
        {"sortname", []() { FileManager::sortNameCommand(FileManager::getCurrentDirectory()); }}
    };


    // Two argument commands (example: {"command", [](const string& arg1, const string& arg2) { ... }})
    unordered_map<string, function<void(const string&, const string&)>> twoArgCommands{}; 
    // Add two-argument commands if needed

    string input, command, arg1, arg2;
    do {
        FileManager::getCurrentDirectory()->displayPath();
        cout << "> ";

        getline(cin, input);
        stringstream ss(input);
        ss >> command >> arg1 >> arg2;

        if (noArgCommands.find(command) != noArgCommands.end()) {
            noArgCommands[command]();
        }
        else if (singleArgCommands.find(command) != singleArgCommands.end()) {
            singleArgCommands[command](arg1);
        }
        else if (sortCommands.find(command) != sortCommands.end()) {
            sortCommands[command]();
        }
        else if (twoArgCommands.find(command) != twoArgCommands.end()) {
            twoArgCommands[command](arg1, arg2);
        }

    } while (command != "exit");


    return 0;
}


// we need to do a little conversion between what the filesystem returns for time stamps and something usable
// just use this function and don't worry about how it works

const tm convertTime(const filesystem::file_time_type& timestamp)
{

  using namespace chrono;  // just for this function, use chrono to save us prefixing chrono:: everywhere
  system_clock::time_point delta=time_point_cast<system_clock::duration>(timestamp-filesystem::file_time_type::clock::now()+system_clock::now());
  time_t conversion=system_clock::to_time_t(delta);

  tm result;
  localtime_s(&result, &conversion);
  return result;

}
