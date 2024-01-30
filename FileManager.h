// FileManager.h
#pragma once
#include "Directory.h"
#include "File.h"
#include <ctime>

class FileManager {
private:
    // Static member to keep track of the current directory
    inline static Directory* currentDir = nullptr;

public:

    inline static Directory* getCurrentDirectory() {
        return currentDir;
    }


    inline static void setCurrentDirectory(Directory* dir) {
        currentDir = dir;
    }

    // Parses a file and adds it to the current directory
    static File* ParseFile(const std::string& filename, int size, Directory* currentDir);

    // Parses a directory and adds it to the current directory
    static Directory* parseDirectory(const std::string& name, const tm& timestamp, Directory* currentDir);

    // Generates a new directory and adds it to the current directory
    static Directory* GenerateDirectory(const std::string& name, Directory* currentDir);

    // Generates a new file and adds it to the current directory
    static File* GenerateFile(const std::string& filename, Directory* currentDir);

    // Sorts the current directory by size
    static void sortSizeCommand(Directory* currentDir);

    // Sorts the current directory by name
    static void sortNameCommand(Directory* currentDir);

    // Deletes an entity (file or directory) from the current directory
    static void deleteEntity(const std::string& entityName);

    // Displays the contents of the current directory
    static void dirCommand();

    // Changes the current directory to the specified directory
    static void changeDirectory(const std::string& dirName);
};

