/********************************************************************************
** Form generated from reading UI file 'allfieldsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLFIELDSDIALOG_H
#define UI_ALLFIELDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lastNameLabel;
    QLabel *firstNameLabel;
    QLabel *phoneNumberLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *lastNameEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *phoneNumberEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(372, 103);
        layoutWidget = new QWidget(AddDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 351, 81));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout_3->addWidget(cancelButton);


        gridLayout_2->addLayout(verticalLayout_3, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lastNameLabel = new QLabel(layoutWidget);
        lastNameLabel->setObjectName(QStringLiteral("lastNameLabel"));

        verticalLayout_2->addWidget(lastNameLabel);

        firstNameLabel = new QLabel(layoutWidget);
        firstNameLabel->setObjectName(QStringLiteral("firstNameLabel"));

        verticalLayout_2->addWidget(firstNameLabel);

        phoneNumberLabel = new QLabel(layoutWidget);
        phoneNumberLabel->setObjectName(QStringLiteral("phoneNumberLabel"));

        verticalLayout_2->addWidget(phoneNumberLabel);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lastNameEdit = new QLineEdit(layoutWidget);
        lastNameEdit->setObjectName(QStringLiteral("lastNameEdit"));

        verticalLayout->addWidget(lastNameEdit);

        firstNameEdit = new QLineEdit(layoutWidget);
        firstNameEdit->setObjectName(QStringLiteral("firstNameEdit"));

        verticalLayout->addWidget(firstNameEdit);

        phoneNumberEdit = new QLineEdit(layoutWidget);
        phoneNumberEdit->setObjectName(QStringLiteral("phoneNumberEdit"));

        verticalLayout->addWidget(phoneNumberEdit);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(AddDialog);

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "AddDialog", nullptr));
        okButton->setText(QApplication::translate("AddDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("AddDialog", "Cancel", nullptr));
        lastNameLabel->setText(QApplication::translate("AddDialog", "Last name:", nullptr));
        firstNameLabel->setText(QApplication::translate("AddDialog", "First name:", nullptr));
        phoneNumberLabel->setText(QApplication::translate("AddDialog", "Phone number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLFIELDSDIALOG_H
