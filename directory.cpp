// Directory.cpp
#include <iostream>
#include "Directory.h"
#include <algorithm>

std::vector<FileEntity*>& Directory::getContents() {
    return contents;
}

Directory* Directory::getParent() const {
    return parent;
}

 tm Directory::generateTimestamp() {
    time_t now = time(nullptr);
    tm newTimestamp;
    localtime_s(&newTimestamp, &now); // Convert time_t to tm struct
    return newTimestamp;
}

void Directory::addFileEntity(FileEntity* entity) {
    // Check for duplicate entity
    for (const auto& existingEntity : contents) {
        if (existingEntity->getName() == entity->getName()) {
            std::cout << "Error: An entity named '" << entity->getName() << "' already exists in this directory." << std::endl;
            return; // Do not add the entity
        }
    }

    // Add the entity if no duplicate found
    contents.push_back(entity);
    if (Directory* dir = dynamic_cast<Directory*>(entity)) {
        dir->parent = this; // Set this directory as the parent of the added directory
    }
}

int Directory::generateEntitySize() const {
    int totalSize = 0;
    for (const auto& entity : contents) {
        totalSize += entity->generateEntitySize();
    }
    return totalSize;
}

void Directory::displayTimestamp() const
{
    std::cout << timestamp_.tm_year + 1900 << "-"
        << timestamp_.tm_mon + 1 << "-"
        << timestamp_.tm_mday << " " << timestamp_.tm_hour << " : " << timestamp_.tm_min;
}

void Directory::displayDetails() const {
    std::cout << "<DIR>\t" << getName() << "\t" << "Total Size: " << generateEntitySize() << "\t";

    displayTimestamp();
    std::cout << std::endl;
}

void Directory::sortsize() {
    std::sort(contents.begin(), contents.end(), [](const FileEntity* a, const FileEntity* b) {
        // Directories always come first
        const Directory* dirA = dynamic_cast<const Directory*>(a);
        const Directory* dirB = dynamic_cast<const Directory*>(b);

        if (dirA && !dirB) return true; // a is a directory, b is not
        if (!dirA && dirB) return false; // b is a directory, a is not

        // If both are files or both are directories, sort by size
        return a->generateEntitySize() < b->generateEntitySize();
        });
}

void Directory::sortname() {
    std::sort(contents.begin(), contents.end(), [](const FileEntity* a, const FileEntity* b) {
        return a->getName() < b->getName();
        });
}

void Directory::displayPath() const {
    if (parent) {
        parent->displayPath();
    }
    std::cout << "/" << name_;
}

