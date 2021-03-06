//
// Created by SL15 on 21.06.2021.
//

#include "Service.h"

Service::Service(Programmer &_programmer,
                 SourceFileRepository &_sourceFileRepository):programmer(_programmer),sourceFileRepository(_sourceFileRepository)
                 {this->sourceFileRepository.load_from_file();}


void Service::addSourceFile(const std::string &name, const Programmer& creatorProgrammer) {
    Programmer reviewerProgrammer;
    SourceFile new_sourceFile{name, "not_revised", creatorProgrammer, reviewerProgrammer};
    this->sourceFileRepository.add(new_sourceFile);
    this->sourceFileRepository.load_from_file();
}

void Service::reviseSourceFile(const std::string &name) {
    std::vector<SourceFile> sourceFiles = this->sourceFileRepository.get_sourceFiles();
    for(auto s : sourceFiles)
        if(s.get_name() == name){
            s.get_reviewerProgrammer().increment_revised_files();
            s.set_status("revised");
            return;
        }
}

std::vector<SourceFile> Service::get_sourceFileRepository() const {
    return this->sourceFileRepository.get_sourceFiles();
}

Programmer Service::get_programmer() const {
    return this->programmer;
}