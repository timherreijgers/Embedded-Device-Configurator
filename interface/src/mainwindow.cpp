/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow() : m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
}
