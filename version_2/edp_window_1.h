#ifndef EDP_WINDOW_1_H
#define EDP_WINDOW_1_H

#include <QtCore/QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QListView>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QVector>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <standard_math.h>

extern double value;

namespace Ui {
class edp_window_1;
}

class edp_window_1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit edp_window_1(QWidget *parent = 0);
    ~edp_window_1();

private slots:
    void digit_press();
    void period_press();
    void add_press();
    void sub_press();
    void div_press();
    void mult_press();
    void clr_press();
    void result_press();
    void calc_save();


private:
    void create_digit_buttons();
    void operator_setup();
    void qt_history(QStringList List);
    void create_actions();
    void create_menus();

    QVector<QString> all_calculations;
    QString pushback_container;
    QLabel *result_label;
    QListView *history;
    QStringListModel *history_list;
    QPushButton *digit_button_0;
    QPushButton *digit_button_1;
    QPushButton *digit_button_2;
    QPushButton *digit_button_3;
    QPushButton *digit_button_4;
    QPushButton *digit_button_5;
    QPushButton *digit_button_6;
    QPushButton *digit_button_7;
    QPushButton *digit_button_8;
    QPushButton *digit_button_9;
    QPushButton *period;
    QPushButton *add_button;
    QPushButton *sub_button;
    QPushButton *div_button;
    QPushButton *mult_button;
    QPushButton *result_button;
    QPushButton *clear_button;
    QMenu *file_menu;
    QAction *save_action;
    QTimer *clear_timer;

    //Pointers for quicker access to functions from other headers/sources.
    Ui::edp_window_1 *ui;
    standard_math *s_math;
};



#endif // EDP_WINDOW_1_H
