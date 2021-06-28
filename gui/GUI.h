//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_GUI_H
#include "Service.h" //useless
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
    Programmer& programmer;
    SourceFileRepository& sourceFileRepository;
    QLineEdit* file_name;
    QVBoxLayout* main;
    QGridLayout* buttons;
    AbstractModel* table;
    QTableView* table_view;
    QSortFilterProxyModel* filterProxyModel;
    QPushButton* add, *revise;
public:
    explicit GUI(Programmer& _programmer, SourceFileRepository& _sourceFileRepository, QWidget* parent = nullptr);
    ~GUI() override{this->sourceFileRepository.removeObserver(this);}
    void init_gui();
    void connect_signal_and_slots();
    void update() override;
    void notify_model();
    void revisionButton_handler();
    int get_selected_index();
public slots:
    void addButton_handler();
};


#endif //QT_GUI_H
