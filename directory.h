#pragma once
#include <vector>
#include <iostream>
#include "FileEntity.h"
#include <algorithm>

class Directory : public FileEntity {
private:
    std::vector<FileEntity*> contents;  // Contents of the directory (files and subdirectories)
    Directory* parent; 
    tm timestamp_; 

public:
    // Constructor for parsed files with a specified timestamp
    Directory(const std::string& name, const tm& timestamp, Directory* parentDir = nullptr)
        : FileEntity(name, timestamp), parent(parentDir), timestamp_(timestamp) {}

    // Constructor for generated files with a generated timestamp
    Directory(const std::string& name, Directory* parentDir = nullptr)
        : FileEntity(name, {}), parent(parentDir), timestamp_(generateTimestamp()) {}

    // Destructor to clean up dynamically allocated memory
    ~Directory() {
        for (auto& entity : contents) {
            delete entity;
        }
    }


    std::vector<FileEntity*>& getContents();


    Directory* getParent() const;

    // Static method to generate a timestamp for a directory
     static tm generateTimestamp();

    // Method to add a file entity (file or subdirectory) to the directory
    void addFileEntity(FileEntity* entity);

    // Override of the base class method to calculate the size of the directory
     int generateEntitySize() const override;

    // Method to display the timestamp of the directory
     void displayTimestamp() const;

    // Override of the base class method to display details of the directory
    void displayDetails() const override;

    // Method to sort the contents of the directory by size
    void sortsize();

    // Method to sort the contents of the directory by name
    void sortname();


    void displayPath() const;
};
