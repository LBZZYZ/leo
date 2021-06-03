/********************************************************************************
** Form generated from reading UI file 'FriendNoteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDNOTEDIALOG_H
#define UI_FRIENDNOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendNoteDialog
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *FriendNoteDialog)
    {
        if (FriendNoteDialog->objectName().isEmpty())
            FriendNoteDialog->setObjectName(QString::fromUtf8("FriendNoteDialog"));
        FriendNoteDialog->resize(397, 206);
        pushButton = new QPushButton(FriendNoteDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 160, 81, 31));
        textEdit = new QTextEdit(FriendNoteDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 50, 281, 101));
        label = new QLabel(FriendNoteDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 54, 12));
        pushButton_2 = new QPushButton(FriendNoteDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 20, 71, 61));
        lineEdit = new QLineEdit(FriendNoteDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 10, 113, 20));
        label_2 = new QLabel(FriendNoteDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 10, 54, 12));
        label_3 = new QLabel(FriendNoteDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 40, 54, 12));

        retranslateUi(FriendNoteDialog);

        QMetaObject::connectSlotsByName(FriendNoteDialog);
    } // setupUi

    void retranslateUi(QWidget *FriendNoteDialog)
    {
        FriendNoteDialog->setWindowTitle(QCoreApplication::translate("FriendNoteDialog", "FriendNoteDialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FriendNoteDialog", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("FriendNoteDialog", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FriendNoteDialog", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("FriendNoteDialog", "\345\244\207\346\263\250", nullptr));
        label_3->setText(QCoreApplication::translate("FriendNoteDialog", "\351\252\214\350\257\201\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendNoteDialog: public Ui_FriendNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDNOTEDIALOG_H
