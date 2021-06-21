//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_SERVICE_H
#include "SourceFileRepository.h"
#include "ProgrammerRepository.h"
#define QT_SERVICE_H


class Service {
private:
    Programmer programmer;
    SourceFileRepository sourceFileRepository;
public:
    Service(const Programmer& _programmer, const SourceFileRepository& _sourceFileRepository);
    ~Service(){;}
    bool addSourceFile(const std::string& name, const Programmer& creatorProgrammer);
    void reviseSourceFile(const std::string& name);
    std::vector<SourceFile> get_sourceFileRepository() const;
//    std::vector<Programmer> get_programmerRepository() const;
};


#endif //QT_SERVICE_H
