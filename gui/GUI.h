//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_GUI_H
#include "Service.h"
#include "Observer.h"
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
#include <QMessageBox>
#include "AbstractModel.h"
#define QT_GUI_H


class GUI: public QWidget,public Observer{
    Q_OBJECT
private:
    Service& service;
    AbstractModel* table;
    QTableView* table_view;
    QPushButton* revision, *add;
    QLineEdit* file_name;
    std::vector<SourceFile> sourceFiles;
    void init_gui();
    void connect_signal_and_slots();
    void revisionButton_handler();
    void notify_model();
    void checkIfReviseAvailable();
public:
    explicit GUI(Service& _service, QWidget* parent= nullptr);
    ~GUI() override{;}
    void update() override;
public slots:
    void addButton_handler();
};


#endif //QT_GUI_H
