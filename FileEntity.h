#pragma once
#include <string>
#include <ctime>
#include<iostream>

class FileEntity {
protected:
    std::string name_;


public:
    FileEntity(std::string name, const tm& timestamp)
        : name_(std::move(name)) {}

    FileEntity(std::string name)
        : name_(std::move(name)) {}

    virtual ~FileEntity() {}

    const std::string& getName() const { return name_; }

    virtual void displayDetails() const = 0;
    virtual int generateEntitySize() const = 0;


};
