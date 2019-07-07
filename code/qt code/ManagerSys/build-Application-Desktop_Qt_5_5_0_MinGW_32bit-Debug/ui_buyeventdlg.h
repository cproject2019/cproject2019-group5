/********************************************************************************
** Form generated from reading UI file 'buyeventdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYEVENTDLG_H
#define UI_BUYEVENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BuyEventdlg
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *CardIDEdit;
    QLineEdit *CardTypeEdit;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *ShopIDEdit;
    QLineEdit *ShopTypeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *MoneyEdit;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *SwimEdit;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *BuyEventdlg)
    {
        if (BuyEventdlg->objectName().isEmpty())
            BuyEventdlg->setObjectName(QStringLiteral("BuyEventdlg"));
        BuyEventdlg->resize(400, 300);
        BuyEventdlg->setMinimumSize(QSize(400, 300));
        verticalLayout_8 = new QVBoxLayout(BuyEventdlg);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(BuyEventdlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        CardIDEdit = new QLineEdit(BuyEventdlg);
        CardIDEdit->setObjectName(QStringLiteral("CardIDEdit"));

        horizontalLayout_6->addWidget(CardIDEdit);

        CardTypeEdit = new QLineEdit(BuyEventdlg);
        CardTypeEdit->setObjectName(QStringLiteral("CardTypeEdit"));

        horizontalLayout_6->addWidget(CardTypeEdit);


        verticalLayout_8->addLayout(horizontalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(BuyEventdlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        ShopIDEdit = new QLineEdit(BuyEventdlg);
        ShopIDEdit->setObjectName(QStringLiteral("ShopIDEdit"));

        horizontalLayout_5->addWidget(ShopIDEdit);

        ShopTypeEdit = new QLineEdit(BuyEventdlg);
        ShopTypeEdit->setObjectName(QStringLiteral("ShopTypeEdit"));

        horizontalLayout_5->addWidget(ShopTypeEdit);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(BuyEventdlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        MoneyEdit = new QLineEdit(BuyEventdlg);
        MoneyEdit->setObjectName(QStringLiteral("MoneyEdit"));

        horizontalLayout_4->addWidget(MoneyEdit);


        verticalLayout_8->addLayout(horizontalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(BuyEventdlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        SwimEdit = new QLineEdit(BuyEventdlg);
        SwimEdit->setObjectName(QStringLiteral("SwimEdit"));

        horizontalLayout_2->addWidget(SwimEdit);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(BuyEventdlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout_8->addLayout(verticalLayout_7);

        SwimEdit->raise();

        retranslateUi(BuyEventdlg);

        QMetaObject::connectSlotsByName(BuyEventdlg);
    } // setupUi

    void retranslateUi(QDialog *BuyEventdlg)
    {
        BuyEventdlg->setWindowTitle(QApplication::translate("BuyEventdlg", "Dialog", 0));
        label->setText(QApplication::translate("BuyEventdlg", "\345\215\241\345\217\267:", 0));
        label_2->setText(QApplication::translate("BuyEventdlg", "\345\225\206\345\272\227\347\274\226\345\217\267:", 0));
        label_4->setText(QApplication::translate("BuyEventdlg", "\346\224\257\344\273\230\351\207\221\351\242\235", 0));
        label_5->setText(QApplication::translate("BuyEventdlg", "\346\264\227\346\276\241\346\227\266\351\227\264:", 0));
    } // retranslateUi

};

namespace Ui {
    class BuyEventdlg: public Ui_BuyEventdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYEVENTDLG_H
