#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <QWidget>

namespace Ui {
class ShopManager;
}

class ShopManager : public QWidget
{
    Q_OBJECT

public:
    explicit ShopManager(QWidget *parent = 0);
    ~ShopManager();

    void appendRowData(QStringList rowData); //添加一行数据

    void clearTableData(); //清除表格数据

    QStringList getCurrentRowData();    //

    QString getCurrentID();

private:
    Ui::ShopManager *ui;
};
#endif // SHOPMANAGER_H
