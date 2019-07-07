#include "createdb.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

CreateDb::CreateDb()
{

}

void CreateDb::initDB() //创建数据库
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //连接数据库
    db.setHostName("HostName.db");  //加载数据库连接
    db.setDatabaseName("10"); //加载数据库
    bool ok = db.open();    //打开数据库 1为不存在 0为存在
    if(ok)  //如果不存在
    {
        qDebug()<<"Create DB";  //debug显示创建数据库

        QSqlQuery query;    //数据库输入类
        query.exec("create table StuManager (create_date datetime, "    //创造时间
                   "id varchar(4)  primary key, work varchar(20) ," //ID为主键的意思
                   " money INTEGER ,swimcard INTEGER)"); //消费券
        ok = query.exec("create table ShopManager (create_date datetime, "    //创造时间
                   "id varchar(4)  primary key, work varchar(20) ," //ID为主键的意思
                   " money INTEGER , buy INTEGER )"); //营业额
        ok = query.exec("create table BuyManager ( id INTEGER  primary key  AUTOINCREMENT,"    //ID为主键的意思
                   " id_card varchar(4) , money INTEGER , id_shop varchar(4) ," //ID为主键的意思
                   " create_date datetime , money_buy INTEGER , money_back INTEGER )"); //营业额
//         QString sql;
//         sql = QString("insert into BuyManager (id_card ,money ,id_shop ,create_date ,money_buy ,money_back)"
//                       " VALUES ('%0', '%1' , '%2' , '%3' , '%4' , '%5' )")
//                 .arg("1").arg("1").arg("1").arg("1").arg("1").arg("1");   //添加sql语句
//          ok = query.exec(sql);
        //创建表StuManager表和ShopManager表
    }
    else    //否则返回数据库名字
    {
        qDebug()<<db.databaseName();
    }
}

QList<QStringList> CreateDb::selectDataFromBase()   //数据库查询
{
    QSqlQuery query("SELECT * FROM StuManager");    //查ID卡的数据

    QList<QStringList> stuInfo;

    while (query.next())
    {
        QStringList rowData ;   //数据串

        rowData <<query.value(1).toString();    //ID
        rowData <<query.value(2).toString();    //职业
        rowData <<query.value(3).toString();    //金钱
        rowData <<query.value(4).toString();    //洗澡券
        stuInfo.append(rowData);    //添加到数据链中
    }
    return stuInfo;
}

QList<QStringList> CreateDb::selectDataFromBaseShop()   //数据库查询
{
    QSqlQuery query("SELECT * FROM ShopManager");    //查ID卡的数据

    QList<QStringList> stuInfo;

    while (query.next())
    {
        QStringList rowData ;   //数据串

        rowData <<query.value(1).toString();    //ID
        rowData <<query.value(2).toString();    //职业
        rowData <<query.value(3).toString();    //营业额
        rowData <<query.value(4).toString();    //交易单数
        stuInfo.append(rowData);    //添加到数据链中
    }
    return stuInfo;
}
QList<QStringList> CreateDb::selectDataFromBaseBuy()   //数据库查询
{
    QSqlQuery query("SELECT * FROM BuyManager");    //查ID卡的数据

    QList<QStringList> stuInfo;

    while (query.next())
    {
        QStringList rowData ;   //数据串

        rowData <<query.value(0).toString();    //ID
        rowData <<query.value(1).toString();    //卡号
        rowData <<query.value(2).toString();    //余额
        rowData <<query.value(3).toString();    //商家编号
        rowData <<query.value(4).toString();    //消费时间
        rowData <<query.value(5).toString();    //消费金额
        rowData <<query.value(6).toString();    //返还金额
        stuInfo.append(rowData);    //添加到数据链中
    }
    return stuInfo;
}
