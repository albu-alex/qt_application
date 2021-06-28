//
// Created by SL15 on 28.06.2021.
//

#ifndef QT_STATISTICS_H
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include "SourceFileRepository.h"
#include "ProgrammerRepository.h"
#include "Observer.h"
#include "AbstractModel.h"
#define QT_STATISTICS_H


class Statistics: public QWidget, public Observer{
private:
    ProgrammerRepository& programmerRepository;
    SourceFileRepository& sourceFileRepository;
    int x=0;
    int y=0;
public:
    Statistics(ProgrammerRepository& _programmerRepository, SourceFileRepository& _sourceFileRepository, QWidget* parent= nullptr);
    ~Statistics(){;};
    void update() override;
    QSize sizeHint() const override;
    void drawCircle(Programmer& p);
    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent* event);
};


#endif //QT_STATISTICS_H
