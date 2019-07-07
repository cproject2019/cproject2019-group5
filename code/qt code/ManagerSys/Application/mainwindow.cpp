#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //ui

    initUi();   //初始化ui 左边的TableWidget

    initAddDlg();   //添加输入connect

    setTabCornerBtn();  //添加按钮功能

    m_pCreateDb = new CreateDb;

    m_pCreateDb->initDB();  //打开数据库

    onBtnRefresh(); //程序启动时，查询数据

    showMaximized();    //最大化

    m_operateType = Add;    //设置当前模式为添加
}

MainWindow::~MainWindow()
{
    delete ui;
}
//增
void MainWindow::onBtnAdd() //增
{
    qDebug()<<"onBtnAdd";
    m_operateType = Add;    //增信号
    if(m_pAddStuDlg)
    {
        m_pAddStuDlg->activateWindow(); //增加窗口置顶
        m_pAddStuDlg->setWindowTitle(tr("add student imfo"));
        m_pAddStuDlg->exec();   //开始运行
    }
}
void MainWindow::onBtnshopAdd()
{
        qDebug()<<"onBtnshopAdd";
        m_operateType = SHOPAdd;    //商店增信号
        if(m_pAddShopDlg)
        {
            m_pAddShopDlg->activateWindow(); //增加窗口置顶
            m_pAddShopDlg->setWindowTitle(tr("add shop info"));
            m_pAddShopDlg->exec();   //开始运行
        }
}
void MainWindow::onBtnbuyAdd()  //交易添加按钮
{
        qDebug()<<"onBtnbuyAdd";
        m_operateType = BUYAdd;    //商店增信号
        if(m_buyeventDlg)
        {
            m_buyeventDlg->activateWindow(); //增加窗口置顶
            m_buyeventDlg->setWindowTitle(tr("add deal info"));
            m_buyeventDlg->exec();   //开始运行
        }
}
//改
void MainWindow::onBtnEdit()    //改
{
    qDebug()<<"onBtnEdit";

    m_operateType = Edit;   //改信号

    QStringList rowData ;
    rowData = m_pTableWidget->getCurrentRowData();  //得到当前鼠标选中行数据数据
    if(rowData.isEmpty())   //如果没有选中行
    {
        QMessageBox::information(this, tr("attention!") , tr("please choose the data to be changed!"));
        return ;
    }
    else
    {
        m_pAddStuDlg->setEditData(rowData); //将当前行数据存到add窗口中
    }

    m_pAddStuDlg->activateWindow(); //将add变为顶体窗口
    m_pAddStuDlg->setWindowTitle(tr("change student info"));   //题目为
    m_pAddStuDlg->exec();   //相当于show,弹窗
}
void MainWindow::onBtnshopEdit()    //商店改
{
    qDebug()<<"onBtnshopEdit";

    m_operateType = SHOPEdit;   //改信号

    QStringList rowData ;
    rowData = m_pShoWidget->getCurrentRowData();  //得到当前鼠标选中行数据数据
    if(rowData.isEmpty())   //如果没有选中行
    {
        QMessageBox::information(this, tr("attention!") , tr("please choose the data to be changed!"));
        return ;
    }
    else
    {
        m_pAddShopDlg->setEditData(rowData); //将当前行数据存到add窗口中
    }

    m_pAddShopDlg->activateWindow(); //将add变为顶体窗口
    m_pAddShopDlg->setWindowTitle(tr("change shop info"));   //题目为
    m_pAddShopDlg->exec();   //相当于show,弹窗
}
void MainWindow::onBtnbuyEdit()    //修改交易记录
{
    qDebug()<<"onBtnshopEdit";

    m_operateType = BUYEdit;   //改信号

    QStringList rowData ;
    rowData = m_pBuyWidget->getCurrentRowData();  //得到当前鼠标选中行数据数据
    if(rowData.isEmpty())   //如果没有选中行
    {
        QMessageBox::information(this, tr("attention!") , tr("please choose the data to be changed!"));
        return ;
    }
    else
    {
        m_buyeventDlg->setEditData(rowData); //将当前行数据存到add窗口中
    }

    m_buyeventDlg->activateWindow(); //将add变为顶体窗口
    m_buyeventDlg->setWindowTitle(tr("change shop info"));   //题目为
    m_buyeventDlg->exec();   //相当于show,弹窗
}
void MainWindow::onBtnDel()
{
    qDebug()<<"onBtnDel";
    QString ID = m_pTableWidget->getCurrentID();
    if(ID.isEmpty())
    {
        QMessageBox::information(this , tr("attention!") , tr("please choose the data to be changed!"));
        return ;
    }

    QMessageBox::StandardButton button = QMessageBox::question(this , tr("attention!") ,tr("Do you really want to delete it？"));
    if(button == QMessageBox::Yes)
    {
        //删除操作
        ExecDelSql(ID); //删除ID
    }
}

//删
void MainWindow::onBtnshopDel() //商店改
{
    qDebug()<<"onBtnshopDel";
    QString ID = m_pShoWidget->getCurrentID();
    if(ID.isEmpty())
    {
        QMessageBox::information(this , tr("attention") , tr("please choose the data to be changed！"));
        return ;
    }

    QMessageBox::StandardButton button = QMessageBox::question(this , tr("attention!") ,tr("Do you really want to delete it？"));
    if(button == QMessageBox::Yes)
    {
        //删除操作
        ExecshopDelSql(ID); //删除ID
    }
}
void MainWindow::onBtnbuyDel() //交易记录撤销
{
    qDebug()<<"onBtnbuyDel";
    QString ID = m_pBuyWidget->getCurrentID();
    if(ID.isEmpty())
    {
        QMessageBox::information(this , tr("attention!") , tr("please choose the data to be changed！"));
        return ;
    }

    QMessageBox::StandardButton button = QMessageBox::question(this , tr("attention!") ,tr("Do you really want to delete it？"));
    if(button == QMessageBox::Yes)
    {
        //删除操作
        ExecbuyDelSql(ID); //删除ID
    }
}
void MainWindow::onBtnRefresh() //添加重载数据
{
    qDebug()<<"onBtnRefresh";
    QList<QStringList> tableData;

    tableData = m_pCreateDb->selectDataFromBase();  //所有数据
    if(!tableData.isEmpty())    //不为空
    {
        m_pTableWidget->clearTableData();   //清空桌面数据
        QListIterator<QStringList> itr(tableData);
        while(itr.hasNext())
        {
            m_pTableWidget->appendRowData(itr.next());  //添加行数据在m_pTableWidget桌面
        }
    }
}
void MainWindow::onBtnshopRefresh() //添加重载数据
{
    qDebug()<<"onBtnshopRefresh";
    QList<QStringList> tableData;

    tableData = m_pCreateDb->selectDataFromBaseShop();  //所有数据
    if(!tableData.isEmpty())    //不为空
    {
        m_pShoWidget->clearTableData();   //清空桌面数据
        QListIterator<QStringList> itr(tableData);
        while(itr.hasNext())
        {
            m_pShoWidget->appendRowData(itr.next());  //添加行数据在m_pTableWidget桌面
        }
    }
}
void MainWindow::onBtnbuyRefresh() //添加重载数据
{
    qDebug()<<"onBtnbuyRefresh";
    QList<QStringList> tableData;

    tableData = m_pCreateDb->selectDataFromBaseBuy();  //所有数据
    if(!tableData.isEmpty())    //不为空
    {
        m_pBuyWidget->clearTableData();   //清空桌面数据
        QListIterator<QStringList> itr(tableData);
        while(itr.hasNext())
        {
            m_pBuyWidget->appendRowData(itr.next());  //添加行数据在m_pTableWidget桌面
        }
    }
}
//数据库添加
void MainWindow::ExecAddSql(QVariantMap stuInfo)    //添加
{
    if(m_operateType == Add)    //操作种类为添加
    {
        QString create_date = stuInfo.value("datetime").toString();
        QString id = stuInfo.value("id").toString();
        QString work = stuInfo.value("work").toString();
        QString money = stuInfo.value("money").toString();
        QString swimcard = stuInfo.value("swimcard").toString();

        QString sql;
        sql = QString("insert into StuManager (create_date,id ,work ,money ,swimcard )"
                      " VALUES ('%0', '%1' , '%2' , '%3' , '%4')")
                .arg(create_date).arg(id).arg(work).arg(money).arg(swimcard);   //添加sql语句
        qDebug()<<sql;    //测试
        QSqlQuery query;
        bool ok = query.exec(sql);  //输入数据库
        if(ok)  //添加成功
        {
            QStringList rowData;    //饭后队列
            rowData <<id <<work <<money << swimcard; //将这些字符串加到rowData中
            m_pTableWidget->appendRowData(rowData); //添加行数据

            QMessageBox::information(this ,tr("attention!") , tr("succeed!")); //提示成功
        }
        else
        {
            QMessageBox::information(this ,tr("attention!") , tr("fail!")); //提示失败
        }
    }
}

void MainWindow::ExecshopAddSql(QVariantMap stuInfo)    //添加
{
    if(m_operateType == SHOPAdd)    //操作种类为添加
    {
        QString create_date = stuInfo.value("datetime").toString();
        QString id = stuInfo.value("id").toString();
        QString work = stuInfo.value("work").toString();
        QString money = stuInfo.value("money").toString();
        QString buy = stuInfo.value("buy").toString();
        QString sql;
        sql = QString("insert into ShopManager (create_date,id ,work ,money ,buy)"
                      " VALUES ('%0', '%1' , '%2' , '%3' , '%4')")
                .arg(create_date).arg(id).arg(work).arg(money).arg(buy);   //添加sql语句
        qDebug()<<sql;    //测试
        QSqlQuery query;
        bool ok = query.exec(sql);  //输入数据库
        if(ok)  //添加成功
        {
            QStringList rowData;    //行数据
            rowData <<id <<work <<money; //将这些字符串加到rowData中
            m_pShoWidget->appendRowData(rowData); //显示行数据

            QMessageBox::information(this ,tr("attention!") , tr("succeed!")); //提示成功
        }
        else
        {
            QMessageBox::information(this ,tr("attention!") , tr("fail!")); //提示失败
        }
    }
}

void MainWindow::ExecbuyAddSql(QVariantMap stuInfo)    //添加
{
    if(m_operateType == BUYAdd)    //操作种类为添加
    {
        QString card_id = stuInfo.value("card_id").toString();    //校园卡号
        QString shop_id = stuInfo.value("shop_id").toString();  //商店卡号
        QString cardtype = stuInfo.value("cardtype").toString();    //卡片种类
        QString shoptype = stuInfo.value("shoptype").toString();    //商店种类
        QString money = stuInfo.value("money").toString();  //花费金钱
        QString swim = stuInfo.value("swim").toString();    //洗澡时间
        QString datetime = stuInfo.value("datetime").toString();  //消费时间
        int money_back = 0,money_card = 0,money_shop = 0,money_buy = 0;//返还金额,卡金额,营业额,消费金额
        int swim_card = 0,buy = 0;  //消费券 交易单数
        QString cardsql;    //查询学生的信息
        QString shopsql;
        QSqlQuery query;
        cardsql = QString("SELECT * FROM StuManager where id = '%0'").arg(card_id);
        bool ok = query.exec(cardsql);
        if(!ok)
        {
           QMessageBox::information(this ,tr("attention!") , tr("do not exist!"));
           return;
        }
        QSqlQuery querystu(cardsql);
        while(querystu.next())
        {
            cardtype =   querystu.value(2).toString();   //职业
            money_card = querystu.value(3).toInt(); //卡金额
            swim_card = querystu.value(4).toInt();  //消费券
        }
        shopsql = QString("SELECT * FROM ShopManager where id = '%0'").arg(shop_id);
        ok = query.exec(shopsql);
        if(!ok)
        {
            QMessageBox::information(this ,tr("attention!") , tr("do not exist!"));
            return;
        }
        QSqlQuery queryshop(shopsql);
        while(queryshop.next())
        {
            shoptype =   queryshop.value(2).toString();   //职业
            money_shop = queryshop.value(3).toInt(); //卡金额
            buy = queryshop.value(4).toInt();  //交易单数
        }


        if(!((shoptype == "食堂")||(shoptype == "超市")||(shoptype == "浴池"))) //判断超市种类输入正确
            {
            QMessageBox::information(this ,tr("attention!") , tr("do not exist or incorrect type!"));
            return;
        }
        if(!((cardtype == "学生")||(cardtype == "教师")||(cardtype == "职工"))) //判断学生种类输入正确
            {
            QMessageBox::information(this ,tr("attention!") , tr("do not exist or incorrect type!"));
            return;
        }
        int buymoney = money.toInt();   //需要计算的花费金额和消费券改为整形
        int swimtime = swim.toInt();
        if(money_card < buymoney)//先判断校园卡是否有足够的钱
            {
            QMessageBox::information(this ,tr("attention!") , tr("no enough money!"));
            return;
        }
        if(money_card < ((swimtime-10)/5+2))//先判断校园卡是否有足够的钱
            {
            QMessageBox::information(this ,tr("attention!") , tr("no enough money!"));
            return;
        }
        if(shoptype == "食堂")
            {
                if(buymoney > 50)
                    {
                     QMessageBox::information(this ,tr("attention") , tr("more than 50 yuan for one time!"));
                }
                if((buymoney > 20)&&((cardtype == "教师")||(cardtype == "职工")))
                    {
                    money_back = 5;
                    money_card = money_card  + money_back;    //卡 = 卡 +返
                }
                money_card = money_card - buymoney; //卡 = 卡 - 花
                money_buy = buymoney;
        }
        else if(shoptype == "超市")
            {
                money_card = money_card - buymoney; //卡 = 卡 - 花
                money_buy = buymoney;
        }
        else if(shoptype == "浴池")
            {
                if(swim_card>= swim.toInt())
                    {
                        swim_card = swim_card - swimtime;
                        money_buy = 0;
                        money_card = money_card - money_buy;
                }
                else if((swim_card+10)>=swim.toInt()){
                    swim_card = 0;
                    money_buy = 2;
                    money_card = money_card - money_buy;
                }
                else{
                        money_buy = (swim.toInt() -swim_card-10)*2/10 + 2; //花费金额
                        swim_card = 0;
                        money_card = money_card - money_buy;
                    }
        }
        buy++;
        money_shop = money_shop + money_buy;
        QString id = card_id;
        QString money_card_str = QString::number(money_card, 10);
        QString money_str = QString::number(money_buy, 10);
        QString money_back_str  = QString::number(money_back, 10);
        QString sql;
        QString shopsetsql;
        QString stusetsql;
        shopsetsql = QString("UPDATE ShopManager "
                      "set money = '%0', buy = '%1' where id = '%2' ")
                .arg(QString::number(money_shop, 10)).arg(QString::number(buy, 10)).arg(shop_id);
        ok = queryshop.exec(shopsetsql);
        stusetsql = QString("UPDATE StuManager "
                            "set money = '%0', swimcard = '%1' where id = '%2' ")
                .arg(money_card_str).arg(QString::number(swim_card, 10)).arg(card_id);
        ok = queryshop.exec(stusetsql);

//        sql = QString("insert into BuyManager (id,id_card ,money ,id_shop ,create_date ,money_buy ,money_back)"
//                      " VALUES ('%0', '%1' , '%2' , '%3' , '%4' , '%5' , '%6')")
//        .arg(id).arg(card_id).arg(card_id).arg(shop_id).arg(datetime).arg(money_str).arg(money_back_str);   //添加sql语句
        sql = QString("insert into BuyManager ( id_card ,money ,id_shop ,create_date ,money_buy ,money_back)"
                      " VALUES ('%0', '%1' , '%2' , '%3' , '%4' , '%5' )")
        .arg(card_id).arg(card_id).arg(shop_id).arg(datetime).arg(money_str).arg(money_back_str);   //添加sql语句
                qDebug()<<sql;    //测试
        QSqlQuery querybuy;
        ok = querybuy.exec(sql);  //输入数据库
        if(ok)  //添加成功
        {
            QStringList rowData;    //行数据

            rowData <<"" <<card_id <<money_card_str<<shop_id<<datetime<<money_str<<money_back_str; //将这些字符串加到rowData中
            m_pBuyWidget->appendRowData(rowData); //显示行数据

            QMessageBox::information(this ,tr("attention!") , tr("succeed!")); //提示成功
        }
        else
        {
            QMessageBox::information(this ,tr("attention") , tr("fail!")); //提示失败
        }
    }
}

void MainWindow::ExecEditSql(QVariantMap stuInfo)   //修改信号
{
    if(m_operateType == Edit)   //信号种类为修改时
    {
        QString create_date = stuInfo.value("datetime").toString();
        QString id = stuInfo.value("id").toString();
        QString work = stuInfo.value("work").toString();
        QString money = stuInfo.value("money").toString();
        QString swimcard = stuInfo.value("swimcard").toString();

        QString sql;
        sql = QString("UPDATE StuManager "
                      "set create_date = '%0' ,id = '%1' ,work = '%2',"
                      "money = '%3' where id = '%4' ")
                .arg(create_date).arg(id).arg(work).arg(money).arg(swimcard).arg(id);

        QSqlQuery query;
        bool ok = query.exec(sql);
        if(ok)
        {
            onBtnRefresh(); //重新加载数据
            QMessageBox::information(this ,tr("attention!") , tr("succeed!")); //修改成功
        }
        else
        {
            QMessageBox::information(this ,tr("attention") , tr("fail!"));
        }
    }
}

void MainWindow::ExecshopEditSql(QVariantMap stuInfo)   //修改信号
{
    if(m_operateType == SHOPEdit)   //信号种类为修改时
    {
        QString create_date = stuInfo.value("datetime").toString();
        QString id = stuInfo.value("id").toString();
        QString work = stuInfo.value("work").toString();
        QString money = stuInfo.value("money").toString();
        QString buy = stuInfo.value("buy").toString();
        QString sql;
        sql = QString("UPDATE ShopManager "
                      "set create_date = '%0' ,id = '%1' ,work = '%2',"
                      "money = '%3', buy = '%4' where id = '%5' ")
                .arg(create_date).arg(id).arg(work).arg(money).arg(buy).arg(id);

        QSqlQuery query;
        bool ok = query.exec(sql);
        if(ok)
        {
            onBtnRefresh(); //重新加载数据
            QMessageBox::information(this ,tr("attention!") , tr("succeed!")); //修改成功
        }
        else
        {
            QMessageBox::information(this ,tr("attention") , tr("fail!"));
        }
    }
}

void MainWindow::ExecbuyEditSql(QVariantMap stuInfo)   //修改信号
{
    if(m_operateType == BUYEdit)   //信号种类为修改时
    {
//        QString id = stuInfo.value("id").toString();    //id
//        QString id_card = stuInfo.value("id_card").toString();  //卡号
//        QString money = stuInfo.value("money").toString();  //余额
//        QString id_shop = stuInfo.value("id_shop").toString();  //商家编号
//        QString datetime = stuInfo.value("datetime").toString();    //消费时间
//        QString money_buy = stuInfo.value("money_buy").toString();  //商家编号
//        QString money_back = stuInfo.value("money_back").toString();    //消费时间
//        QString sql;
//        sql = QString("UPDATE ShopManager "
//                      "set id = '%0' ,id_card = '%1' ,money = '%2',"
//                      "id_shop = '%3', datetime = '%4',money_buy = '%5' ,"
//                      " money_back = '%6' where id = '%7' ")
//                .arg(id).arg(id_card).arg(money).arg(id_shop).arg(datetime).arg(money_buy).arg(money_back).arg(id);   //添加sql语句

//        QSqlQuery query;
//        bool ok = query.exec(sql);
//        if(ok)
//        {
//            onBtnRefresh(); //重新加载数据
//            QMessageBox::information(this ,tr("attention！") , tr("succeed!")); //修改成功
//        }
//        else
//        {
//            QMessageBox::information(this ,tr("attention!") , tr("fail!"));
//        }
    }
}

void MainWindow::ExecDelSql(QString id)
{
    QString sql;
    sql = QString("DELETE FROM StuManager "
                  " where id = '%0' ").arg(id);

    QSqlQuery query;
    bool ok = query.exec(sql);
    if(ok)
    {
        onBtnRefresh(); //重新加载数据
        QMessageBox::information(this ,tr("attention!") , tr("succeed!"));
    }
    else
    {
        QMessageBox::information(this ,tr("attention") , tr("fail!"));
    }
}

void MainWindow::ExecshopDelSql(QString id)
{
    QString sql;
    sql = QString("DELETE FROM ShopManager "
                  " where id = '%0' ").arg(id);

    QSqlQuery query;
    bool ok = query.exec(sql);
    if(ok)
    {
        onBtnshopRefresh(); //重新加载数据
        QMessageBox::information(this ,tr("attention!") , tr("succeed!"));
    }
    else
    {
        QMessageBox::information(this ,tr("attention!") , tr("fail!"));
    }
}

void MainWindow::ExecbuyDelSql(QString id)
{
    QString sql;
    sql = QString("DELETE FROM BuyManager "
                  " where id = '%0' ").arg(id);

    QSqlQuery query;
    bool ok = query.exec(sql);
    if(ok)
    {
        onBtnbuyRefresh(); //重新加载数据
        QMessageBox::information(this ,tr("attention!") , tr("succeed!"));
    }
    else
    {
        QMessageBox::information(this ,tr("attention!") , tr("fail!"));
    }
}

void MainWindow::initUi()
{
    m_pTableWidget = new StuManager;    //学生窗口
    m_pShoWidget = new ShopManager;     //商店窗口
    m_pBuyWidget =  new BuyManager;  //交易窗口

    m_pTabWidget = new QTabWidget(this);    //窗口区
    m_pTabWidget->addTab(m_pTableWidget , tr("manage cards")); //添加校园卡窗口
    m_pTabWidget->addTab(m_pShoWidget ,tr("manage shops")); //添加商家窗口
    m_pTabWidget->addTab(m_pBuyWidget ,tr("deal records")); //添加商家窗口
    setStyleSheet("QTabBar::tab{min-width:30ex; min-height:10ex;}");    //小部件每格大小

    setCentralWidget(m_pTabWidget); //生成窗口
    setContentsMargins(5 , 10, 5 ,5);   //小部件边距
}

void MainWindow::setTabCornerBtn()  //创建按钮
{
    //校园卡
    QPushButton *btnRefresh = new QPushButton;
    btnRefresh->setText(tr("card refresh"));

    QPushButton *btnAdd = new QPushButton;
    btnAdd->setText(tr("add card"));

    QPushButton *btnEdit = new QPushButton;
    btnEdit->setText(tr("change card"));

    QPushButton *btnDel = new QPushButton;
    btnDel->setText(tr("delete carff"));
    //商家
    QPushButton *btnshopRefresh = new QPushButton;
    btnshopRefresh->setText(tr("shop refresh"));

    QPushButton *btnshopAdd = new QPushButton;
    btnshopAdd->setText(tr("add shop"));

    QPushButton *btnshopEdit = new QPushButton;
    btnshopEdit->setText(tr("change shop"));

    QPushButton *btnshopDel = new QPushButton;
    btnshopDel->setText(tr("delete shop"));
    //交易记录
    QPushButton *btnbuyRefresh = new QPushButton;
    btnbuyRefresh->setText(tr("deal refresh"));

    QPushButton *btnbuyAdd = new QPushButton;
    btnbuyAdd->setText(tr("add deal"));

    QPushButton *btnbuyEdit = new QPushButton;
    btnbuyEdit->setText(tr("change deal"));

    QPushButton *btnbuyDel = new QPushButton;
    btnbuyDel->setText(tr("delete deal"));

    QWidget *widget = new QWidget;  //窗口
    widget->setMinimumSize(20 ,55);
    widget->setContentsMargins(0,0,0,10);

    QHBoxLayout *hLayout = new QHBoxLayout(widget); //创建group
    hLayout->addWidget(btnRefresh);
    hLayout->addWidget(btnAdd);
    hLayout->addWidget(btnEdit);
    hLayout->addWidget(btnDel);
    hLayout->addWidget(btnshopRefresh);
    hLayout->addWidget(btnshopAdd);
    hLayout->addWidget(btnshopEdit);
    hLayout->addWidget(btnshopDel);
    hLayout->addWidget(btnbuyRefresh);
    hLayout->addWidget(btnbuyAdd);
    hLayout->addWidget(btnbuyEdit);
    hLayout->addWidget(btnbuyDel);

    widget->setLayout(hLayout);
    m_pTabWidget->setCornerWidget(widget ,Qt::TopRightCorner);  //显示窗口
      //增删改插的信号与槽
    connect(btnRefresh , SIGNAL(clicked(bool)) , this ,SLOT(onBtnRefresh()));   //刷新(查)
    connect(btnAdd , SIGNAL(clicked(bool)) , this ,SLOT(onBtnAdd()));   //增
    connect(btnEdit , SIGNAL(clicked(bool)), this ,SLOT(onBtnEdit()));  //改
    connect(btnDel , SIGNAL(clicked(bool)) ,this , SLOT(onBtnDel()));   //删
    connect(btnshopRefresh , SIGNAL(clicked(bool)) , this ,SLOT(onBtnshopRefresh()));   //刷新(查)
    connect(btnshopAdd , SIGNAL(clicked(bool)) , this ,SLOT(onBtnshopAdd()));   //增
    connect(btnshopEdit , SIGNAL(clicked(bool)), this ,SLOT(onBtnshopEdit()));  //改
    connect(btnshopDel , SIGNAL(clicked(bool)) ,this , SLOT(onBtnshopDel()));   //删
    connect(btnbuyRefresh , SIGNAL(clicked(bool)) , this ,SLOT(onBtnbuyRefresh()));   //刷新(查)
    connect(btnbuyAdd , SIGNAL(clicked(bool)) , this ,SLOT(onBtnbuyAdd()));   //增
    connect(btnbuyEdit , SIGNAL(clicked(bool)), this ,SLOT(onBtnbuyEdit()));  //改
    connect(btnbuyDel , SIGNAL(clicked(bool)) ,this , SLOT(onBtnbuyDel()));   //删
}

void MainWindow::initAddDlg()   //添加窗初始化
{
    m_pAddStuDlg = new AddStuDlg;
    m_pAddShopDlg = new addshopdlg;
    m_buyeventDlg = new BuyEventdlg;
    connect(m_pAddStuDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecAddSql(QVariantMap)));   //发送添加sql函数
    connect(m_pAddStuDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecEditSql(QVariantMap)));   //发送修改sql函数
    connect(m_pAddShopDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecshopAddSql(QVariantMap)));   //发送添加商店sql函数
    connect(m_pAddShopDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecshopEditSql(QVariantMap)));   //发送修改商店sql函数
    connect(m_buyeventDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecbuyAddSql(QVariantMap)));   //发送添加交易sql函数
    connect(m_buyeventDlg , SIGNAL(signalStuInfo(QVariantMap)) , this ,SLOT(ExecbuyEditSql(QVariantMap)));   //发送交易sql函数
}
