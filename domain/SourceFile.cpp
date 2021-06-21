//
// Created by SL15 on 21.06.2021.
//

#include "SourceFile.h"

SourceFile::SourceFile(const std::string &_name, const std::string &_status, const Programmer &_creator,
                       const Programmer &_reviewer):name(_name),status(_status), creator(_creator), reviewer(_reviewer) {;}


std::istream& operator>>(std::istream& input, SourceFile& sourceFile){
    std::getline(input, sourceFile.name, ',');
    std::getline(input, sourceFile.status, ',');
    input >> sourceFile.creator;
    input >> sourceFile.reviewer;
    return input;
}

std::ostream& operator<<(std::ostream& output, const SourceFile& sourceFile){
    std::string sourceFileToString = sourceFile.name + "," + sourceFile.status + ",";
    output << sourceFileToString << sourceFile.creator << sourceFile.reviewer;
    return output;
}