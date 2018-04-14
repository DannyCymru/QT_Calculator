#ifndef EDP_WINDOW_2_H
#define EDP_WINDOW_2_H

#include <QMainWindow>
#include <included_headers.h>
#include <advanced_math.h>

namespace Ui {
class edp_window_2;
}

class edp_window_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit edp_window_2(QWidget *parent = 0);
    ~edp_window_2();

private slots:
    void digit_press();
    void period_press();
    void calc_save();
    void help_view();
    void add_press();
    void sub_press();
    void div_press();
    void mult_press();
    void clr_press();
    void result_press();

private:
    //Functions
    void create_menus();
    void create_actions();
    void create_rbuttons();
    void create_lbuttons();
    void create_smath_buttons();
    void qt_history(QStringList edp2_List);
    void operator_setup();

    //Objects

    //menubar
    QMenu *file_menu;
    QMenu *help;
    QMenu *view;
    QAction *save_action;
    QAction *help_action;
    QListView *history;
    QStringListModel *history_list;
    QVector<QString> all_calculations;
    //Content Labels
    QString pushback_container;
    QLabel *result_label;
    //rbuttons
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
    QTimer *clear_timer;
    //lbuttons
    QRadioButton *decimal_radio;
    QRadioButton *octal_radio;
    QRadioButton *hex_radio;
    QRadioButton *binary_radio;
    //Pointers
    advanced_math *a_math;
    Ui::edp_window_2 *ui;
};

#endif // EDP_WINDOW_2_H
