//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_SOURCEFILEREPOSITORY_H
#include "Repository.h"
#include "Observer.h"
#include <fstream>
#define QT_SOURCEFILEREPOSITORY_H


class SourceFileRepository: public Repository<SourceFile>,public ObserverWindow{
private:
    std::vector<SourceFile> sourceFiles;
    void save_to_file() override;
public:
    SourceFileRepository(){;};
    ~SourceFileRepository() override{;}
    void load_from_file() override;
    bool add(const SourceFile& sourceFile) override;
    void reviseFile(SourceFile& sourceFile);
    std::vector<SourceFile> get_sourceFiles() const;
};


#endif //QT_SOURCEFILEREPOSITORY_H
