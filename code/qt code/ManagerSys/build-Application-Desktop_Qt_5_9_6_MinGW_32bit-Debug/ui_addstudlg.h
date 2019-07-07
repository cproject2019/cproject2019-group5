/********************************************************************************
** Form generated from reading UI file 'addstudlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDLG_H
#define UI_ADDSTUDLG_H

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

class Ui_AddStuDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IDEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *WorkEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *MoneyEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *SwimcardEdit;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AddStuDlg)
    {
        if (AddStuDlg->objectName().isEmpty())
            AddStuDlg->setObjectName(QStringLiteral("AddStuDlg"));
        AddStuDlg->resize(373, 335);
        verticalLayout_2 = new QVBoxLayout(AddStuDlg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddStuDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        IDEdit = new QLineEdit(AddStuDlg);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));

        horizontalLayout->addWidget(IDEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddStuDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_2->addWidget(label_2);

        WorkEdit = new QLineEdit(AddStuDlg);
        WorkEdit->setObjectName(QStringLiteral("WorkEdit"));

        horizontalLayout_2->addWidget(WorkEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(AddStuDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(70, 0));
        label_5->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_5->addWidget(label_5);

        MoneyEdit = new QLineEdit(AddStuDlg);
        MoneyEdit->setObjectName(QStringLiteral("MoneyEdit"));

        horizontalLayout_5->addWidget(MoneyEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(AddStuDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(70, 0));
        label_6->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_6->addWidget(label_6);

        SwimcardEdit = new QLineEdit(AddStuDlg);
        SwimcardEdit->setObjectName(QStringLiteral("SwimcardEdit"));

        horizontalLayout_6->addWidget(SwimcardEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(AddStuDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_8->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(AddStuDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddStuDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddStuDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddStuDlg);
    } // setupUi

    void retranslateUi(QDialog *AddStuDlg)
    {
        AddStuDlg->setWindowTitle(QApplication::translate("AddStuDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddStuDlg", "ID:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddStuDlg", "Jobs:", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddStuDlg", "balance:", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddStuDlg", "tickets", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddStuDlg: public Ui_AddStuDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDLG_H
