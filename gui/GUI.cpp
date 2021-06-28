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
    this->table->updateInternalData();
}

void GUI::init_gui() {
    this->main = new QVBoxLayout{this};
    this->file_name = new QLineEdit{};
    this->add = new QPushButton{"Add"};
    this->revise = new QPushButton{"Revise File"};

    this->table = new AbstractModel{this->sourceFileRepository};
    this->table_view = new QTableView{};

    this->filterProxyModel = new QSortFilterProxyModel{};
    this->filterProxyModel->setSourceModel(this->table);
    this->table_view->setSortingEnabled(true);
    this->filterProxyModel->sort(0, Qt::AscendingOrder);

    this->table_view->setModel(this->filterProxyModel);

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

void GUI::addButton_handler() {
    std::string source_file = this->file_name->text().toStdString();
    if(source_file.empty()){
        QMessageBox::critical(this, "Error", "You should write a file name!");
        return;
    }
    SourceFile newSourceFile{source_file, "not-revised", this->programmer, Programmer{"", 0, 0}};
    this->sourceFileRepository.add(newSourceFile);
}

void GUI::revisionButton_handler() {
    std::string source_file = this->file_name->text().toStdString();
    for(auto file:this->sourceFileRepository.get_sourceFiles())
        if(file.get_name() == source_file){
            this->sourceFileRepository.reviseFile(file);
        }
}

int GUI::get_selected_index() {return 0;}