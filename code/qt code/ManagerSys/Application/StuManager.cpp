#include "StuManager.h"
#include "ui_StuManager.h"
#include <QTableWidgetItem>
#include <QHeaderView>

StuManager::StuManager(QWidget *parent) : QWidget(parent), ui(new Ui::StuManager)
{
    ui->setupUi(this);      //建立ui
    ui->tableWidget->setColumnCount(4); //四列
    ui->tableWidget->setRowCount(0);//0行
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"ID" << "jobs"<< "balance"
                                               <<"tickets" );

    ui->tableWidget->setAlternatingRowColors(true); //设置颜色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);  // 最后一列伸缩铺满
}

StuManager::~StuManager()
{
    delete ui;
}

void StuManager::appendRowData(QStringList rowData) //显示行数据
{
    int row = ui->tableWidget->rowCount();  //当前行数

    ui->tableWidget->insertRow(row);    //添加行数

    for(int i  = 0 ; i < rowData.size() ; i++)  //
    {
        QTableWidgetItem *item = new QTableWidgetItem;  //新建表
        item->setText(rowData.at(i));   //控件显示行数据
        ui->tableWidget->setItem(row , i , item);   //table窗口添加行数据控件
    }
}

void StuManager::clearTableData()   //清空桌面
{
    //清除表格
    int rowCount = ui->tableWidget->rowCount(); //工作区当前行数
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->tableWidget->removeRow(r);  //清空
    }
}

QStringList StuManager::getCurrentRowData()
{
    QStringList rowData;
    int row = ui->tableWidget->currentRow();    //当前table控件行数
    if(row != -1)   //将当前行数据存入rowData
    {
        rowData << ui->tableWidget->item(row , 0)->text();  //控件当前行列数据
        rowData << ui->tableWidget->item(row , 1)->text();
        rowData << ui->tableWidget->item(row , 2)->text();
        rowData << ui->tableWidget->item(row , 3)->text();

    }
    return rowData;
}

QString StuManager::getCurrentID()  //获取ID信息
{
    QString ID ;
    int row = ui->tableWidget->currentRow();
    if(row != -1)
    {
        ID =  ui->tableWidget->item(row , 0)->text();
    }
    return ID;
}
