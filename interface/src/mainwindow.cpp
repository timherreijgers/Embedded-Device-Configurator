/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "protocol_table_item_model.h"

MainWindow::MainWindow() : m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    const auto protocolTableItemModel = new ProtocolTableItemModel(m_ui->tableView);
    m_ui->tableView->setModel(protocolTableItemModel);
}
