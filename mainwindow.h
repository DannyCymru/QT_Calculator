#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//Methods
private slots:
    //Screen clear
    void clear();

    //basic operations
    void add();
    void subtract();
    void multiply();
    void division();
    void equals();

    //numbering systems
    void binary();
    void octal();
    void hex();

    //numbers/letters allowed
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void a();
    void b();
    void c();
    void d();
    void e();
    void f();



private:
    Ui::MainWindow *ui;

    QLabel *label;
    QPushButton *clear_button;
    QPushButton *add_button;
    QPushButton *subtract_button;
    QPushButton *multiply_button;
    QPushButton *division_button;
    QPushButton *equals_button;
    QPushButton *binary_button;
    QPushButton *octal_button;
    QPushButton *hex_button;
    QPushButton *zero_button;
    QPushButton *one_button;
    QPushButton *two_button;
    QPushButton *three_button;
    QPushButton *four_button;
    QPushButton *five_button;
    QPushButton *six_button;
    QPushButton *seven_button;
    QPushButton *eight_button;
    QPushButton *nine_button;



};

#endif // MAINWINDOW_H
