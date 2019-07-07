/********************************************************************************
** Form generated from reading UI file 'buydlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYDLG_H
#define UI_BUYDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_buydlg
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *buydlg)
    {
        if (buydlg->objectName().isEmpty())
            buydlg->setObjectName(QStringLiteral("buydlg"));
        buydlg->resize(400, 300);
        buttonBox = new QDialogButtonBox(buydlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(buydlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), buydlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), buydlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(buydlg);
    } // setupUi

    void retranslateUi(QDialog *buydlg)
    {
        buydlg->setWindowTitle(QApplication::translate("buydlg", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class buydlg: public Ui_buydlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYDLG_H
