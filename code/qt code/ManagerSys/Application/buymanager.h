#ifndef BUYMANAGER_H
#define BUYMANAGER_H

#include <QWidget>

namespace Ui {
class BuyManager;
}

class BuyManager : public QWidget
{
    Q_OBJECT

public:
    explicit BuyManager(QWidget *parent = 0);
    ~BuyManager();

    void appendRowData(QStringList rowData); //添加一行数据

    void clearTableData(); //清除表格数据

    QStringList getCurrentRowData();    //

    QString getCurrentID();

private:
    Ui::BuyManager *ui;
};

#endif // BUYMANAGER_H
