#include "addshopdlg.h"
#include "ui_addshopdlg.h"
#include <QDateTime>
#include <QStringList>
#include <QString>
#include <QDebug>

addshopdlg::addshopdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addshopdlg)
{
    ui->setupUi(this);
    setFixedSize(sizeHint());       //设置字体
}

addshopdlg::~addshopdlg()
{
    delete ui;
}
void addshopdlg::setEditData(QStringList rowData)    //编辑表
{
    ui->IDEdit->setText(rowData.at(0));
    ui->WorkEdit->setText(rowData.at(1));
    ui->MoneyEdit->setText(rowData.at(2));
    ui->BuyEdit->setText(rowData.at(3));
    ui->IDEdit->setEnabled(false);  //没明白
}

void addshopdlg::clearData()    //清除ui数据
{
    ui->IDEdit->clear();
    ui->WorkEdit->clear();
    ui->MoneyEdit->clear();
    ui->BuyEdit->clear();
}

void addshopdlg::closeEvent(QCloseEvent *event)  //关闭时存入数据
{
    clearData();
}

void addshopdlg::on_buttonBox_accepted() //发射信息存储信号
{
    QVariantMap stuInfo;    //存储类

    QString id = ui->IDEdit->text();
    QString work = ui->WorkEdit->text();
    QString money = ui->MoneyEdit->text();
    QString buy = ui->BuyEdit->text();

    QString datetime = QDateTime::currentDateTime().toString();

    stuInfo.insert("datetime" ,datetime );
    stuInfo.insert("id" ,id );
    stuInfo.insert("work" ,work );
    stuInfo.insert("money" ,money );
    stuInfo.insert("buy" ,buy );

    emit signalStuInfo(stuInfo);    //发射存储信号
    ui->IDEdit->setEnabled(true);   //激活名字ID编辑栏
}

void addshopdlg::on_buttonBox_rejected() //关闭菜单
{
    ui->IDEdit->setEnabled(true);
    close();
}
