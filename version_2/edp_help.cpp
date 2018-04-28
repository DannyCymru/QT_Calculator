#include "edp_help.h"
#include "ui_edp_help.h"

edp_help::edp_help(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::edp_help)
{
    ui->setupUi(this);
}

edp_help::~edp_help()
{
    delete ui;
}
