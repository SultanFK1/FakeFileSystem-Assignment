#pragma once
#include <vector>
#include <iostream>
#include "FileEntity.h"



class Directory : public FileEntity {
private:
    std::vector<FileEntity*> contents;
    Directory* parent; // Pointer to the parent directory
    tm timestamp_;

public:

    Directory(const std::string& name, const tm& timestamp, Directory* parentDir = nullptr)
        : FileEntity(name, timestamp), parent(parentDir), timestamp_(timestamp) {}

    Directory(const std::string& name, Directory* parentDir = nullptr)
        : FileEntity(name, {}), parent(parentDir), timestamp_({}) {}

    ~Directory() {
        for (auto& entity : contents) {
            delete entity;
        }
    }

    void addFileEntity(FileEntity* entity) {
        contents.push_back(entity);
        if (Directory* dir = dynamic_cast<Directory*>(entity)) {
            dir->parent = this; // Set this directory as the parent of the added directory
        }
    }

    int generateEntitySize() const override {
        int totalSize = 0;
        for (const auto& entity : contents) {
            totalSize += entity->generateEntitySize();
        }
        return totalSize;
    }

    void displayTimestamp() const
    {
        std::cout << timestamp_.tm_year + 1900 << "-"
            << timestamp_.tm_mon + 1 << "-"
            << timestamp_.tm_mday << " " << timestamp_.tm_hour << " : " << timestamp_.tm_hour;

    }

    void displayDetails() const override {
        std::cout << "<DIR>\t" << getName() << "\t" << "Total Size: " << generateEntitySize() << "\t";

        displayTimestamp();
        std::cout << std::endl;
        
        for (const auto& entity : contents) {
            entity->displayDetails();
        }
    }



};
