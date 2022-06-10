/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include <QtGui/QApplication>

#include <iostream>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    auto mainWindow = new MainWindow();

    mainWindow->show();

    return app.exec();
}