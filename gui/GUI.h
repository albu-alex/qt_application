//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_GUI_H
#include "Service.h"
#include <QWidget>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QTableView>
#include <QMainWindow>
#include <qstringlistmodel.h>
#include <QSortFilterProxyModel>
#define QT_GUI_H


class GUI: public QWidget{
    Q_OBJECT
private:
    Service service;
public:
    explicit GUI(const Service& _service, QWidget* parent= nullptr);
    ~GUI() override{;}
};


#endif //QT_GUI_H
