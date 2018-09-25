/********************************************************************************
** Form generated from reading UI file 'idrequestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDREQUESTDIALOG_H
#define UI_IDREQUESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IdRequestDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idLineEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_2;

    void setupUi(QWidget *IdRequestDialog)
    {
        if (IdRequestDialog->objectName().isEmpty())
            IdRequestDialog->setObjectName(QStringLiteral("IdRequestDialog"));
        IdRequestDialog->resize(338, 136);
        layoutWidget = new QWidget(IdRequestDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 321, 121));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        idLineEdit = new QLineEdit(layoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));

        horizontalLayout->addWidget(idLineEdit);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(IdRequestDialog);

        QMetaObject::connectSlotsByName(IdRequestDialog);
    } // setupUi

    void retranslateUi(QWidget *IdRequestDialog)
    {
        IdRequestDialog->setWindowTitle(QApplication::translate("IdRequestDialog", "Enter the requested Id", nullptr));
        label->setText(QApplication::translate("IdRequestDialog", "Id:", nullptr));
        idLineEdit->setPlaceholderText(QApplication::translate("IdRequestDialog", "e.g. 2451", nullptr));
        okButton->setText(QApplication::translate("IdRequestDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("IdRequestDialog", "Cancel", nullptr));
        label_2->setText(QApplication::translate("IdRequestDialog", "<html><head/><body><p>Please note that the id of every person is unique. </p><p>If you don't remember it, try using the Search button.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IdRequestDialog: public Ui_IdRequestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDREQUESTDIALOG_H
