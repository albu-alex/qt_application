//
// Created by SL15 on 21.06.2021.
//

#include "programmer.h"

Programmer::Programmer(const std::string &_name, const int &_revisedFiles, const int &_mustRevise):
name(_name),revisedFiles(_revisedFiles),mustRevise(_mustRevise){;}

std::istream& operator>>(std::istream& input, Programmer& programmer){
    std::string revisedFiles, mustRevise;

    std::getline(input ,programmer.name, ',');
    std::getline(input, revisedFiles, ',');
    std::getline(input, mustRevise, ',');

    if(!revisedFiles.empty() && !mustRevise.empty()){
        programmer.revisedFiles = std::stoi(revisedFiles);
        programmer.mustRevise = std::stoi(mustRevise);
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Programmer& programmer){
    std::string programmer_to_string = programmer.name + "," + std::to_string(programmer.revisedFiles) + "," +
            std::to_string(programmer.mustRevise);
    output << programmer_to_string;
    return output;
}