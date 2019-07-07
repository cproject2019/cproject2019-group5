#ifndef ADDSHOPDLG_H
#define ADDSHOPDLG_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class addshopdlg;
}

class addshopdlg : public QDialog
{
    Q_OBJECT

public:
    explicit addshopdlg(QWidget *parent = 0);
    ~addshopdlg();

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
    Ui::addshopdlg *ui;
};

#endif // ADDSHOPDLG_H
