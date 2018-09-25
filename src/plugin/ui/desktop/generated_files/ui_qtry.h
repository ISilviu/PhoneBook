/********************************************************************************
** Form generated from reading UI file 'qtry.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRY_H
#define UI_QTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTryClass
{
public:

    void setupUi(QWidget *QTryClass)
    {
        if (QTryClass->objectName().isEmpty())
            QTryClass->setObjectName(QStringLiteral("QTryClass"));
        QTryClass->resize(600, 400);

        retranslateUi(QTryClass);

        QMetaObject::connectSlotsByName(QTryClass);
    } // setupUi

    void retranslateUi(QWidget *QTryClass)
    {
        QTryClass->setWindowTitle(QApplication::translate("QTryClass", "QTry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTryClass: public Ui_QTryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRY_H
