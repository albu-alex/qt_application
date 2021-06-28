//
// Created by SL15 on 21.06.2021.
//

#include "GUI.h"

GUI::GUI(Programmer &_programmer, SourceFileRepository &_sourceFileRepository, QWidget *parent):programmer(_programmer),sourceFileRepository(_sourceFileRepository),
                                                                                                QWidget(parent)
        {
            this->sourceFileRepository.load_from_file();
            this->sourceFileRepository.addObserver(this);
            this->init_gui();
            this->connect_signal_and_slots();
            this->show();
        }


void GUI::update() {
    this->notify_model();
}

void GUI::notify_model() {
    this->table->updateData();
}

void GUI::init_gui() {
    this->main = new QVBoxLayout{this};
    this->file_name = new QLineEdit{};
    this->add = new QPushButton{"Add"};
    this->revise = new QPushButton{"Revise File"};

    std::vector<SourceFile> sourceFiles = this->sourceFileRepository.get_sourceFiles();
    this->table = new AbstractModel{sourceFiles};
    this->table_view = new QTableView{};

    this->filterProxyModel = new QSortFilterProxyModel{};
    this->filterProxyModel->setSourceModel(this->table);
    this->table_view->setSortingEnabled(true);
    this->filterProxyModel->sort(0, Qt::AscendingOrder);

    this->main->addWidget(this->table_view);
    this->buttons = new QGridLayout{};
    this->buttons->addWidget(this->add, 0, 0);
    this->buttons->addWidget(this->revise, 0, 2);
    this->main->addLayout(this->buttons);

    QFormLayout* addNewFile = new QFormLayout{};
    addNewFile->addRow("New file name", this->file_name);
    this->main->addLayout(addNewFile);
    QWidget::setWindowTitle(QString::fromStdString(this->programmer.get_name()));
}

void GUI::connect_signal_and_slots() {
    QObject::connect(this->revise, &QPushButton::clicked, this, &GUI::revisionButton_handler);
    QObject::connect(this->add, &QPushButton::clicked, this, &GUI::addButton_handler);
    //available revise to implement next
}