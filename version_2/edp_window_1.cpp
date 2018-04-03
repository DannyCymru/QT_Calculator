#include "edp_window_1.h"
#include "ui_edp_window_1.h"

double value{0};
double val_1;
double val_2;
double returned_val;
QStringList List;

edp_window_1::edp_window_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edp_window_1)
{
    ui->setupUi(this);
    s_math = new standard_math();

    //Manually set window title
    setWindowTitle("EDP Calc");

    //menu bar functions
    create_actions();
    create_menus();

    //function to make the digit buttons
    create_digit_buttons();

    //Label to contain the numbers/calculation results
    result_label = new QLabel("0",this);
    result_label->setAlignment(Qt::AlignRight); //Aligns the information to the right
    result_label->setGeometry(QRect(QPoint(10,80), QSize(280,25)));
    result_label->setStyleSheet("font: 18pt; background-color:#e3e3e3;"); //Allows for style changes using CSS-like syntax

    //Creats a list view to hold all the previous calculations
    history = new QListView(this);
    history->setGeometry(QRect(QPoint(10,35), QSize(280,40)));
    history->QAbstractItemView::setEditTriggers(QAbstractItemView::NoEditTriggers); //This removes the ability to edit the list
    history->QAbstractItemView::scrollToTop();
    history_list = new QStringListModel(this); //Connects the list view with a list of data

    clear_timer = new QTimer(this);

    //Button for decimal place
    period = new QPushButton(".", this);
    period -> setGeometry(QRect(QPoint(110,260), QSize(50,50)));

    //Buttons for simple math calculations
    add_button = new QPushButton("+", this);
    add_button -> setGeometry(QRect(QPoint(190,160), QSize(50,50)));

    sub_button = new QPushButton("-", this);
    sub_button -> setGeometry(QRect(QPoint(240,160), QSize(50,50)));

    mult_button = new QPushButton("X", this);
    mult_button -> setGeometry(QRect(QPoint(190,210), QSize(50,50)));

    div_button = new QPushButton("/", this);
    div_button -> setGeometry(QRect(QPoint(240,210), QSize(50,50)));

    //Auxillary function buttons
    clear_button = new QPushButton("Clr", this);
    clear_button -> setGeometry(QRect(QPoint(190, 110), QSize(100,50)));
    clear_button->setStyleSheet("background-color: #c23616;");

    result_button = new QPushButton("=", this);
    result_button->setGeometry(QRect(QPoint(190,260), QSize(100, 50)));

    //Connection for decimal place button
    connect(period, SIGNAL(released()), this, SLOT(period_press()));

    //Connects the calculation signal to the correct slot
    connect(add_button, SIGNAL(released()), this, SLOT(add_press()));
    connect(sub_button, SIGNAL(released()), this, SLOT(sub_press()));
    connect(mult_button, SIGNAL(released()), this, SLOT(mult_press()));
    connect(div_button, SIGNAL(released()), this, SLOT(div_press()));

    //Connects the auxillary function signals to the correct slot
    connect(clear_button, SIGNAL(released()), this, SLOT(clr_press()));
    connect(result_button, SIGNAL(released()), this, SLOT(result_press()));
    connect(clear_timer, SIGNAL(timeout()), this, SLOT (clr_press()));
}

void edp_window_1::create_digit_buttons(){

    //Manual creation of push buttons
    digit_button_0 = new QPushButton("0", this);
    digit_button_0 -> setGeometry(QRect(QPoint(10,260), QSize(100,50)));

    digit_button_1 = new QPushButton("1", this);
    digit_button_1 -> setGeometry(QRect(QPoint(10,210), QSize(50,50)));

    digit_button_2 = new QPushButton("2", this);
    digit_button_2 -> setGeometry(QRect(QPoint(60,210), QSize(50,50)));

    digit_button_3 = new QPushButton("3", this);
    digit_button_3 -> setGeometry(QRect(QPoint(110,210), QSize(50,50)));

    digit_button_4 = new QPushButton("4", this);
    digit_button_4 -> setGeometry(QRect(QPoint(10,160), QSize(50,50)));

    digit_button_5 = new QPushButton("5", this);
    digit_button_5 -> setGeometry(QRect(QPoint(60,160), QSize(50,50)));

    digit_button_6 = new QPushButton("6", this);
    digit_button_6 -> setGeometry(QRect(QPoint(110,160), QSize(50,50)));

    digit_button_7 = new QPushButton("7", this);
    digit_button_7 -> setGeometry(QRect(QPoint(10,110), QSize(50,50)));

    digit_button_8 = new QPushButton("8", this);
    digit_button_8 -> setGeometry(QRect(QPoint(60,110), QSize(50,50)));

    digit_button_9 = new QPushButton("9", this);
    digit_button_9 -> setGeometry(QRect(QPoint(110,110), QSize(50,50)));


    //Connects all of the buttons to the digit pressed function
    connect(digit_button_0, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_1, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_2, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_3, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_4, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_5, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_6, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_7, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_8, SIGNAL(released()),this,SLOT(digit_press()));
    connect(digit_button_9, SIGNAL(released()),this,SLOT(digit_press()));

}

//Function to allow every digit press to be handled by the same code, allows for less code reuse
void edp_window_1::digit_press() {
    QPushButton *button =(QPushButton*)sender(); //On detection of a sender from the connected QPushButtons
    value = (result_label->text() + button->text()).toDouble(); //the value variable takes the text in the label + takes the specific buttons text, turning it into a double
    QString val_string = QString::number(value); //The new value becomes a string of the number from the label
    result_label->setText(val_string); //Label is now the updated value from the button click

    clear_timer->start(10000);

}

//This function will allow me to add decimal points to the value
void edp_window_1::period_press() {
    double temp_value = value;
    result_label->setText(QString::number(temp_value) + ".");
    value = temp_value;
}

//The slot that the events connect to. AKA the event handlers for the button press functions
void edp_window_1::add_press(){
    val_1 = value;
    c_op='+';
    result_label->setText("");
}

void edp_window_1::div_press(){
    val_1 = value;
    c_op='/';
    result_label->setText("");
}

void edp_window_1::mult_press(){
    val_1 = value;
    c_op='*';
    result_label->setText("");
}

void edp_window_1::sub_press(){
    val_1 = value;
    c_op='-';
    result_label->setText("");
}

//Slots for auxillary functions
void edp_window_1::clr_press(){
    val_1 = 0;
    val_2 = 0;
    value = 0;
    returned_val = 0;
    result_label->setText("");
}

void edp_window_1::result_press(){
    val_2 = value;
    operator_setup();
}

//Function to handle the actual s_math function calls
void edp_window_1::operator_setup(){
    //Switch statement to workout which function to call
    switch (c_op) {
        case '+':
            s_math->add(val_1, val_2);
            result_label->setText(QString::number(returned_val));
            break;
        case '-':
            s_math->subtract(val_1, val_2);
            result_label->setText(QString::number(returned_val));
            break;
        case '*':
            s_math->multiply(val_1, val_2);
            result_label->setText(QString::number(returned_val));
            break;
        case '/':
            s_math->divide(val_1, val_2);
            result_label->setText(QString::number(returned_val));
            break;
        default:
            qDebug("Failure");
            break;
    }

    //Temporary container to store the full string of data to push back into the vector
    pushback_container = QString::number(val_1) + " " + QString(c_op) + " " + QString::number(val_2) + " = " + QString::number(returned_val);
    all_calculations.push_back(pushback_container);
    qt_history(List); //Calls the function with the "List", this is what will populate the list view. This will also add a new calculation everytime the result button is clicked.

}

//Function to allow some of the funcitonality to allow the list view to be more dynamic.
void edp_window_1::qt_history(QStringList List){
    //A range for loop to go through every value in the vector and push it through the List.
    for(QString i : all_calculations ){
        List << i;
    }
    //Connects the "List" to the history_list container.
    history_list->setStringList(List);
    history->setModel(history_list);
    history->QAbstractItemView::scrollToBottom(); //Makes the list view scroll to the bottom. Effectively making it scroll to the bottom with each added calculation to the list.
}

void edp_window_1::create_actions(){
    save_action = new QAction("Save", this);
    save_action->setShortcut(QKeySequence::Save);
    save_action->setStatusTip("Saves all of your calculations");
    connect(save_action, QAction::triggered, this, edp_window_1::calc_save);
}

void edp_window_1::create_menus(){
   file_menu = menuBar()->addMenu("File");
   file_menu->addAction(save_action);

}

void edp_window_1::calc_save(){
    QString file_name = QFileDialog::getSaveFileName(this,
            tr("Save your calcualtions"), "",
            tr("Text File (*.txt);;All Files (*)"));

    if(file_name.isEmpty()){
        return;
    }
    else{
        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_5);
        out << all_calculations;
    }
}

edp_window_1::~edp_window_1(){
    //deletes pointers in attempt to clear any memory leaks
    delete ui;
    delete s_math;
}