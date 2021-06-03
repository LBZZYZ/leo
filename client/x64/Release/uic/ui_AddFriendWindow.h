/********************************************************************************
** Form generated from reading UI file 'AddFriendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWINDOW_H
#define UI_ADDFRIENDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *SearchInfoEditor;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *SearchFriendsButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QComboBox *SexComboBox;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *AgeComboBox;
    QSpacerItem *horizontalSpacer_6;
    QListWidget *listWidget;

    void setupUi(QWidget *AddFriendWindow)
    {
        if (AddFriendWindow->objectName().isEmpty())
            AddFriendWindow->setObjectName(QString::fromUtf8("AddFriendWindow"));
        AddFriendWindow->resize(771, 548);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/window-icon/WindowIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddFriendWindow->setWindowIcon(icon);
        AddFriendWindow->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QComboBox\n"
"{\n"
"	border: 1px solid #BDBDBD; \n"
"	border-radius: 2px;\n"
"	padding: 2px;\n"
"	background: #FFFFFF; \n"
"	\n"
"	font-family: '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"	font-size: 16px;\n"
"	color: #212121;	/*\346\226\207\346\234\254\351\242\234\350\211\262\357\274\214ComboBox\344\270\212\346\230\276\347\244\272\347\232\204\357\274\214\344\270\215\346\230\257item\351\207\214\347\232\204*/\n"
"	\n"
"	\n"
"	width: 56px;\n"
"	height: 24px;\n"
"}\n"
"\n"
"QComboBox::hover\n"
"{\n"
"	border: 1px solid #512DA8;	\n"
"}\n"
"\n"
"\n"
"QComboBox::on\n"
"{\n"
"	border: 1px solid #673AB7;\n"
"}\n"
"\n"
"QComboBox::drop-down \n"
"{\n"
"	border: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow \n"
"{\n"
"	border: none;\n"
"	image: url(:/down-arrow/212121/arrow-down-filling.png);\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow::hover\n"
"{\n"
"	border: none;\n"
"	image: url(:/down-arrow-hover/512DA8/arrow-down-filling (1).png)\n"
"}\n"
"\n"
""
                        "QComboBox::down-arrow::on\n"
"{\n"
"	border: none;\n"
"	\n"
"	image: url(:/down-arrow-on/673AB7/arrow-up-filling.png);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	color: #212121;\n"
"	\n"
"	background-color: #FFFFFF;\n"
"	outline: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"	height: 24px;\n"
"}\n"
"QComboBox QAbstractItemView::item:hover\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #673AB7;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView::item:selected\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #673AB7;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color: #673AB7;\n"
"	color: #FFFFFF;\n"
"\n"
"	height: 36px;\n"
"	width: 88px;\n"
"\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: #512DA8;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(AddFriendWindow);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(16);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        SearchInfoEditor = new QLineEdit(AddFriendWindow);
        SearchInfoEditor->setObjectName(QString::fromUtf8("SearchInfoEditor"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchInfoEditor->sizePolicy().hasHeightForWidth());
        SearchInfoEditor->setSizePolicy(sizePolicy);
        SearchInfoEditor->setMinimumSize(QSize(0, 0));
        SearchInfoEditor->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        SearchInfoEditor->setFont(font);
        SearchInfoEditor->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"\n"
"	padding-left: 8px;\n"
"\n"
"	border: 1px solid #BDBDBD;\n"
"	border-radius:2px;\n"
"\n"
"	height: 36px;\n"
"\n"
"	color: #212121;\n"
"\n"
"}\n"
"\n"
"QLineEdit::hover\n"
"{\n"
"	border: 1px solid #673AB7;\n"
"}\n"
""));
        SearchInfoEditor->setMaxLength(12);
        SearchInfoEditor->setFrame(true);

        horizontalLayout_2->addWidget(SearchInfoEditor);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        SearchFriendsButton = new QPushButton(AddFriendWindow);
        SearchFriendsButton->setObjectName(QString::fromUtf8("SearchFriendsButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SearchFriendsButton->sizePolicy().hasHeightForWidth());
        SearchFriendsButton->setSizePolicy(sizePolicy1);
        SearchFriendsButton->setMaximumSize(QSize(16777215, 16777215));
        SearchFriendsButton->setFont(font);
        SearchFriendsButton->setCursor(QCursor(Qt::ArrowCursor));
        SearchFriendsButton->setStyleSheet(QString::fromUtf8(""));
        SearchFriendsButton->setAutoRepeatDelay(300);
        SearchFriendsButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(SearchFriendsButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 13);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SexComboBox = new QComboBox(AddFriendWindow);
        SexComboBox->addItem(QString());
        SexComboBox->addItem(QString());
        SexComboBox->addItem(QString());
        SexComboBox->setObjectName(QString::fromUtf8("SexComboBox"));
        sizePolicy.setHeightForWidth(SexComboBox->sizePolicy().hasHeightForWidth());
        SexComboBox->setSizePolicy(sizePolicy);
        SexComboBox->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        SexComboBox->setFont(font1);
        SexComboBox->setAutoFillBackground(false);
        SexComboBox->setStyleSheet(QString::fromUtf8(""));
        SexComboBox->setEditable(false);
        SexComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

        horizontalLayout->addWidget(SexComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        AgeComboBox = new QComboBox(AddFriendWindow);
        AgeComboBox->addItem(QString());
        AgeComboBox->addItem(QString());
        AgeComboBox->addItem(QString());
        AgeComboBox->addItem(QString());
        AgeComboBox->addItem(QString());
        AgeComboBox->setObjectName(QString::fromUtf8("AgeComboBox"));
        sizePolicy.setHeightForWidth(AgeComboBox->sizePolicy().hasHeightForWidth());
        AgeComboBox->setSizePolicy(sizePolicy);
        AgeComboBox->setMaximumSize(QSize(16777215, 16777215));
        AgeComboBox->setStyleSheet(QString::fromUtf8(""));
        AgeComboBox->setEditable(false);

        horizontalLayout->addWidget(AgeComboBox);

        horizontalSpacer_6 = new QSpacerItem(13, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 14);

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(AddFriendWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(true);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border: 1px solid #BDBDBD;\n"
"}\n"
"\n"
"QListWidget::item\n"
"{\n"
"	height: 40px;\n"
"}"));
        listWidget->setFrameShape(QFrame::StyledPanel);
        listWidget->setAutoScrollMargin(0);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setLayoutMode(QListView::Batched);
        listWidget->setBatchSize(10);

        verticalLayout_2->addWidget(listWidget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 7);

        verticalLayout_3->addLayout(verticalLayout_2);

        QWidget::setTabOrder(SexComboBox, SearchInfoEditor);
        QWidget::setTabOrder(SearchInfoEditor, AgeComboBox);
        QWidget::setTabOrder(AgeComboBox, listWidget);
        QWidget::setTabOrder(listWidget, SearchFriendsButton);

        retranslateUi(AddFriendWindow);

        QMetaObject::connectSlotsByName(AddFriendWindow);
    } // setupUi

    void retranslateUi(QWidget *AddFriendWindow)
    {
        AddFriendWindow->setWindowTitle(QCoreApplication::translate("AddFriendWindow", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
#if QT_CONFIG(whatsthis)
        AddFriendWindow->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        SearchInfoEditor->setText(QString());
        SearchInfoEditor->setPlaceholderText(QCoreApplication::translate("AddFriendWindow", "\350\264\246\345\217\267/\346\230\265\347\247\260/\346\211\213\346\234\272\345\217\267", nullptr));
        SearchFriendsButton->setText(QCoreApplication::translate("AddFriendWindow", "\346\237\245\346\211\276\345\245\275\345\217\213", nullptr));
        SexComboBox->setItemText(0, QCoreApplication::translate("AddFriendWindow", "\346\200\247\345\210\253", nullptr));
        SexComboBox->setItemText(1, QCoreApplication::translate("AddFriendWindow", "\347\224\267", nullptr));
        SexComboBox->setItemText(2, QCoreApplication::translate("AddFriendWindow", "\345\245\263", nullptr));

        SexComboBox->setCurrentText(QCoreApplication::translate("AddFriendWindow", "\346\200\247\345\210\253", nullptr));
        SexComboBox->setPlaceholderText(QString());
        AgeComboBox->setItemText(0, QCoreApplication::translate("AddFriendWindow", "\345\271\264\351\276\204", nullptr));
        AgeComboBox->setItemText(1, QCoreApplication::translate("AddFriendWindow", "18\344\273\245\344\270\213", nullptr));
        AgeComboBox->setItemText(2, QCoreApplication::translate("AddFriendWindow", "18-22", nullptr));
        AgeComboBox->setItemText(3, QCoreApplication::translate("AddFriendWindow", "22-30", nullptr));
        AgeComboBox->setItemText(4, QCoreApplication::translate("AddFriendWindow", "30\344\273\245\344\270\212", nullptr));

        AgeComboBox->setCurrentText(QCoreApplication::translate("AddFriendWindow", "\345\271\264\351\276\204", nullptr));
        AgeComboBox->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddFriendWindow: public Ui_AddFriendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWINDOW_H
