// FileEntity.h
#pragma once
#include <string>
#include <ctime>
#include <iostream>

class FileEntity {
protected:
    std::string name_;  // Name of the file entity

public:
    // Constructor for a file entity with a specified name and timestamp
    FileEntity(std::string name, const tm& timestamp)
        : name_(std::move(name)) {}

    // Constructor for a file entity with a specified name
    FileEntity(std::string name)
        : name_(std::move(name)) {}

    // Virtual destructor for proper cleanup in derived classes
    virtual ~FileEntity() {}

    // Getter for the name of the file entity
    const std::string& getName() const { return name_; }

    // Abstract method to display details of the file entity (to be implemented in derived classes)
    virtual void displayDetails() const = 0;

    // Abstract method to generate the size of the file entity (to be implemented in derived classes)
    virtual int generateEntitySize() const = 0;

    
};
