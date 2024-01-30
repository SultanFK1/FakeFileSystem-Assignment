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

    //Constructor when generating a new file
    File(const std::string& filename)
        : FileEntity(filename), entitySize_(generateFileSize()) {}

    int generateFileSize();

    int generateEntitySize() const override;

    void displayDetails() const override;

};
