//
// Created by SL15 on 21.06.2021.
//

#include "AbstractModel.h"

AbstractModel::AbstractModel(std::vector<SourceFile> &_sourceFiles, QObject *parent): QAbstractTableModel{parent},sourceFiles(_sourceFiles) {
    this->sourceFiles_count = _sourceFiles.size();
}

AbstractModel::~AbstractModel(){;}

int AbstractModel::rowCount(const QModelIndex &parent) const {
    return this->sourceFiles_count;
}

int AbstractModel::columnCount(const QModelIndex &parent) const {
    return 8;
}

QVariant AbstractModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if(role == Qt::FontRole){
        QFont qFont{QString::fromStdString(this->font_name), this->font_size};
        return qFont;
    }
    if(role == Qt::DisplayRole){
        SourceFile currentSourceFile = this->sourceFiles[row];
        if(column < 0 || column > 7)
            throw std::runtime_error("Table Error! Wrong column count!");
        if(column == 0)
            return QString::fromStdString(currentSourceFile.get_name());
        if(column == 1)
            return QString::fromStdString(currentSourceFile.get_status());
        if(column == 2)
            return QString::fromStdString(currentSourceFile.get_creatorProgrammer().get_name());
        if(column == 3)
            return QString::fromStdString(std::to_string(currentSourceFile.get_creatorProgrammer().get_revisedFiles()));
        if(column == 4)
            return QString::fromStdString(std::to_string(currentSourceFile.get_creatorProgrammer().get_mustRevise()));
        if(column == 5)
            return QString::fromStdString(currentSourceFile.get_reviewerProgrammer().get_name());
        if(column == 6)
            return QString::fromStdString(std::to_string(currentSourceFile.get_reviewerProgrammer().get_revisedFiles()));
        if(column == 7)
            return QString::fromStdString(std::to_string(currentSourceFile.get_reviewerProgrammer().get_mustRevise()));
    }
    return QVariant();
}

QVariant AbstractModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::FontRole){
        QFont qFont{QString::fromStdString(this->font_name), this->font_size};
        return qFont;
    }
    if(role == Qt::DisplayRole)
        if(orientation == Qt::Horizontal){
            if(section < 0 || section > 7)
                throw std::runtime_error("Table Error! Wrong column count!");
            if(section == 0)
                return QString{"File Name"};
            if(section == 1)
                return QString{"Revision Status"};
            if(section == 2)
                return QString{"Creator Programmer Name"};
            if(section == 3)
                return QString{"Creator Programmer Revised Files"};
            if(section == 4)
                return QString{"Creator Programmer Must Revise This Many Files"};
            if(section == 5)
                return QString{"Reviewer Programmer Name"};
            if(section == 6)
                return QString{"Reviewer Programmer Revised Files"};
            if(section == 7)
                return QString{"Reviewer Programmer Must Revise This Many Files"};
        }
    return QVariant();
}

Qt::ItemFlags AbstractModel::flags(const QModelIndex &index) const  {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool AbstractModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(!index.isValid() || role != Qt::EditRole)
        return false;
    int row = index.row();
    int column = index.column();
    if(row == this->sourceFiles.size()){
        this->beginInsertRows(QModelIndex{}, row, row);
        if(column < 0 || column > 7)
            throw std::runtime_error("Table Error! Wrong column count!");
        if(column == 0)
            this->sourceFiles.emplace_back(value.toString().toStdString(), "", Programmer{"", NULL_INTEGER, NULL_INTEGER}, Programmer{"", NULL_INTEGER, NULL_INTEGER});
        if(column == 1)
            this->sourceFiles.emplace_back("", value.toString().toStdString(), Programmer{"", NULL_INTEGER, NULL_INTEGER}, Programmer{"", NULL_INTEGER, NULL_INTEGER});
        if(column == 2)
            this->sourceFiles.emplace_back("", "", Programmer{value.toString().toStdString(), NULL_INTEGER, NULL_INTEGER}, Programmer{"", NULL_INTEGER, NULL_INTEGER});
        if(column == 3)
            this->sourceFiles.emplace_back("", "", Programmer{"", std::stoi(value.toString().toStdString()), NULL_INTEGER}, Programmer{"", NULL_INTEGER, NULL_INTEGER});
        if(column == 4)
            this->sourceFiles.emplace_back("", "", Programmer{"", NULL_INTEGER, std::stoi(value.toString().toStdString())}, Programmer{"", NULL_INTEGER, NULL_INTEGER});
        if(column == 5)
            this->sourceFiles.emplace_back("", "", Programmer{"", NULL_INTEGER, NULL_INTEGER}, Programmer{value.toString().toStdString(), NULL_INTEGER, NULL_INTEGER});
        if(column == 6)
            this->sourceFiles.emplace_back("", "", Programmer{"", NULL_INTEGER, NULL_INTEGER}, Programmer{"", std::stoi(value.toString().toStdString()), NULL_INTEGER});
        if(column == 7)
            this->sourceFiles.emplace_back("", "", Programmer{"", NULL_INTEGER, NULL_INTEGER}, Programmer{"", NULL_INTEGER, std::stoi(value.toString().toStdString())});
        this->endInsertRows();
        return true;
    }
    SourceFile& sourceFile = this->sourceFiles[row];
    if(column < 0 || column > 7)
        throw std::runtime_error("Table Error! Wrong column count!");
    if(column == 0)
        sourceFile.set_name(value.toString().toStdString());
    if(column == 1)
        sourceFile.set_status(value.toString().toStdString());
    if(column == 2)
        sourceFile.get_creatorProgrammer().set_name(value.toString().toStdString());
    if(column == 3)
        sourceFile.get_creatorProgrammer().set_revisedFiles(std::stoi(value.toString().toStdString()));
    if(column == 4)
        sourceFile.get_creatorProgrammer().set_mustRevise(std::stoi(value.toString().toStdString()));
    if(column == 5)
        sourceFile.get_reviewerProgrammer().set_name(value.toString().toStdString());
    if(column == 6)
        sourceFile.get_reviewerProgrammer().set_revisedFiles(std::stoi(value.toString().toStdString()));
    if(column == 7)
        sourceFile.get_reviewerProgrammer().set_mustRevise(std::stoi(value.toString().toStdString()));
    this->sourceFiles[row] = sourceFile;
    emit dataChanged(index, index);
    return true;
}