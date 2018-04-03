#include "edp_window_1.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    edp_window_1 w1;
    w1.show();

    //Sets show size to 300 pixels wide and 350 pixels in height
    w1.setFixedSize(300,325);

    //Moves the widget to the middle of the screen on startup.
    w1.move(QApplication::desktop()->screen()->rect().center()-w1.rect().center());
    return a.exec();
}
