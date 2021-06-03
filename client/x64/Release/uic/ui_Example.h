/********************************************************************************
** Form generated from reading UI file 'Example.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLE_H
#define UI_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Example
{
public:

    void setupUi(QWidget *Example)
    {
        if (Example->objectName().isEmpty())
            Example->setObjectName(QString::fromUtf8("Example"));
        Example->resize(400, 300);

        retranslateUi(Example);

        QMetaObject::connectSlotsByName(Example);
    } // setupUi

    void retranslateUi(QWidget *Example)
    {
        Example->setWindowTitle(QCoreApplication::translate("Example", "Example", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Example: public Ui_Example {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLE_H
