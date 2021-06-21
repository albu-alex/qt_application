//
// Created by SL15 on 21.06.2021.
//

#include "Service.h"

Service::Service(const ProgrammerRepository &_programmerRepository,
                 const SourceFileRepository &_sourceFileRepository):programmerRepository(_programmerRepository),sourceFileRepository(_sourceFileRepository)
                 {this->sourceFileRepository.load_from_file();}


bool Service::addSourceFile(const std::string &name, const Programmer& creatorProgrammer) {
    Programmer reviewerProgrammer;
    SourceFile new_sourceFile{name, "not_revised", creatorProgrammer, reviewerProgrammer};
    return this->sourceFileRepository.add(new_sourceFile);
}

void Service::reviseSourceFile(const std::string &name) {
    std::vector<SourceFile> sourceFiles = this->sourceFileRepository.get_sourceFiles();
    for(auto s : sourceFiles)
        if(s.get_name() == name){
            s.get_reviewerProgrammer().increment_revised_files();
            return;
        }
}