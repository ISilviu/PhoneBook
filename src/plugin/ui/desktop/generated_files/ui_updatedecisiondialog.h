/********************************************************************************
** Form generated from reading UI file 'updatedecisiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEDECISIONDIALOG_H
#define UI_UPDATEDECISIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateDecisionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *lastNameCheckBox;
    QCheckBox *firstNameCheckBox;
    QCheckBox *phoneNumberCheckBox;
    QLabel *label;

    void setupUi(QDialog *UpdateDecisionDialog)
    {
        if (UpdateDecisionDialog->objectName().isEmpty())
            UpdateDecisionDialog->setObjectName(QStringLiteral("UpdateDecisionDialog"));
        UpdateDecisionDialog->resize(263, 140);
        buttonBox = new QDialogButtonBox(UpdateDecisionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 110, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(UpdateDecisionDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 95, 65));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lastNameCheckBox = new QCheckBox(layoutWidget);
        lastNameCheckBox->setObjectName(QStringLiteral("lastNameCheckBox"));

        verticalLayout->addWidget(lastNameCheckBox);

        firstNameCheckBox = new QCheckBox(layoutWidget);
        firstNameCheckBox->setObjectName(QStringLiteral("firstNameCheckBox"));

        verticalLayout->addWidget(firstNameCheckBox);

        phoneNumberCheckBox = new QCheckBox(layoutWidget);
        phoneNumberCheckBox->setObjectName(QStringLiteral("phoneNumberCheckBox"));

        verticalLayout->addWidget(phoneNumberCheckBox);

        label = new QLabel(UpdateDecisionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 188, 41));

        retranslateUi(UpdateDecisionDialog);

        QMetaObject::connectSlotsByName(UpdateDecisionDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateDecisionDialog)
    {
        UpdateDecisionDialog->setWindowTitle(QApplication::translate("UpdateDecisionDialog", "UpdateDecisionDialog", nullptr));
        lastNameCheckBox->setText(QApplication::translate("UpdateDecisionDialog", "Last name", nullptr));
        firstNameCheckBox->setText(QApplication::translate("UpdateDecisionDialog", "First name", nullptr));
        phoneNumberCheckBox->setText(QApplication::translate("UpdateDecisionDialog", "Phone Number", nullptr));
        label->setText(QApplication::translate("UpdateDecisionDialog", "What field(s) would you like to change?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateDecisionDialog: public Ui_UpdateDecisionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEDECISIONDIALOG_H
