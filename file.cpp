#include "file.h"
#include <cstdlib> // For srand and rand
#include <ctime>   // For time
#include <iostream>

using namespace std;
// Seed the random number generator outside of any function


// Generate a random file size
int file::generateFileSize(string& filename)
{
    int fileSize = rand() + 1;
    return fileSize;
}


ostream& operator<<(ostream& os, const file& rhs) {
    os << rhs.filename_;
    os << rhs.filesize_;
    return os;
}