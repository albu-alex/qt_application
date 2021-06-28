//
// Created by SL15 on 28.06.2021.
//

#include "Statistics.h"

Statistics::Statistics(ProgrammerRepository &_programmerRepository, SourceFileRepository &_sourceFileRepository,
                       QWidget *parent):programmerRepository(_programmerRepository), sourceFileRepository(_sourceFileRepository),
                                        QWidget(parent) {
    this->sourceFileRepository.addObserver(this);
    this->setWindowTitle(QString::fromStdString("Statistics"));
    this->show();
}

void Statistics::update() {
    this->repaint();
}

void Statistics::paintEvent(QPaintEvent *event) {
    this->x=0;
    this->y=0;
    for(auto programmer : this->programmerRepository.get_programmers())
        this->drawCircle(programmer);
}

void Statistics::drawCircle(Programmer &programmer) {
    QPainter painter{this};
    if(programmer.get_revisedFiles() >= programmer.get_mustRevise()){
        QPen pen{Qt::darkBlue, 1, Qt::SolidLine, Qt::RoundCap};
        painter.setPen(pen);
        QBrush brush{Qt::blue, Qt::FDiagPattern};
        painter.setBrush(brush);
    }
    else{
        QPen pen{Qt::black, 1, Qt::SolidLine, Qt::RoundCap};
        painter.setPen(pen);
        QBrush brush{Qt::black, Qt::FDiagPattern};
        painter.setBrush(brush);
    }
    int size = programmer.get_revisedFiles();
    this->x+=size*5;
    this->y+=size*5;
    QString name = QString::fromStdString(programmer.get_name());
    painter.drawEllipse(this->x,this->y, size*10, size*10);
    painter.drawText(this->x+size*15,this->y+size*5, name);
    this->y+=size*10;
    this->x=0;
}

QSize Statistics::sizeHint() const {
    return QSize{600, 400};
}

void Statistics::resizeEvent(QResizeEvent *event) {
    this->x=0;
    this->y=0;
}