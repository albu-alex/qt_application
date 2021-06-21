//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_SOURCEFILE_H
#include "programmer.h"
#define QT_SOURCEFILE_H


class SourceFile {
private:
    std::string name;
    std::string status;
    Programmer creator;
    Programmer reviewer;
public:
    SourceFile(const std::string& _name, const std::string& _status, const Programmer& _creator, const Programmer& _reviewer);
    ~SourceFile(){;}
    friend std::istream& operator>>(std::istream& input, SourceFile& sourceFile);
    friend std::ostream& operator<<(std::ostream& output, const SourceFile& sourceFile);
};


#endif //QT_SOURCEFILE_H
