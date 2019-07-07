#ifndef BUYEVENTDLG_H
#define BUYEVENTDLG_H

#include <QDialog>
#include <QVariantMap>
namespace Ui {
class BuyEventdlg;
}

class BuyEventdlg : public QDialog
{
    Q_OBJECT

public:
    explicit BuyEventdlg(QWidget *parent = 0);
    ~BuyEventdlg();

    void setEditData(QStringList rowData);

private:
    void clearData();

    void closeEvent(QCloseEvent *event);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void signalStuInfo(QVariantMap stuInfo);

private:
    Ui::BuyEventdlg *ui;
};

#endif // BUYEVENTDLG_H
