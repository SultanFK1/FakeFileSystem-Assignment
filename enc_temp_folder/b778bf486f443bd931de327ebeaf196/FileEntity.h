#pragma once
#include <string>
#include <ctime>

class FileEntity {
protected:
    std::string name_;
    tm timestamp_;

public:
    FileEntity(std::string name, const tm& timestamp)
        : name_(std::move(name)), timestamp_(timestamp) {}

    FileEntity(std::string name)
        : name_(std::move(name)), timestamp_({}) {}

    virtual ~FileEntity() {}

    const std::string& getName() const { return name_; }
    const tm& getTimestamp() const { return timestamp_; }

    virtual void displayDetails() const = 0;
    virtual int generateEntitySize() const = 0;  // Virtual method for entity size
};
