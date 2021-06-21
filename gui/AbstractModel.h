//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_ABSTRACTMODEL_H
#include <QAbstractTableModel>
#include <QFont>
#include <vector>
#include "SourceFile.h"
#define NULL_INTEGER -111111111
#define QT_ABSTRACTMODEL_H


class AbstractModel:public QAbstractTableModel {
private:
    std::vector<SourceFile> sourceFiles;
    unsigned long long sourceFiles_count;
    const int font_size = 15;
    const std::string font_name = "Times New Roman";
public:
    explicit AbstractModel(std::vector<SourceFile>& _sourceFiles, QObject* parent= nullptr);
    ~AbstractModel() override;
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void updateSourceFiles(const std::vector<SourceFile> newSourceFiles);
    void updateData();
};


#endif //QT_ABSTRACTMODEL_H
