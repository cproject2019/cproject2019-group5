#include "buymanager.h"
#include "ui_buymanager.h"
BuyManager::BuyManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyManager)
{
    ui->setupUi(this);      //建立ui
    ui->tableWidget->setColumnCount(7); //四列
    ui->tableWidget->setRowCount(0);//0行
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() <<"deal record" << "card number"<< "balance"
                                               <<"shop number"<<"time of deal" << "money paid"<< "money backpaid" );

    ui->tableWidget->setAlternatingRowColors(true); //设置颜色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //整行选中
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//显示表头
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);  // 最后一列伸缩铺满

}

BuyManager::~BuyManager()
{
    delete ui;
}
void BuyManager::appendRowData(QStringList rowData) //显示行数据
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

void BuyManager::clearTableData()   //清空桌面
{
    //清除表格
    int rowCount = ui->tableWidget->rowCount(); //工作区当前行数
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->tableWidget->removeRow(r);  //清空
    }
}

QStringList BuyManager::getCurrentRowData()
{
    QStringList rowData;
    int row = ui->tableWidget->currentRow();    //当前table控件行数
    if(row != -1)   //将当前行数据存入rowData
    {
        rowData << ui->tableWidget->item(row , 0)->text();  //控件当前行列数据
        rowData << ui->tableWidget->item(row , 1)->text();
        rowData << ui->tableWidget->item(row , 2)->text();
        rowData << ui->tableWidget->item(row , 3)->text();
        rowData << ui->tableWidget->item(row , 4)->text();
        rowData << ui->tableWidget->item(row , 5)->text();
        rowData << ui->tableWidget->item(row , 6)->text();
    }
    return rowData;
}

QString BuyManager::getCurrentID()  //获取ID信息
{
    QString ID ;
    int row = ui->tableWidget->currentRow();
    if(row != -1)
    {
        ID =  ui->tableWidget->item(row , 0)->text();
    }
    return ID;
}
