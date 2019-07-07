/********************************************************************************
** Form generated from reading UI file 'ShopManager.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPMANAGER_H
#define UI_SHOPMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopManager
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ShopManager)
    {
        if (ShopManager->objectName().isEmpty())
            ShopManager->setObjectName(QStringLiteral("ShopManager"));
        ShopManager->resize(478, 374);
        gridLayout = new QGridLayout(ShopManager);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(ShopManager);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(ShopManager);

        QMetaObject::connectSlotsByName(ShopManager);
    } // setupUi

    void retranslateUi(QWidget *ShopManager)
    {
        ShopManager->setWindowTitle(QApplication::translate("ShopManager", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ShopManager: public Ui_ShopManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPMANAGER_H
