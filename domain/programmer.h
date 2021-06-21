//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_PROGRAMMER_H
#include <string>
#define QT_PROGRAMMER_H


class Programmer{
private:
    std::string name;
    int revisedFiles;
    int mustRevise;
public:
    Programmer(){;}
    Programmer(const std::string& _name, const int& _revisedFiles, const int& _mustRevise);
    ~Programmer(){;}
    friend std::istream& operator>>(std::istream& input, Programmer& programmer);
    friend std::ostream& operator<<(std::ostream& output, const Programmer& programmer);
    bool operator ==(const Programmer& other_programmer);
    bool operator !=(const Programmer& other_programmer);
    void increment_revised_files();
    std::string get_name() const;
    int get_revisedFiles() const;
    int get_mustRevise() const;
    void set_name(const std::string& _name);
    void set_revisedFiles(const int& _revisedFiles);
    void set_mustRevise(const int& _mustRevise);
};


#endif //QT_PROGRAMMER_H
