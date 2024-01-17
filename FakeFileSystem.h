#pragma once
#include "File.h"
#include "Directory.h"
#include <ctime>


class FileManager {
private:


public:
    static Directory* rootDirectory;
    static File* createFile(const std::string& filename, int size, const tm& timestamp) {
        File* newFile = new File(filename, size, timestamp);
        rootDirectory->addFileEntity(newFile);
        return newFile;
    }

    static Directory* createDirectory(const std::string& name) {
        Directory* newDirectory = new Directory(name);
        rootDirectory->addFileEntity(newDirectory);
        return newDirectory;
    }

    static void listFilesAndDirectories() {
        if (rootDirectory) {
            rootDirectory->displayDetails();
        }
    }

    static void cleanup() {
        delete rootDirectory;
        rootDirectory = nullptr;
    }
};
Directory* FileManager::rootDirectory = nullptr; // Define the static member
