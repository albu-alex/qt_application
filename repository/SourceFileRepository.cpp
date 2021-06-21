//
// Created by SL15 on 21.06.2021.
//

#include "SourceFileRepository.h"

bool SourceFileRepository::add(const SourceFile &sourceFile) {
    for(auto s : this->sourceFiles)
        if(s == sourceFile)
            return false;
    this->sourceFiles.push_back(sourceFile);
    return true;
}

void SourceFileRepository::load_from_file() {
    std::ifstream input;
    input.open("D:\\clion_projects\\qt_application\\sources.txt");
    if(!input.is_open())
        throw std::runtime_error("File could not open correctly!");
    SourceFile new_sourceFile;
    while(!input.eof() && input >> new_sourceFile)
        this->add(new_sourceFile);
    input.close();
}

void SourceFileRepository::save_to_file() {
    std::ofstream output("D:\\clion_projects\\qt_application\\sources.txt");
    if(!output.is_open())
        throw std::runtime_error("File could not open correctly!");
    for(const auto& sourceFile:this->sourceFiles)
        if(&sourceFile == &this->sourceFiles.back())
            output << sourceFile;
        else
            output << sourceFile << std::endl;
    output.close();
}

std::vector<SourceFile> SourceFileRepository::get_sourceFiles() const {
    return this->sourceFiles;
}