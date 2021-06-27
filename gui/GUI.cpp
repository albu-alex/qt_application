//
// Created by SL15 on 21.06.2021.
//

#include "GUI.h"

void GUI::init_gui() {
    QVBoxLayout* main = new QVBoxLayout{this};

    this->file_name = new QLineEdit{};
    this->add = new QPushButton{"Add"};
    this->revision = new QPushButton{"Revise Source File"};

    this->sourceFiles = this->service.get_sourceFileRepository();
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
    QWidget::setWindowTitle(QString::fromStdString(service.get_programmer().get_name()));
}

void GUI::connect_signal_and_slots() {
    QObject::connect(this->revision, &QPushButton::clicked, this, &GUI::revisionButton_handler);
    QObject::connect(this->add, &QPushButton::clicked, this, &GUI::addButton_handler);
    QObject::connect(this->table_view, &QTableView::clicked, this, &GUI::checkIfReviseAvailable);
}

GUI::GUI(Service &_service, QWidget *parent): service(_service), QWidget(parent) {
    this->init_gui();
    this->connect_signal_and_slots();
    this->show();
}

void GUI::revisionButton_handler() {
    std::string name = this->file_name->text().toStdString();
    if(name.empty()){
        QMessageBox error;
        error.setText("You must enter a file name to revise!");
        error.exec();
        return;
    }
    this->service.reviseSourceFile(name);
    for(auto sourceFile : this->service.get_sourceFileRepository())
        if(sourceFile.get_name() == name){
            QMessageBox revised;
            revised.setText(QString::fromStdString(
                    sourceFile.get_reviewerProgrammer().get_name() + " has reviewed another file!"));
            revised.exec();
        }
    this->service.get_programmer().set_revisedFiles(this->service.get_programmer().get_revisedFiles() + 1);
    this->table->updateData();
}

void GUI::addButton_handler() {
    std::string name = this->file_name->text().toStdString();
    if(name.empty()){
        QMessageBox error;
        error.setText("You must enter a file name to revise!");
        error.exec();
        return;
    }
    this->service.addSourceFile(name, this->service.get_programmer());
    this->table->updateData();
}

void GUI::notify_model() {
    this->table->updateData();
}

void GUI::update() {
    this->notify_model();
}

void GUI::checkIfReviseAvailable(){;}