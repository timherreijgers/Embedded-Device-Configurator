/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "protocol_table_item_model.h"

#include <fmt/core.h>

static QString columnContents[3] = {
        "Type",
        "Size",
        "Value"
};

ProtocolTableItemModel::ProtocolTableItemModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ProtocolTableItemModel::rowCount(const QModelIndex &parent) const
{
    return 5;
}

int ProtocolTableItemModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ProtocolTableItemModel::data(const QModelIndex &index, int role) const
{
    return columnContents[index.column()];
}

Qt::ItemFlags ProtocolTableItemModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
