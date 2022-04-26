#include <QtCore>
#include <QtGui>

#include <iostream>

int __stdcall WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
    std::cout << __argv[0] << std::endl;

    QApplication app(__argc, __argv);

    auto *mainWindow = new QWidget();
    mainWindow->setMinimumSize(700, 350);

    QPushButton *pb = new QPushButton();
    pb->setText("Close");

    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(pb);

    QObject::connect(pb, &QPushButton::clicked,
                     mainWindow, &QWidget::close);

    mainWindow->show();

    return app.exec();
}