// FileManager.h
#pragma once
#include "Directory.h"
#include "File.h"
#include <ctime>

class FileManager {
private:

public:
    static File* createFile(const std::string& filename, int size, Directory* currentDir) {
        File* newFile = new File(filename, size);
        currentDir->addFileEntity(newFile);
        return newFile;
    }

    static Directory* createDirectory(const std::string& name, const tm& timestamp, Directory* currentDir) {
        Directory* newDirectory = new Directory(name, timestamp, currentDir);
        currentDir->addFileEntity(newDirectory);
        return newDirectory;
    } 

    static void listFilesAndDirectories(const Directory* currentDir) {
        if (currentDir) {
            currentDir->displayDetails();
        }
    }
    static File* addFile(const std::string& filename, int size, Directory* currentDir) {
        File* newFile = new File(filename, size);
        currentDir->addFileEntity(newFile);
        return newFile;
    }

};

