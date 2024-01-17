/*
 * This is the starting project for the Advanced Programming assessment - 2023-4
 * This project enumerates just the directory specified and does not descend into subdirectories
*/

#include <crtdbg.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <filesystem>  // file system needs cpp standard 17 or above.  This is enabled in this project, but if you recreated from scratch, set -std=c++17 flags
#include "FakeFileSystem.h"
#include "FileEntity.h"
#include"file.h"
#include"directory.h"

#include <memory>
#include<string.h>
#include <ctime>

using namespace std;

// function prototype of a helper method to convert timestamps
const tm convertTime(const filesystem::file_time_type& timestamp);


void initializeFileSystem(const std::string& path, Directory* currentDir) {
    for (const auto& item : filesystem::directory_iterator(path)) {
        tm timestamp = convertTime(item.last_write_time());
        string name = item.path().filename().string();

        if (item.is_directory()) {
            Directory* newDir = FileManager::createDirectory(name, timestamp, currentDir);
            initializeFileSystem(item.path().string(), newDir); // Recursive call for subdirectories
        }
        else {
            __int64 filesize = item.file_size();
            FileManager::createFile(name, static_cast<int>(filesize), currentDir);
        }
    }
}


// C++ entry point
int main() {

    const char* path = "C:\\Users\\s\\Desktop\\FakeFileSystem - C2026900\\TestEnvironment";
    Directory* rootDirectory = new Directory("Root", {});
    initializeFileSystem(path, rootDirectory); // Initialize file system starting from root
    cout << "Initialisation complete..." << endl;



    cout << "Here is a list of files in: " << path << "\n\n";

    for (const filesystem::directory_entry& item : filesystem::directory_iterator(path)) {
        tm timestamp = convertTime(item.last_write_time());
        string name = item.path().filename().string();

       if (item.is_directory()) {
          FileManager::createDirectory(name, timestamp, rootDirectory); // Logic to determine parentDir may be needed
          }
       else{
         __int64 filesize = item.file_size();
                FileManager::createFile(name, static_cast<int>(filesize), rootDirectory );
          }
       }

        // Assuming you want to create a File. If you want a Directory, use Directory class instead.
        string name1 = "Sos";
        string name2 = "SOs";
        File* testFile = new File(name1);// Replace with Directory if you want a directory instead. 
        Directory* testFile1 = new Directory(name2);
        rootDirectory->addFileEntity(testFile);
        rootDirectory->addFileEntity(testFile1);
        FileManager::listFilesAndDirectories(rootDirectory);
        
        string input;
        do {
            cin >> input;
        } while (input != "exit");

        delete rootDirectory;
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
