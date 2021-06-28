//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_PROGRAMMERREPOSITORY_H
#include "Repository.h"
#include "Observer.h"
#include <fstream>
#define QT_PROGRAMMERREPOSITORY_H


class ProgrammerRepository: public Repository<Programmer>, public ObserverWindow{
private:
    std::vector<Programmer> programmers;
    void save_to_file() override;
public:
    ProgrammerRepository(){;}
    ~ProgrammerRepository(){;}
    bool add(const Programmer& programmer) override;
    void load_from_file() override;
    std::vector<Programmer> get_programmers() const;
};


#endif //QT_PROGRAMMERREPOSITORY_H
