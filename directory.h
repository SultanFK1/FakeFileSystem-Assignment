#pragma once
#include <vector>
#include <iostream>
#include "FileEntity.h"



class Directory : public FileEntity {

private:
    std::vector<FileEntity*> contents;

public:
    Directory(const std::string& name, const tm& timestamp)
        : FileEntity(name, timestamp) {}

    Directory(const std::string& name)
        : FileEntity(name) {}

    ~Directory() {
        for (auto& entity : contents) {
            delete entity;
        }
    }

    void addFileEntity(FileEntity* entity) {
        contents.push_back(entity);
    }


    int generateEntitySize() const override {
        int totalSize = 0;
        for (const auto& entity : contents) {
            totalSize += entity->generateEntitySize();
        }
        return totalSize;
    }

    void displayDetails() const override {
        std::cout << "Directory: " << getName() << " (Total Size: " << generateEntitySize() << ")\n";
        for (const auto& entity : contents) {
            entity->displayDetails();
        }
    }

};
