//
// Created by SL15 on 21.06.2021.
//

#include "GUI.h"
#include <QtWidgets>
int main(int argc, char** argv){
    QApplication a(argc, argv);
    SourceFileRepository sourceFileRepository{};
    ProgrammerRepository programmerRepository{};
    Service service{programmerRepository, sourceFileRepository};
    GUI gui{service};
    gui.show();
    return a.exec();
}

