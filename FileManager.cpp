// FileManager.h
#pragma once

#include "FileManager.h"
#include "File.h"
#include "Directory.h"
#include <ctime>




 File* FileManager::ParseFile(const std::string& filename, int size, Directory* currentDir) {
        File* newFile = new File(filename, size);
        currentDir->addFileEntity(newFile);
        return newFile;
    }

     Directory* FileManager::parseDirectory(const std::string& name, const tm& timestamp, Directory* currentDir) {
        Directory* newDirectory = new Directory(name, timestamp, currentDir);
        currentDir->addFileEntity(newDirectory);
        return newDirectory;
    }

     Directory* FileManager::GenerateDirectory(const std::string& name, Directory* currentDir) {
        Directory* newDirectory = new Directory(name, currentDir);
        currentDir->addFileEntity(newDirectory);
        return newDirectory;
    }

     File* FileManager::GenerateFile(const std::string& filename, Directory* currentDir) {
        File* newFile = new File(filename);
        currentDir->addFileEntity(newFile);
        return newFile;
    }

     void FileManager::sortSizeCommand(Directory* currentDir) {
        if (currentDir) {
            currentDir->sortsize();
        }
    }

    // Command to sort the current directory by name
     void FileManager::sortNameCommand(Directory* currentDir) {
        if (currentDir) {
            currentDir->sortname();
        }
    }

     void FileManager::deleteEntity(const std::string& entityName) {
        auto& contents = currentDir->getContents();
        auto it = std::find_if(contents.begin(), contents.end(), [&entityName](FileEntity* entity) {
            return entity->getName() == entityName;
            });

        if (it == contents.end()) {
            std::cout << "Error: Entity '" << entityName << "' does not exist." << std::endl;
        }
        else {
            delete* it;
            contents.erase(it);
        }
    }

     void FileManager::dirCommand() {
        if (currentDir) {

            system("cls");
            // Display the path
            currentDir->displayPath();
            std::cout << std::endl;

            // Display details of each entity in the current directory
            for (const auto& entity : currentDir->getContents()) {
                entity->displayDetails();
            }

            // Count and display the number of files and directories
            int fileCount = 0, dirCount = 0;
            for (const auto& entity : currentDir->getContents()) {
                if (dynamic_cast<Directory*>(entity)) dirCount++;
                else fileCount++;
            }
            std::cout << "\t" << fileCount << " File(s)\n";
            std::cout << "\t" << dirCount << " Dir(s)\n";


        }

    }
     void FileManager::changeDirectory(const std::string& dirName) {
        if (dirName == "..") {
            if (currentDir->getParent() != nullptr) {
                currentDir = currentDir->getParent();
            }
        }
        else {
            auto found = std::find_if(currentDir->getContents().begin(), currentDir->getContents().end(),
                [&dirName](FileEntity* entity) {
                    return dynamic_cast<Directory*>(entity) && entity->getName() == dirName;
                });
            if (found == currentDir->getContents().end()) {
                std::cout << "Error: Directory '" << dirName << "' does not exist." << std::endl;
            }
            else {
                currentDir = dynamic_cast<Directory*>(*found);
            }
        }
    }


