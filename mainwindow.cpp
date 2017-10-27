#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>
#include <bitset>
#include <QDataStream>


QString value = "", total = "", alt_string = "";
int first_num, second_num, string_to_int, alt_num;
bool add_bool = false, subtract_bool = false, multiply_bool = false, division_bool = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel("0",this);
    label -> setGeometry(QRect(QPoint(75,-50), QSize(100,200)));

    clear_button = new QPushButton("Clr", this);
    clear_button -> setGeometry(QRect(QPoint(170,150), QSize(40,40)));
    connect(clear_button, SIGNAL(released()), this, SLOT(clear()));

    add_button = new QPushButton("+", this);
    add_button -> setGeometry(QRect(QPoint(170,100), QSize(40,40)));
    connect(add_button, SIGNAL(released()), this, SLOT(add()));

    subtract_button = new QPushButton("-", this);
    subtract_button -> setGeometry(QRect(QPoint(210,100), QSize(40,40)));
    connect(subtract_button, SIGNAL(released()), this, SLOT(subtract()));

    multiply_button = new QPushButton("X", this);
    multiply_button -> setGeometry(QRect(QPoint(250,100), QSize(40,40)));
    connect(multiply_button, SIGNAL(released()), this, SLOT(multiply()));

    division_button = new QPushButton("/", this);
    division_button -> setGeometry(QRect(QPoint(250,150), QSize(40,40)));
    connect(division_button, SIGNAL(released()), this, SLOT(division()));

    equals_button = new QPushButton("=", this);
    equals_button -> setGeometry(QRect(QPoint(210,150), QSize(40,40)));
    connect(equals_button, SIGNAL(released()), this, SLOT(equals()));

    binary_button = new QPushButton("Bin", this);
    binary_button -> setGeometry(QRect(QPoint(170,200), QSize(40,40)));
    connect(binary_button, SIGNAL(released()), this, SLOT(binary()));

    octal_button = new QPushButton("Oct", this);
    octal_button -> setGeometry(QRect(QPoint(210,200), QSize(40,40)));
    connect(octal_button, SIGNAL(released()), this, SLOT(octal()));

    hex_button = new QPushButton("Hex", this);
    hex_button -> setGeometry(QRect(QPoint(250,200), QSize(40,40)));
    connect(hex_button, SIGNAL(released()), this, SLOT(hex()));

    zero_button = new QPushButton("0", this);
    zero_button -> setGeometry(QRect(QPoint(60,250), QSize(50,50)));
    connect(zero_button, SIGNAL(released()), this, SLOT(zero()));

    one_button = new QPushButton("1", this);
    one_button -> setGeometry(QRect(QPoint(10,100), QSize(50,50)));
    connect(one_button, SIGNAL(released()), this, SLOT(one()));

    two_button = new QPushButton("2", this);
    two_button -> setGeometry(QRect(QPoint(60,100), QSize(50,50)));
    connect(two_button, SIGNAL(released()), this, SLOT(two()));

    three_button = new QPushButton("3", this);
    three_button -> setGeometry(QRect(QPoint(110,100), QSize(50,50)));
    connect(three_button, SIGNAL(released()), this, SLOT(three()));

    four_button = new QPushButton("4", this);
    four_button -> setGeometry(QRect(QPoint(10,150), QSize(50,50)));
    connect(four_button, SIGNAL(released()), this, SLOT(four()));

    five_button = new QPushButton("5", this);
    five_button -> setGeometry(QRect(QPoint(60,150), QSize(50,50)));
    connect(five_button, SIGNAL(released()), this, SLOT(five()));

    six_button = new QPushButton("6", this);
    six_button -> setGeometry(QRect(QPoint(110,150), QSize(50,50)));
    connect(six_button, SIGNAL(released()), this, SLOT(six()));

    seven_button = new QPushButton("7", this);
    seven_button -> setGeometry(QRect(QPoint(10,200), QSize(50,50)));
    connect(seven_button, SIGNAL(released()), this, SLOT(seven()));

    eight_button = new QPushButton("8", this);
    eight_button -> setGeometry(QRect(QPoint(60,200), QSize(50,50)));
    connect(eight_button, SIGNAL(released()), this, SLOT(eight()));

    nine_button = new QPushButton("9", this);
    nine_button -> setGeometry(QRect(QPoint(110,200), QSize(50,50)));
    connect(nine_button, SIGNAL(released()), this, SLOT(nine()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Screen clear
void MainWindow::clear(){
    value = "";
    label -> setText(value);
}

//basic operations
void MainWindow::add(){

    first_num = value.toInt();
    value = "";
    label -> setText(value);

    add_bool = true;

}

void MainWindow::subtract(){

    first_num = value.toInt();
    value = "";
    label -> setText(value);

    subtract_bool = true;

}

void MainWindow::multiply(){

    first_num = value.toInt();
    value = "";
    label -> setText(value);

    multiply_bool = true;

}

void MainWindow::division(){

    first_num = value.toInt();
    value = "";
    label -> setText(value);

    division_bool = true;

}

void MainWindow::equals(){
    second_num = value.toInt();

    if (add_bool) {

       total = QString::number(first_num + second_num);
       label -> setText(total);
    }

    if (subtract_bool) {

        total = QString::number(first_num - second_num);
        label -> setText(total);

    }

   if (multiply_bool) {

        total = QString::number(first_num * second_num);
        label -> setText(total);

    }

    if (division_bool) {

        total = QString::number(first_num / second_num);
        label -> setText(total);

    }

    else {
        total=QString::number(first_num + second_num);
        label -> setText(total);

    }

}

//numbering systems
void MainWindow::binary(){

        QString alt_string = QString::number(total.toInt(), 2);


        label -> setText(alt_string);
}

void MainWindow::octal(){

    QString alt_string = QString::number(total.toInt(), 8);

    label->setText(alt_string);


}

void MainWindow::hex(){

    QString alt_string = QString::number(total.toInt(), 16).toUpper();

    label->setText(alt_string);

}

//numbers/letters allowed
void MainWindow::zero(){

    value = value + "0";
    label -> setText(value);

}

void MainWindow::one(){

    value = value + "1";
    label -> setText(value);

}

void MainWindow::two(){

    value = value + "2";
    label -> setText(value);
}

void MainWindow::three(){

    value = value + "3";
    label -> setText(value);

}

void MainWindow::four(){

    value = value + "4";
    label -> setText(value);
}

void MainWindow::five(){

    value = value + "5";
    label -> setText(value);
}

void MainWindow::six(){

    value = value + "6";
    label -> setText(value);

}

void MainWindow::seven(){

    value = value + "7";
    label -> setText(value);

}

void MainWindow::eight(){

    value = value + "8";
    label -> setText(value);

}

void MainWindow::nine(){

    value = value + "9";
    label -> setText(value);

}




