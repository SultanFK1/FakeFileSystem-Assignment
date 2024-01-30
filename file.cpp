#pragma once
#include "file.h"
#include <iostream>
#include <cstdlib>


    int File::generateFileSize() {
        // Random number generation
        return std::rand() + 1; // Random positive number
    }

    int File::generateEntitySize() const   {
        return entitySize_;  // Return the fixed size of the file
    }

    void File::displayDetails() const 
    {
        std::cout << "\t\t " << getName() << " \t" << entitySize_ << " bytes\t" << "\t";
        std::cout << std::endl;

    }

