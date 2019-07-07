#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "StuManager.h"
#include "ShopManager.h"
#include "buymanager.h"
#include "createdb.h"
#include "addstudlg.h"
#include "addshopdlg.h"
#include "buyeventdlg.h"


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum OperateType
    {
        Add ,
        Edit ,
        SHOPAdd,
        SHOPEdit,
        BUYAdd,
        BUYEdit
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //校园卡
    void onBtnAdd();    //增信号

    void onBtnEdit();   //改

    void onBtnDel();    //删

    void onBtnRefresh();    //查

    void ExecAddSql(QVariantMap stuInfo);   //数据库加

    void ExecEditSql(QVariantMap stuInfo);  //数据库改

    void ExecDelSql(QString id);    //数据库删
    //商店
    void onBtnshopAdd();    //增信号

    void onBtnshopEdit();   //改 可能存在问题m_pTableWidget

    void onBtnshopDel();    //删 可能存在问题m_pTableWidget

    void onBtnshopRefresh();    //查 可能存在问题m_pTableWidget


    void ExecshopAddSql(QVariantMap stuInfo);   //数据库加

    void ExecshopEditSql(QVariantMap stuInfo);  //数据库改

    void ExecshopDelSql(QString id);    //数据库删
    //交易记录
    void onBtnbuyAdd();    //增信号

    void onBtnbuyEdit();   //改 可能存在问题m_pTableWidget

    void onBtnbuyDel();    //删 可能存在问题m_pTableWidget

    void onBtnbuyRefresh();    //查 可能存在问题m_pTableWidget


    void ExecbuyAddSql(QVariantMap stuInfo);   //数据库加

    void ExecbuyEditSql(QVariantMap stuInfo);  //数据库改

    void ExecbuyDelSql(QString id);    //数据库删



private:
    void initUi();  //ui初始化

    void setTabCornerBtn(); //设置桌面

    void initAddDlg();  //添加 设置完毕

private:
    Ui::MainWindow *ui;
    QTabWidget *m_pTabWidget;

    ShopManager *m_pShoWidget;
    StuManager *m_pTableWidget;
    BuyManager *m_pBuyWidget;

    CreateDb *m_pCreateDb;

    AddStuDlg* m_pAddStuDlg;
    addshopdlg* m_pAddShopDlg;
    BuyEventdlg *m_buyeventDlg;

    OperateType m_operateType;
};

#endif // MAINWINDOW_H
