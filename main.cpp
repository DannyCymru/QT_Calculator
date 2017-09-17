#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Sets show size to 300 x 400 pixels
    w.setFixedSize(300,400);

    //Moves the widget to the middle of the screen on startup.
    w.move(QApplication::desktop()->screen()->rect().center()-w.rect().center());
    return a.exec();
}
