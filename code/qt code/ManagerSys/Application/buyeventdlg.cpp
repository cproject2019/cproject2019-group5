#include "buyeventdlg.h"
#include "ui_buyeventdlg.h"
#include <QDateTime>
#include <QStringList>
#include <QString>
#include <QDebug>

BuyEventdlg::BuyEventdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyEventdlg)
{
    ui->setupUi(this);
        setFixedSize(sizeHint());       //设置字体
}

BuyEventdlg::~BuyEventdlg()
{
    delete ui;
}
void BuyEventdlg::setEditData(QStringList rowData)    //编辑表
{
    ui->CardIDEdit->setText(rowData.at(0));
    ui->CardIDEdit->setText(rowData.at(1));
    ui->CardIDEdit->setText(rowData.at(2));
    ui->CardIDEdit->setText(rowData.at(3));
    ui->CardIDEdit->setText(rowData.at(4));
    ui->CardIDEdit->setText(rowData.at(5));
    ui->CardIDEdit->setText(rowData.at(6));
    ui->CardIDEdit->setEnabled(false);  //没明白
}

void BuyEventdlg::clearData()    //清除ui数据
{
    ui->CardIDEdit->clear();
    ui->ShopIDEdit->clear();
    ui->ShopTypeEdit->clear();
    ui->MoneyEdit->clear();
    ui->SwimEdit->clear();
}

void BuyEventdlg::closeEvent(QCloseEvent *event)  //关闭时存入数据
{
    clearData();
}

void BuyEventdlg::on_buttonBox_accepted() //发射信息存储信号
{
    QVariantMap stuInfo;    //存储类

    QString card_id = ui->CardIDEdit->text();
    QString shop_id = ui->ShopIDEdit->text();
    QString shoptype = ui->ShopTypeEdit->text();
    QString cardtype = ui->CardTypeEdit->text();
    QString money = ui->MoneyEdit->text();  //消费金额
    QString swim = ui->SwimEdit->text();    //洗澡时间

    QString datetime = QDateTime::currentDateTime().toString();

    stuInfo.insert("card_id" ,card_id );
    stuInfo.insert("shop_id" ,shop_id );
    stuInfo.insert("cardtype" ,cardtype );
    stuInfo.insert("shoptype" ,shoptype );
    stuInfo.insert("money" ,money );
    stuInfo.insert("swim" ,swim );
    stuInfo.insert("datetime" ,datetime );

    emit signalStuInfo(stuInfo);    //发射存储信号
    ui->CardIDEdit->setEnabled(true);   //激活名字ID编辑栏
}

void BuyEventdlg::on_buttonBox_rejected() //关闭菜单
{
    ui->CardIDEdit->setEnabled(true);
    close();
}
