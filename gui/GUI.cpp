//
// Created by SL15 on 21.06.2021.
//

#include "GUI.h"

void GUI::init_gui() {
    QVBoxLayout* main = new QVBoxLayout{this};

    this->file_name = new QLineEdit{};
    this->add = new QPushButton{"Add"};
    this->revision = new QPushButton{"Revise Source File"};

    std::vector<SourceFile> sourceFiles = this->service.get_sourceFileRepository();
    this->table = new AbstractModel{sourceFiles};
    this->table_view = new QTableView{};
    this->table_view->setModel(this->table);
    this->table_view->resizeRowsToContents();
    this->table_view->resizeColumnsToContents();
    main->addWidget(this->table_view);

    QGridLayout* buttons = new QGridLayout{};
    buttons->addWidget(this->add, 0, 0);
    buttons->addWidget(this->revision, 0, 2);
    main->addLayout(buttons);

    QFormLayout* addNewFile = new QFormLayout{};
    addNewFile->addRow("New file name", this->file_name);
    main->addLayout(addNewFile);
}

void GUI::connect_signal_and_slots() {
    QObject::connect(this->revision, &QPushButton::clicked, this, &GUI::revisionButton_handler);
    QObject::connect(this->add, &QPushButton::clicked, this, &GUI::addButton_handler);
}

GUI::GUI(const Service &_service, QWidget *parent): service(_service), QWidget(parent) {
    this->init_gui();
    this->connect_signal_and_slots();
}

void GUI::revisionButton_handler() {
    ;
}

void GUI::addButton_handler() {
    ;
}