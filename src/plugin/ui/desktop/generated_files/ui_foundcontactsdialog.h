/********************************************************************************
** Form generated from reading UI file 'foundcontactsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOUNDCONTACTSDIALOG_H
#define UI_FOUNDCONTACTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FoundContactsDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTableView *foundContactsTableView;

    void setupUi(QDialog *FoundContactsDialog)
    {
        if (FoundContactsDialog->objectName().isEmpty())
            FoundContactsDialog->setObjectName(QStringLiteral("FoundContactsDialog"));
        FoundContactsDialog->resize(400, 300);
        layoutWidget = new QWidget(FoundContactsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        foundContactsTableView = new QTableView(layoutWidget);
        foundContactsTableView->setObjectName(QStringLiteral("foundContactsTableView"));
        foundContactsTableView->setAutoFillBackground(false);
        foundContactsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        foundContactsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        foundContactsTableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(foundContactsTableView, 1, 0, 1, 1);


        retranslateUi(FoundContactsDialog);

        QMetaObject::connectSlotsByName(FoundContactsDialog);
    } // setupUi

    void retranslateUi(QDialog *FoundContactsDialog)
    {
        FoundContactsDialog->setWindowTitle(QApplication::translate("FoundContactsDialog", "FoundContactsDialog", nullptr));
        label->setText(QApplication::translate("FoundContactsDialog", "<html><head/><body><p align=\"center\">Result(s):</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FoundContactsDialog: public Ui_FoundContactsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOUNDCONTACTSDIALOG_H
