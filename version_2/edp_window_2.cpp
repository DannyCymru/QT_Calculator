#include "edp_window_2.h"
#include "ui_edp_window_2.h"

double edp2_value{0};
double edp2_val_1;
double edp2_val_2;
double edp2_returned_val;

QString total{"not this"};
QStringList edp2_List;


edp_window_2::edp_window_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edp_window_2)
{
    ui->setupUi(this);
    a_math = new advanced_math();

    edp_window_2::setFixedSize(500, 340);

    setWindowTitle("EDP Calc Advanced View"); //Sets new title window

    //Populate menubar with actions
    create_actions();
    create_menus();

    //Populate the form with buttons
    create_rbuttons();
    create_smath_buttons();
    create_lbuttons();

    //Label to contain the numbers/calculation results
    result_label = new QLabel("0",this);
    result_label->setAlignment(Qt::AlignRight); //Aligns the information to the right
    result_label->setGeometry(QRect(QPoint(10,85), QSize(480,30)));
    result_label->setStyleSheet("font: 18pt; background-color:#e3e3e3;"); //Allows for style changes using CSS-like syntax
    result_label->setStatusTip("Shows the numbers you enter and the final result");

    //Creats a list view to hold all the previous calculations
    history = new QListView(this);
    history->setGeometry(QRect(QPoint(10,30), QSize(480,50)));
    history->isWrapping();
    history->QAbstractItemView::setEditTriggers(QAbstractItemView::NoEditTriggers); //This removes the ability to edit the list
    history->QAbstractItemView::scrollToTop();
    history_list = new QStringListModel(this); //Connects the list view with a list of data
    history->setStatusTip("Holds all your previous calculations");

}

void edp_window_2::create_menus(){
    qDebug() << "Menu Creation: 1" ;
    file_menu = menuBar()->addMenu("File");
    file_menu->addAction(save_action);
}

void edp_window_2::create_actions(){
    qDebug() << "Action Creation: 1" ;
    save_action = new QAction("Save", this);
    save_action->setShortcut(QKeySequence::Save);
    save_action->setStatusTip("Saves all of your calculations");
    connect(save_action, &QAction::triggered, this, &edp_window_2::calc_save);
};

void edp_window_2::calc_save(){
    qDebug() << "calc save" ;
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
        QTextStream out(&file);
            for (QVector<QString>::iterator iter = all_calculations.begin(); iter != all_calculations.end(); iter++){
             out << *iter;
                }

         file.close();
        }
}

//Function to allow some of the funcitonality to allow the list view to be more dynamic.
void edp_window_2::qt_history(QStringList List){
    //A range for loop to go through every value in the vector and push it through the List.
    for(QString i : all_calculations ){
        List << i;
    }
    //Connects the "List" to the history_list container.
    history_list->setStringList(List);
    history->setModel(history_list);
    history->QAbstractItemView::scrollToBottom(); //Makes the list view scroll to the bottom. Effectively making it scroll to the bottom with each added calculation to the list.
}

void edp_window_2::create_lbuttons(){

    //Radio Buttons
    decimal_radio = new QRadioButton("Decimal", this);
    decimal_radio -> setGeometry(QRect(QPoint(10,120), QSize(65,30)));
    decimal_radio->setChecked(true);
    decimal_radio->setStatusTip("Converts the numbers to decimal");

    binary_radio = new QRadioButton("Binary", this);
    binary_radio -> setGeometry(QRect(QPoint(10,140), QSize(55,30)));
    binary_radio->setStatusTip("Converts the numbers to binary");

    hex_radio = new QRadioButton("Hex", this);
    hex_radio -> setGeometry(QRect(QPoint(160, 120), QSize(42,30)));
    hex_radio->setStatusTip("Converts the numbers to hexadecimal");

    octal_radio = new QRadioButton("Octal", this);
    octal_radio -> setGeometry(QRect(QPoint(160, 140), QSize(55,30)));
    octal_radio->setStatusTip("Converts the numbers to octal");

    sin_button = new QPushButton("Sin", this);
    sin_button->setGeometry(QRect(QPoint(10, 180), QSize(100, 50)));

    tan_button = new QPushButton("Tan", this);
    tan_button->setGeometry(QRect(QPoint(120, 180), QSize(100, 50)));

    cos_button = new QPushButton("Cos", this);
    cos_button->setGeometry(QRect(QPoint(10, 230), QSize(100, 50)));

    log_button = new QPushButton("Log", this);
    log_button->setGeometry(QRect(QPoint(120, 230), QSize(100, 50)));

    //Radio button connects
    connect(decimal_radio, SIGNAL(clicked()),this,SLOT(conversion()));
    connect(binary_radio, SIGNAL(clicked()),this,SLOT(conversion()));
    connect(hex_radio, SIGNAL(clicked()),this,SLOT(conversion()));
    connect(octal_radio, SIGNAL(clicked()),this,SLOT(conversion()));

    //Push Button Connections
    connect(sin_button, SIGNAL(released()),this,SLOT(sin_press()));
    connect(cos_button, SIGNAL(released()), this, SLOT(cos_press()));
    connect(tan_button, SIGNAL(released()), this, SLOT(tan_press()));
    connect(log_button, SIGNAL(released()), this, SLOT(log_press()));
}

void edp_window_2::sin_press(){
    qDebug() << "Sin for the world";
    edp2_val_1 = edp2_value;
    a_math->edp2_sin(edp2_val_1);
    result_label->setText(QString::number(edp2_returned_val));
}

void edp_window_2::tan_press(){
    qDebug() << "Tan for the world";
    edp2_val_1 = edp2_value;
    a_math->edp2_tan(edp2_val_1);
    result_label->setText(QString::number(edp2_returned_val));
}

void edp_window_2::cos_press(){
    qDebug() << "Cos for the world";
    edp2_val_1 = edp2_value;
    a_math->edp2_cos(edp2_val_1);
    result_label->setText(QString::number(edp2_returned_val));
}

void edp_window_2::log_press(){
    qDebug() << "Log for the world";
    edp2_val_1 = edp2_value;
    a_math->edp2_log(edp2_val_1);
    result_label->setText(QString::number(edp2_returned_val));
}

void edp_window_2::conversion(){
    qDebug() << "You just clicked";
    QString alt_string = {"Temp Value"};

    if (decimal_radio->isChecked()){
        alt_string = QString::number(total.toInt(), 10);
        result_label -> setText(alt_string);
    }

    else if(binary_radio->isChecked()) {
        qDebug() << "binary";
        alt_string = QString::number(total.toInt(), 2);
        result_label -> setText(alt_string);
    }

    else if(octal_radio->isChecked()){
        qDebug() << "Octal";
        alt_string = QString::number(total.toInt(), 8);
        result_label -> setText(alt_string);
    }

    else if(hex_radio->isChecked()){
        qDebug() << "Hex";
        alt_string = QString::number(total.toInt(), 16);
        result_label -> setText(alt_string);
    }

}

void edp_window_2::create_rbuttons(){
    qDebug() << "Label buttons Creation: 1" ;

    //Manual creation of push buttons
    digit_button_0 = new QPushButton("0", this);
    digit_button_0 -> setGeometry(QRect(QPoint(230,270), QSize(100,50)));

    digit_button_1 = new QPushButton("1", this);
    digit_button_1 -> setGeometry(QRect(QPoint(230,220), QSize(50,50)));

    digit_button_2 = new QPushButton("2", this);
    digit_button_2 -> setGeometry(QRect(QPoint(280,220), QSize(50,50)));

    digit_button_3 = new QPushButton("3", this);
    digit_button_3 -> setGeometry(QRect(QPoint(330,220), QSize(50,50)));

    digit_button_4 = new QPushButton("4", this);
    digit_button_4 -> setGeometry(QRect(QPoint(230,170), QSize(50,50)));

    digit_button_5 = new QPushButton("5", this);
    digit_button_5 -> setGeometry(QRect(QPoint(280,170), QSize(50,50)));

    digit_button_6 = new QPushButton("6", this);
    digit_button_6 -> setGeometry(QRect(QPoint(330,170), QSize(50,50)));

    digit_button_7 = new QPushButton("7", this);
    digit_button_7 -> setGeometry(QRect(QPoint(230,120), QSize(50,50)));

    digit_button_8 = new QPushButton("8", this);
    digit_button_8 -> setGeometry(QRect(QPoint(280,120), QSize(50,50)));

    digit_button_9 = new QPushButton("9", this);
    digit_button_9 -> setGeometry(QRect(QPoint(330,120), QSize(50,50)));

    period = new QPushButton(".", this);
    period -> setGeometry(QRect(QPoint(330,270), QSize(50,50)));

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
    connect(period, SIGNAL(released()), this, SLOT(period_press()));
}

void edp_window_2::create_smath_buttons(){
    qDebug() << "Create math buttons";
    //Buttons for simple math calculations
    add_button = new QPushButton("+", this);
    add_button -> setGeometry(QRect(QPoint(390,170), QSize(50,50)));
    add_button->setToolTip("Starts the calculation to add two numbers you enter together");

    sub_button = new QPushButton("-", this);
    sub_button -> setGeometry(QRect(QPoint(440,170), QSize(50,50)));
    sub_button->setToolTip("Starts the calculation to subtract two numbers you enter");

    mult_button = new QPushButton("X", this);
    mult_button -> setGeometry(QRect(QPoint(390,220), QSize(50,50)));
    mult_button->setToolTip("Starts the calculation to multiply two numbers you enter together");

    div_button = new QPushButton("/", this);
    div_button -> setGeometry(QRect(QPoint(440,220), QSize(50,50)));
    div_button->setToolTip("Starts the calculation to divide two numbers you enter");

    //Auxillary function buttons
    clear_button = new QPushButton("Clr", this);
    clear_button -> setGeometry(QRect(QPoint(390, 120), QSize(100,50)));
    clear_button->setStyleSheet("background-color: #c23616;");
    clear_button->setToolTip("Clears every number entered, at any stage of the calculation to allow you to do a completely new calculation");

    result_button = new QPushButton("=", this);
    result_button->setGeometry(QRect(QPoint(390,270), QSize(100, 50)));
    result_button->setToolTip("Finishes the calculation used and prints out the full result");

    //Creates the timer
    clear_timer = new QTimer(this);

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

void edp_window_2::digit_press(){
    qDebug() << "Digit Pressed Function: 1";
    QPushButton *button =(QPushButton*)sender(); //On detection of a sender from the connected QPushButtons
    edp2_value = (result_label->text() + button->text()).toDouble(); //the value variable takes the text in the label + takes the specific buttons text, turning it into a double
    QString val_string = QString::number(edp2_value); //The new value becomes a string of the number from the label
    result_label->setText(val_string); //Label is now the updated value from the button click

    clear_timer->start(10000);
}

void edp_window_2::period_press(){
    double temp_value = edp2_value;
    result_label->setText(QString::number(temp_value) + ".");
    edp2_value = temp_value;
}

void edp_window_2::add_press(){
    edp2_val_1 = edp2_value;
    edp2_c_op='+';
    result_label->setText("");
}

void edp_window_2::div_press(){
    edp2_val_1 = edp2_value;
    edp2_c_op='/';
    result_label->setText("");
}

void edp_window_2::mult_press(){
    edp2_val_1 = edp2_value;
    edp2_c_op='*';
    result_label->setText("");
}

void edp_window_2::sub_press(){
    edp2_val_1 = edp2_value;
    edp2_c_op='-';
    result_label->setText("");
}

//Slots for auxillary functions
void edp_window_2::clr_press(){
    edp2_val_1 = 0;
    edp2_val_1 = 0;
    edp2_value = 0;
    edp2_returned_val = 0;
    result_label->setText("");
}

void edp_window_2::result_press(){
    edp2_val_2 = edp2_value;
    operator_setup();
}

//Function to handle the actual a_math function calls
void edp_window_2::operator_setup(){
    //Switch statement to workout which function to call
    switch (edp2_c_op) {
        case '+':
            a_math->edp2_add(edp2_val_1, edp2_val_2);
            total = QString::number(edp2_returned_val);
            result_label->setText(total);
            break;
        case '-':
            a_math->edp2_subtract(edp2_val_1, edp2_val_2);
            total = QString::number(edp2_returned_val);
            result_label->setText(total);
            break;
        case '*':
            a_math->edp2_multiply(edp2_val_1, edp2_val_2);
            total = QString::number(edp2_returned_val);
            result_label->setText(total);
            break;
        case '/':
            a_math->edp2_divide(edp2_val_1, edp2_val_2);
            total = QString::number(edp2_returned_val);
            result_label->setText(total);
            break;
        default:
            qDebug("Failure");
            break;
    }

    //Temporary container to store the full string of data to push back into the vector
    pushback_container = QString::number(edp2_val_1) + " " + QString(edp2_c_op) + " " + QString::number(edp2_val_2) + " = " + QString::number(edp2_returned_val) + "\n";
    all_calculations.push_back(pushback_container);
    qt_history(edp2_List); //Calls the function with the "List", this is what will populate the list view. This will also add a new calculation everytime the result button is clicked.

    //edp2_val_1=0; //this is
}

edp_window_2::~edp_window_2()
{
    delete ui;
}
