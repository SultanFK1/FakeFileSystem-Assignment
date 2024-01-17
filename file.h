#pragma once
#include "FileEntity.h"
#include <iostream>
#include <cstdlib>

class File : public FileEntity {
private:
    int entitySize_;

public:
    //Constructor for parsing the initial entities into root directory. 
    File(const std::string& filename, int size)
        : FileEntity(filename), entitySize_(size) {}

    //Constructor when adding a new file
    File(const std::string& filename)
        : FileEntity(filename), entitySize_(generateEntitySize()) {}

    int generateEntitySize() const override {
        // Random number generation
        return std::rand() + 1; // Random positive number
    }

    void displayDetails() const override 
    {
        std::cout << "\t\t " << getName() <<  " \t" << entitySize_ << " bytes\t" << "\t";
        std::cout << std::endl;
    
    }

};
