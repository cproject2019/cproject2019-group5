#include "mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent)
{
    tipLbl = new QLabel(this);
    tipLbl->setText(tr("welcome!"));
}
