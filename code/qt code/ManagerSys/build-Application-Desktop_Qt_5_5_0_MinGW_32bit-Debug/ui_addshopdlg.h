/********************************************************************************
** Form generated from reading UI file 'addshopdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSHOPDLG_H
#define UI_ADDSHOPDLG_H

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

class Ui_addshopdlg
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *IDEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *WorkEdit;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *MoneyEdit;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *BuyEdit;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *addshopdlg)
    {
        if (addshopdlg->objectName().isEmpty())
            addshopdlg->setObjectName(QStringLiteral("addshopdlg"));
        addshopdlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(addshopdlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(addshopdlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        IDEdit = new QLineEdit(addshopdlg);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));

        horizontalLayout_3->addWidget(IDEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(addshopdlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        WorkEdit = new QLineEdit(addshopdlg);
        WorkEdit->setObjectName(QStringLiteral("WorkEdit"));

        horizontalLayout_4->addWidget(WorkEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(addshopdlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        MoneyEdit = new QLineEdit(addshopdlg);
        MoneyEdit->setObjectName(QStringLiteral("MoneyEdit"));

        horizontalLayout_5->addWidget(MoneyEdit);


        verticalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(addshopdlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        BuyEdit = new QLineEdit(addshopdlg);
        BuyEdit->setObjectName(QStringLiteral("BuyEdit"));

        horizontalLayout_6->addWidget(BuyEdit);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(addshopdlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_5);


        verticalLayout->addLayout(verticalLayout_4);


        retranslateUi(addshopdlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), addshopdlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addshopdlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(addshopdlg);
    } // setupUi

    void retranslateUi(QDialog *addshopdlg)
    {
        addshopdlg->setWindowTitle(QApplication::translate("addshopdlg", "Dialog", 0));
        label->setText(QApplication::translate("addshopdlg", "ID:", 0));
        label_2->setText(QApplication::translate("addshopdlg", "\345\225\206\345\256\266\347\261\273\345\236\213:", 0));
        label_3->setText(QApplication::translate("addshopdlg", "\350\220\245\344\270\232\351\242\235:", 0));
        label_4->setText(QApplication::translate("addshopdlg", "\344\272\244\346\230\223\345\215\225\346\225\260:", 0));
    } // retranslateUi

};

namespace Ui {
    class addshopdlg: public Ui_addshopdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSHOPDLG_H
