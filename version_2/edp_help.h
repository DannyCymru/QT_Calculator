#ifndef EDP_HELP_H
#define EDP_HELP_H

#include <included_headers.h>

namespace Ui {
class edp_help;
}

class edp_help : public QMainWindow
{
    Q_OBJECT

public:
    explicit edp_help(QWidget *parent = 0);
    ~edp_help();

private:
    Ui::edp_help *ui;
};

#endif // EDP_HELP_H
