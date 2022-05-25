/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#include <QtGui>

#include <iostream>

#include "mainwindow.h"

#ifdef _MSC_VER
int __stdcall WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
#else
int main(int __argc, char **__argv)
#endif
{
    QApplication app(__argc, __argv);

    auto mainWindow = new MainWindow();

    mainWindow->show();

    return app.exec();
}