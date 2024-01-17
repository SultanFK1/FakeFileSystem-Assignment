#pragma once
#include "FileEntity.h"
#include <iostream>
#include <cstdlib>

class File : public FileEntity {
private:
    int entitySize_;

public:
    File(const std::string& filename, int size, const tm& timestamp)
        : FileEntity(filename, timestamp), entitySize_(size) {}

    File(const std::string& filename)
        : FileEntity(filename), entitySize_(generateEntitySize()) {}

    int generateEntitySize() const override {
        // Random number generation
        return std::rand() + 1; // Random positive number
    }

    void displayDetails() const override {
        std::cout << "File: " << getName() << " Size: " << entitySize_
            << " Timestamp: Year: " << getTimestamp().tm_year + 1900
            << " Month: " << getTimestamp().tm_mon + 1
            << " Day: " << getTimestamp().tm_mday << std::endl;
    }
};
