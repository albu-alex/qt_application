//
// Created by SL15 on 21.06.2021.
//

#include "SourceFile.h"

SourceFile::SourceFile(const std::string &_name, const std::string &_status, const Programmer &_creator,
                       const Programmer &_reviewer):name(_name),status(_status), creator(_creator), reviewer(_reviewer) {;}


std::istream& operator>>(std::istream& input, SourceFile& sourceFile){
    std::getline(input, sourceFile.name, ',');
    std::getline(input, sourceFile.status, '\n');
    input >> sourceFile.creator;
    input >> sourceFile.reviewer;
    return input;
}

std::ostream& operator<<(std::ostream& output, const SourceFile& sourceFile){
    std::string sourceFileToString = sourceFile.name + "," + sourceFile.status + "\n";
    output << sourceFileToString << sourceFile.creator << sourceFile.reviewer;
    return output;
}

bool SourceFile::operator==(const SourceFile &sourceFile) {
    return this->name == sourceFile.name;
}

bool SourceFile::operator!=(const SourceFile &sourceFile) {
    return this->name != sourceFile.name;
}

std::string SourceFile::get_name() const {
    return this->name;
}

Programmer SourceFile::get_reviewerProgrammer() const {
    return this->reviewer;
}

Programmer SourceFile::get_creatorProgrammer() const {
    return this->creator;
}

std::string SourceFile::get_status() const {
    return this->status;
}

void SourceFile::set_name(const std::string _name) {
    this->name = _name;
}

void SourceFile::set_status(const std::string _status) {
    this->status = _status;
}