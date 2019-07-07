#include "addstudlg.h"
#include "ui_addstudlg.h"
#include <QDateTime>
#include <QStringList>
#include <QString>
#include <QDebug>

AddStuDlg::AddStuDlg(QWidget *parent) :QDialog(parent),ui(new Ui::AddStuDlg)
{
    ui->setupUi(this);
    setFixedSize(sizeHint());

}

AddStuDlg::~AddStuDlg()
{
    delete ui;
}

void AddStuDlg::setEditData(QStringList rowData)    //编辑表
{
    ui->IDEdit->setText(rowData.at(0));
    ui->WorkEdit->setText(rowData.at(1));
    ui->MoneyEdit->setText(rowData.at(2));
    ui->SwimcardEdit->setText(rowData.at(3));
    ui->IDEdit->setEnabled(false);  //没明白
}

void AddStuDlg::clearData()
{
    ui->IDEdit->clear();
    ui->WorkEdit->clear();
    ui->MoneyEdit->clear();
    ui->SwimcardEdit->clear();
}

void AddStuDlg::closeEvent(QCloseEvent *event)  //关闭时存入数据
{
    clearData();
}

void AddStuDlg::on_buttonBox_accepted() //发送信息
{
    QVariantMap stuInfo;    //存储类

    QString id = ui->IDEdit->text();
    QString work = ui->WorkEdit->text();
    QString money = ui->MoneyEdit->text();
    QString swimcard = ui->SwimcardEdit->text();

    QString datetime = QDateTime::currentDateTime().toString();

    stuInfo.insert("datetime" ,datetime );
    stuInfo.insert("id" ,id );
    stuInfo.insert("work" ,work );
    stuInfo.insert("money" ,money );
    stuInfo.insert("swimcard" ,swimcard );

    emit signalStuInfo(stuInfo);    //发射存储信号
    ui->IDEdit->setEnabled(true);   //激活名字ID编辑栏
}

void AddStuDlg::on_buttonBox_rejected()
{
    ui->IDEdit->setEnabled(true);
    close();
}
