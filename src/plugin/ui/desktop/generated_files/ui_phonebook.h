/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneBookClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *searchButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *PhoneBookClass)
    {
        if (PhoneBookClass->objectName().isEmpty())
            PhoneBookClass->setObjectName(QStringLiteral("PhoneBookClass"));
        PhoneBookClass->resize(635, 412);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PhoneBookClass->sizePolicy().hasHeightForWidth());
        PhoneBookClass->setSizePolicy(sizePolicy);
        PhoneBookClass->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/PhoneBook/Contacts_Phone_Book-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        PhoneBookClass->setWindowIcon(icon);
        PhoneBookClass->setAutoFillBackground(false);
        layoutWidget = new QWidget(PhoneBookClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 611, 391));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout->addWidget(addButton);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        verticalLayout->addWidget(searchButton);

        updateButton = new QPushButton(layoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        verticalLayout->addWidget(deleteButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(PhoneBookClass);

        QMetaObject::connectSlotsByName(PhoneBookClass);
    } // setupUi

    void retranslateUi(QWidget *PhoneBookClass)
    {
        PhoneBookClass->setWindowTitle(QApplication::translate("PhoneBookClass", "PhoneBook", nullptr));
        addButton->setText(QApplication::translate("PhoneBookClass", "Add", nullptr));
        searchButton->setText(QApplication::translate("PhoneBookClass", "Search", nullptr));
        updateButton->setText(QApplication::translate("PhoneBookClass", "Update", nullptr));
        deleteButton->setText(QApplication::translate("PhoneBookClass", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhoneBookClass: public Ui_PhoneBookClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
