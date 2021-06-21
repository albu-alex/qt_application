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
    std::getline(input, mustRevise, '\n');

    if(!revisedFiles.empty() && !mustRevise.empty()){
        programmer.revisedFiles = std::stoi(revisedFiles);
        programmer.mustRevise = std::stoi(mustRevise);
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Programmer& programmer){
    std::string programmer_to_string = programmer.name + "," + std::to_string(programmer.revisedFiles) + "," +
            std::to_string(programmer.mustRevise) + "\n";
    output << programmer_to_string;
    return output;
}

bool Programmer::operator==(const Programmer &other_programmer) {
    return this->name == other_programmer.name;
}

bool Programmer::operator!=(const Programmer &other_programmer) {
    return this->name != other_programmer.name;
}

void Programmer::increment_revised_files() {
    this->revisedFiles++;
}

std::string Programmer::get_name() const {
    return this->name;
}

int Programmer::get_mustRevise() const {
    return this->mustRevise;
}

int Programmer::get_revisedFiles() const {
    return this->revisedFiles;
}

void Programmer::set_name(const std::string& _name) {
    this->name = _name;
}

void Programmer::set_revisedFiles(const int &_revisedFiles) {
    this->revisedFiles = _revisedFiles;
}

void Programmer::set_mustRevise(const int &_mustRevise) {
    this->mustRevise = _mustRevise;
}