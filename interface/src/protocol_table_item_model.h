/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include <QAbstractTableModel>
#include <QObject>

class ProtocolTableItemModel : public QAbstractTableModel
{
public:
    explicit ProtocolTableItemModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:

};