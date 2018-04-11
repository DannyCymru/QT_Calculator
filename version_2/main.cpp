#include "edp_window_1.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    edp_window_1 window_1;
    window_1.show();

    //Sets show size to 300 pixels wide and 350 pixels in height
    window_1.setFixedSize(300,340);

    //Moves the widget to the middle of the screen on startup.
    window_1.move(QApplication::desktop()->screen()->rect().center()-window_1.rect().center());
    return a.exec();
}
