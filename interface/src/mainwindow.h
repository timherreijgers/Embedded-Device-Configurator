/*
 * Copyright (c) 2022 Tim Herreijgers
 */

#pragma once

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow();

private:
    Ui::MainWindow * m_ui;
};