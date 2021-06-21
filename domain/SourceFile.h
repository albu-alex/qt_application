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
    SourceFile(){;}
    SourceFile(const std::string& _name, const std::string& _status, const Programmer& _creator, const Programmer& _reviewer);
    ~SourceFile(){;}
    friend std::istream& operator>>(std::istream& input, SourceFile& sourceFile);
    friend std::ostream& operator<<(std::ostream& output, const SourceFile& sourceFile);
    bool operator == (const SourceFile& sourceFile);
    bool operator != (const SourceFile& sourceFile);
    std::string get_name() const;
    std::string get_status() const;
    void set_name(const std::string name);
    void set_status(const std::string status);
    Programmer get_reviewerProgrammer() const;
    Programmer get_creatorProgrammer() const;
};


#endif //QT_SOURCEFILE_H
