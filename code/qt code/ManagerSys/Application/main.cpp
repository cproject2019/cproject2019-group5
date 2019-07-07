#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextCodec>
#include <QCoreApplication>
#include <QFont>
#include <QTextStream>
#include "mainform.h"
#include "loginform.h"

int mainlogin(int argc,char** argv)
{
    QApplication app(argc,argv);
    MainForm *mainlogin = new MainForm();
    mainlogin->setWindowTitle("欢迎界面");

    LoginForm login;
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回
    {
       mainlogin->show();
       return app.exec();
    }
    else return 0;
}

int main(int argc, char *argv[])
{
    QTextCodec *pCodec = QTextCodec::codecForName("GBK");
    if(pCodec)
    {
        QTextCodec::setCodecForLocale(pCodec);
    }

    QCoreApplication::setApplicationName("StuTest");

    QApplication a(argc, argv);

    QFile file("../Styles/white.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString style = in.readAll();
        file.close();
        qApp->setStyleSheet(style);
    }

    QFont serifFont("Times", 12, QFont::Thin);
    a.setFont(serifFont);

    MainWindow w;
    w.setWindowTitle(QObject::tr("campus card managing system"));
    w.hide();

    MainForm *mainlogin = new MainForm();
    mainlogin->setWindowTitle("欢迎界面");

    LoginForm login;
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回
    {
           w.show();
    return a.exec();
    }

}
