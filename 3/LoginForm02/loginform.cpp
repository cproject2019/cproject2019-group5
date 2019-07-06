﻿#include "loginform.h"
#include <QMessageBox>

LoginForm::LoginForm(QDialog *parent) :
    QDialog(parent)
{
    //设置窗体标题
    this->setWindowTitle(tr("login"));

    //用户名Label
    userNameLbl = new QLabel(this);
    userNameLbl->move(70,80);//移动到(70,80)位置(Label左上角坐标，相对于父窗体)
    userNameLbl->setText("type:");

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(120,80);
    userNameLEd->setPlaceholderText(tr("please enter type!"));//占位符

    //密码Label
    pwdLbl = new QLabel(this);
    pwdLbl->move(80,130);
    pwdLbl->setText("password:");

    //密码输入框
    pwdLEd = new QLineEdit(this);
    pwdLEd->move(120,130);
    pwdLEd->setPlaceholderText("please enter password!");
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn->move(80,200);
    loginBtn->setText("login");

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->move(170,200);
    exitBtn->setText("exit");

    //单击登录按钮时 执行 LoginForm::login 槽函数；//单击退出按钮时 执行 LoginForm::close 槽函数
    connect(loginBtn,&QPushButton::clicked,this,&LoginForm::login);
    connect(exitBtn,&QPushButton::clicked,this,&LoginForm::close);


}

void LoginForm::login()
{
    //获得userNameLEd输入框的文本userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，防止设置中文时乱码
    if(userNameLEd->text().trimmed() == tr("student") &&
           pwdLEd->text() == tr("123456"))
    {
       accept();//关闭窗体，并设置返回值为Accepted
    }
    else if(userNameLEd->text().trimmed() == tr("admin") &&
           pwdLEd->text() == tr("123456"))
    {
       accept();//关闭窗体，并设置返回值为Accepted
    }
    else {
       QMessageBox::warning(this, tr("warning！"),
                   tr("incorrect input!"),
                   QMessageBox::Yes);
       // 清空内容
       userNameLEd->clear();
       pwdLEd->clear();
       //定位光标
       userNameLEd->setFocus();
    }
}