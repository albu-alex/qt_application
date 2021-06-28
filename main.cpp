//
// Created by SL15 on 21.06.2021.
//

#include "GUI.h"
#include <QtWidgets>
int main(int argc, char** argv){
    QApplication a(argc, argv);
    SourceFileRepository sourceFileRepository{};
    ProgrammerRepository programmerRepository{};
    programmerRepository.load_from_file();
    std::vector<Programmer> programmers = programmerRepository.get_programmers();
    std::vector<Service*> services;
    std::vector<GUI*> gui;
    for(int i=0;i<programmers.size();i++)
        gui.push_back(new GUI{programmers[i], sourceFileRepository});
    return a.exec();
}

