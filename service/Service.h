//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_SERVICE_H
#include "SourceFileRepository.h"
#include "ProgrammerRepository.h"
#define QT_SERVICE_H


class Service {
private:
    ProgrammerRepository programmerRepository;
    SourceFileRepository sourceFileRepository;
public:
    Service(const ProgrammerRepository& _programmerRepository, const SourceFileRepository& _sourceFileRepository);
    ~Service(){;}
    bool addSourceFile(const std::string& name, const Programmer& creatorProgrammer);
    void reviseSourceFile(const std::string& name);
    std::vector<SourceFile> get_sourceFileRepository() const;
};


#endif //QT_SERVICE_H
