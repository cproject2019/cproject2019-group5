/********************************************************************************
** Form generated from reading UI file 'buymanager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYMANAGER_H
#define UI_BUYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyManager
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *BuyManager)
    {
        if (BuyManager->objectName().isEmpty())
            BuyManager->setObjectName(QStringLiteral("BuyManager"));
        BuyManager->resize(400, 300);
        gridLayout = new QGridLayout(BuyManager);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(BuyManager);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(BuyManager);

        QMetaObject::connectSlotsByName(BuyManager);
    } // setupUi

    void retranslateUi(QWidget *BuyManager)
    {
        BuyManager->setWindowTitle(QApplication::translate("BuyManager", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BuyManager: public Ui_BuyManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYMANAGER_H
