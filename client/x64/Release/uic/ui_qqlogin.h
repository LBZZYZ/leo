/********************************************************************************
** Form generated from reading UI file 'qqlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQLOGIN_H
#define UI_QQLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQLoginClass
{
public:
    QFrame *frame;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QComboBox *m_userNameCom;
    QLineEdit *m_passwordlineedit;
    QCheckBox *m_rememberpw;
    QLabel *m_searchpw;
    QLabel *m_registaccount;
    QPushButton *m_pLoginButton;
    QLabel *qLabel_HeadIcon;
    QWidget *page_3;
    QPushButton *m_pRegister;
    QPushButton *m_pRegisterCancel;
    QPushButton *m_closebutton;
    QLabel *label_13;
    QLineEdit *qLineEdit_UserName;
    QLabel *label_17;
    QLineEdit *qLineEdit_PassWord;
    QLabel *label_19;
    QLineEdit *qLineEdit_PhoneNumber;
    QLabel *qLabel_UserName;
    QLabel *qLabel_PassWord;
    QLabel *qLabel_PhoneNumber;
    QLabel *label_2;
    QPushButton *m_minbutton;
    QPushButton *pushButton;

    void setupUi(QWidget *QQLoginClass)
    {
        if (QQLoginClass->objectName().isEmpty())
            QQLoginClass->setObjectName(QString::fromUtf8("QQLoginClass"));
        QQLoginClass->resize(280, 330);
        QPalette palette;
        QBrush brush(QColor(255, 193, 7, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QQLoginClass->setPalette(palette);
        QQLoginClass->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(QQLoginClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(-20, 0, 301, 331));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame->setPalette(palette1);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 301, 331));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(117, 117, 117, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(103, 58, 183, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        stackedWidget->setPalette(palette2);
        QFont font;
        font.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font.setPointSize(8);
        stackedWidget->setFont(font);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        page->setPalette(palette3);
        page->setStyleSheet(QString::fromUtf8(""));
        m_userNameCom = new QComboBox(page);
        m_userNameCom->addItem(QString());
        m_userNameCom->setObjectName(QString::fromUtf8("m_userNameCom"));
        m_userNameCom->setGeometry(QRect(50, 150, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        m_userNameCom->setFont(font1);
        m_userNameCom->setCursor(QCursor(Qt::SizeVerCursor));
        m_userNameCom->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: none;  \n"
"    border-bottom:1px solid;\n"
"    border-bottom-color:rgb(188, 188, 188);\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QComboBox:hover{\n"
"       \n"
"	border-bottom-color: rgb(103, 58, 183);\n"
"}\n"
"QComboBox::QAbstractItemView::item\n"
"{\n"
"    height:40px;\n"
"}\n"
"\n"
"QComboBox::drop-down {	\n"
"   background:transparent;\n"
"    subcontrol-position: top right; \n"
"    width: 30px;\n"
"    height:40px;   \n"
"}\n"
"QComboBox::drop-down {	\n"
" border-image:url(Resources/down-arrow.png)\n"
"   \n"
"}\n"
"QComboBox::drop-down:hover {	\n"
" border-image:url(Resources/down-arrow-hover.png)\n"
"   \n"
"}\n"
"QComboBox::drop-down:focus{	\n"
" border-image:url(Resources/down-arrow-pressed.png)\n"
"   \n"
"}\n"
"QComboBox::down-arrow:on\n"
"{\n"
"  border-image:url(Resources/down-arrow-pressed.png)\357\274\233\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_userNameCom->setEditable(false);
        m_userNameCom->setMaxCount(10);
        m_userNameCom->setIconSize(QSize(20, 20));
        m_passwordlineedit = new QLineEdit(page);
        m_passwordlineedit->setObjectName(QString::fromUtf8("m_passwordlineedit"));
        m_passwordlineedit->setGeometry(QRect(50, 200, 221, 31));
        QPalette palette4;
        m_passwordlineedit->setPalette(palette4);
        m_passwordlineedit->setFont(font1);
        m_passwordlineedit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    border: none;  \n"
"    border-bottom:1px solid;   \n"
"	border-bottom-color: rgb(189, 189, 189);\n"
"}\n"
"QLineEdit:hover {\n"
"	\n"
"	border-bottom-color: rgb(103, 58, 183);\n"
"}\n"
"\n"
""));
        m_passwordlineedit->setMaxLength(22);
        m_passwordlineedit->setEchoMode(QLineEdit::Password);
        m_rememberpw = new QCheckBox(page);
        m_rememberpw->setObjectName(QString::fromUtf8("m_rememberpw"));
        m_rememberpw->setGeometry(QRect(60, 300, 91, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(9);
        m_rememberpw->setFont(font2);
        m_rememberpw->setAutoFillBackground(false);
        m_rememberpw->setStyleSheet(QString::fromUtf8("QCheckBox{  \n"
"	  \n"
"    color:rgb(188, 188, 188)    \n"
"}\n"
"QCheckBox::indicator {\n"
"    border: 1px solid rgb(188, 188, 188);\n"
"	border-radius:2px;\n"
"}\n"
"QCheckBox::indicator:hover {\n"
"    \n"
"    border: 1px solid rgb(91, 91, 91) ;\n"
"}\n"
"QCheckBox::indicator:checked {background-color:black}\n"
"QCheckBox:hover {\n"
"        color:rgb(91, 91, 91);\n"
"}"));
        m_rememberpw->setCheckable(true);
        m_rememberpw->setChecked(false);
        m_rememberpw->setTristate(false);
        m_searchpw = new QLabel(page);
        m_searchpw->setObjectName(QString::fromUtf8("m_searchpw"));
        m_searchpw->setGeometry(QRect(210, 300, 51, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        m_searchpw->setFont(font3);
        m_searchpw->setStyleSheet(QString::fromUtf8("QWidget{\n"
"font: 9pt \"Adobe \351\273\221\344\275\223 Std R\";\n"
"color:rgb(188, 188, 188)\n"
"}\n"
"QWidget:hover{\n"
"color: rgb(91, 91, 91)\n"
"}\n"
"\n"
"\n"
"\n"
""));
        m_searchpw->setFrameShape(QFrame::NoFrame);
        m_searchpw->setFrameShadow(QFrame::Plain);
        m_searchpw->setLineWidth(1);
        m_searchpw->setTextFormat(Qt::AutoText);
        m_searchpw->setScaledContents(false);
        m_registaccount = new QLabel(page);
        m_registaccount->setObjectName(QString::fromUtf8("m_registaccount"));
        m_registaccount->setGeometry(QRect(25, 0, 21, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        m_registaccount->setFont(font4);
        m_registaccount->setStyleSheet(QString::fromUtf8("QWidget{\n"
"font: 20pt \"\351\273\221\344\275\223\";\n"
"color:rgb(188, 188, 188)\n"
"}\n"
"\n"
"\n"
""));
        m_pLoginButton = new QPushButton(page);
        m_pLoginButton->setObjectName(QString::fromUtf8("m_pLoginButton"));
        m_pLoginButton->setGeometry(QRect(50, 260, 221, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        m_pLoginButton->setPalette(palette5);
        m_pLoginButton->setFont(font1);
        m_pLoginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border : none;\n"
"	border-radius:2px;\n"
"	background-color: rgb(103, 58, 183);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 193, 7);\n"
"}"));
        m_pLoginButton->setText(QString::fromUtf8("\347\231\273     \345\275\225"));
        m_pLoginButton->setFlat(false);
        qLabel_HeadIcon = new QLabel(page);
        qLabel_HeadIcon->setObjectName(QString::fromUtf8("qLabel_HeadIcon"));
        qLabel_HeadIcon->setGeometry(QRect(130, 60, 48, 48));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        qLabel_HeadIcon->setPalette(palette6);
        qLabel_HeadIcon->setStyleSheet(QString::fromUtf8("min-width:     48px;     \n"
"background-image: url(:/new/prefix1/Resources/QQImage.png);\n"
"min-height:    48px;     \n"
"max-width:     48px;     \n"
"max-height:   48px;    \n"
"border-radius: 24px;         \n"
"\n"
""));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush5(QColor(209, 196, 233, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(209, 196, 233, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush7(QColor(209, 196, 233, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush8(QColor(209, 196, 233, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        page_3->setPalette(palette7);
        page_3->setStyleSheet(QString::fromUtf8("\n"
"background-color:#FFFFFF;"));
        m_pRegister = new QPushButton(page_3);
        m_pRegister->setObjectName(QString::fromUtf8("m_pRegister"));
        m_pRegister->setEnabled(true);
        m_pRegister->setGeometry(QRect(200, 270, 61, 25));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush9(QColor(117, 117, 117, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        m_pRegister->setPalette(palette8);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(11);
        m_pRegister->setFont(font5);
        m_pRegister->setContextMenuPolicy(Qt::ActionsContextMenu);
        m_pRegister->setStyleSheet(QString::fromUtf8("#m_pRegister\n"
"{\n"
"	border-radius : 2px;\n"
"	background-color:#673ab7;\n"
"}\n"
"#m_pRegister:hover{\n"
"   background-color:#FFC107;\n"
"}\n"
""));
        m_pRegister->setFlat(false);
        m_pRegisterCancel = new QPushButton(page_3);
        m_pRegisterCancel->setObjectName(QString::fromUtf8("m_pRegisterCancel"));
        m_pRegisterCancel->setGeometry(QRect(60, 270, 61, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        m_pRegisterCancel->setPalette(palette9);
        m_pRegisterCancel->setFont(font5);
        m_pRegisterCancel->setStyleSheet(QString::fromUtf8("#m_pRegisterCancel{\n"
"	border-radius : 2px;\n"
"	\n"
"}"));
        m_closebutton = new QPushButton(page_3);
        m_closebutton->setObjectName(QString::fromUtf8("m_closebutton"));
        m_closebutton->setGeometry(QRect(470, 0, 32, 31));
        m_closebutton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(0,0,0,0)}\n"
"QPushButton:hover{border:none;background-color:rgb(200, 83, 48);}"));
        m_closebutton->setIconSize(QSize(32, 32));
        m_closebutton->setFlat(false);
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(50, 190, 41, 20));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_13->setPalette(palette10);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(8);
        font6.setBold(false);
        font6.setWeight(50);
        label_13->setFont(font6);
        qLineEdit_UserName = new QLineEdit(page_3);
        qLineEdit_UserName->setObjectName(QString::fromUtf8("qLineEdit_UserName"));
        qLineEdit_UserName->setGeometry(QRect(50, 70, 221, 31));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qLineEdit_UserName->sizePolicy().hasHeightForWidth());
        qLineEdit_UserName->setSizePolicy(sizePolicy);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush12(QColor(33, 33, 33, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        qLineEdit_UserName->setPalette(palette11);
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font7.setPointSize(12);
        qLineEdit_UserName->setFont(font7);
        qLineEdit_UserName->setStyleSheet(QString::fromUtf8("\n"
"#qLineEdit_UserName\n"
"{\n"
"	border-radius : 2px;\n"
"	border : 2px groove gray;\n"
"}\n"
"#qLineEdit_UserName:hover\n"
"{\n"
"	border-color: rgb(103, 58, 183);\n"
"	\n"
"}\n"
""));
        qLineEdit_UserName->setMaxLength(10);
        qLineEdit_UserName->setEchoMode(QLineEdit::Normal);
        qLineEdit_UserName->setClearButtonEnabled(true);
        label_17 = new QLabel(page_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(50, 50, 41, 21));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_17->setPalette(palette12);
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(8);
        label_17->setFont(font8);
        qLineEdit_PassWord = new QLineEdit(page_3);
        qLineEdit_PassWord->setObjectName(QString::fromUtf8("qLineEdit_PassWord"));
        qLineEdit_PassWord->setGeometry(QRect(50, 140, 221, 31));
        sizePolicy.setHeightForWidth(qLineEdit_PassWord->sizePolicy().hasHeightForWidth());
        qLineEdit_PassWord->setSizePolicy(sizePolicy);
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        qLineEdit_PassWord->setPalette(palette13);
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font9.setPointSize(12);
        font9.setBold(false);
        font9.setWeight(50);
        qLineEdit_PassWord->setFont(font9);
        qLineEdit_PassWord->setStyleSheet(QString::fromUtf8("#qLineEdit_PassWord\n"
"{\n"
"	border-radius : 2px;\n"
"	border : 2px groove gray;\n"
"}\n"
"#qLineEdit_PassWord:hover\n"
"{\n"
"	\n"
"	\n"
"	border-color: rgb(103, 58, 183);\n"
"}\n"
"\n"
""));
        qLineEdit_PassWord->setMaxLength(23);
        qLineEdit_PassWord->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        qLineEdit_PassWord->setClearButtonEnabled(true);
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 120, 31, 21));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_19->setPalette(palette14);
        label_19->setFont(font8);
        label_19->setStyleSheet(QString::fromUtf8(""));
        qLineEdit_PhoneNumber = new QLineEdit(page_3);
        qLineEdit_PhoneNumber->setObjectName(QString::fromUtf8("qLineEdit_PhoneNumber"));
        qLineEdit_PhoneNumber->setGeometry(QRect(50, 210, 221, 31));
        sizePolicy.setHeightForWidth(qLineEdit_PhoneNumber->sizePolicy().hasHeightForWidth());
        qLineEdit_PhoneNumber->setSizePolicy(sizePolicy);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        qLineEdit_PhoneNumber->setPalette(palette15);
        qLineEdit_PhoneNumber->setFont(font7);
        qLineEdit_PhoneNumber->setContextMenuPolicy(Qt::DefaultContextMenu);
        qLineEdit_PhoneNumber->setStyleSheet(QString::fromUtf8("#qLineEdit_PhoneNumber\n"
"{\n"
"	border-radius : 2px;\n"
"	border : 2px groove gray;\n"
"}\n"
"#qLineEdit_PhoneNumber:hover\n"
"{\n"
"	border-color: rgb(103, 58, 183);\n"
"	\n"
"}\n"
""));
        qLineEdit_PhoneNumber->setInputMethodHints(Qt::ImhNone);
        qLineEdit_PhoneNumber->setMaxLength(32767);
        qLineEdit_PhoneNumber->setEchoMode(QLineEdit::Normal);
        qLineEdit_PhoneNumber->setClearButtonEnabled(true);
        qLabel_UserName = new QLabel(page_3);
        qLabel_UserName->setObjectName(QString::fromUtf8("qLabel_UserName"));
        qLabel_UserName->setGeometry(QRect(50, 100, 221, 16));
        QPalette palette16;
        QBrush brush13(QColor(244, 67, 54, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        qLabel_UserName->setPalette(palette16);
        qLabel_UserName->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\" red;"));
        qLabel_PassWord = new QLabel(page_3);
        qLabel_PassWord->setObjectName(QString::fromUtf8("qLabel_PassWord"));
        qLabel_PassWord->setGeometry(QRect(50, 170, 221, 16));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        qLabel_PassWord->setPalette(palette17);
        qLabel_PassWord->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\" red;"));
        qLabel_PhoneNumber = new QLabel(page_3);
        qLabel_PhoneNumber->setObjectName(QString::fromUtf8("qLabel_PhoneNumber"));
        qLabel_PhoneNumber->setGeometry(QRect(50, 240, 221, 16));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        qLabel_PhoneNumber->setPalette(palette18);
        qLabel_PhoneNumber->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\" red;"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 91, 31));
        QFont font10;
        font10.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font10.setPointSize(16);
        font10.setBold(false);
        font10.setWeight(50);
        label_2->setFont(font10);
        stackedWidget->addWidget(page_3);
        qLabel_PhoneNumber->raise();
        qLabel_PassWord->raise();
        qLabel_UserName->raise();
        m_pRegister->raise();
        m_pRegisterCancel->raise();
        m_closebutton->raise();
        label_13->raise();
        label_17->raise();
        label_19->raise();
        qLineEdit_PhoneNumber->raise();
        qLineEdit_UserName->raise();
        qLineEdit_PassWord->raise();
        label_2->raise();
        m_minbutton = new QPushButton(frame);
        m_minbutton->setObjectName(QString::fromUtf8("m_minbutton"));
        m_minbutton->setEnabled(true);
        m_minbutton->setGeometry(QRect(210, 0, 32, 32));
        m_minbutton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(0, 0, 0,0)}\n"
""));
        m_minbutton->setIconSize(QSize(32, 32));
        m_minbutton->setCheckable(false);
        m_minbutton->setChecked(false);
        m_minbutton->setFlat(false);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(240, 0, 32, 32));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(0, 0, 0,0)}\n"
""));
        pushButton->setIconSize(QSize(32, 32));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setFlat(false);
        m_minbutton->raise();
        pushButton->raise();
        stackedWidget->raise();
        QWidget::setTabOrder(m_minbutton, pushButton);
        QWidget::setTabOrder(pushButton, m_userNameCom);
        QWidget::setTabOrder(m_userNameCom, m_passwordlineedit);
        QWidget::setTabOrder(m_passwordlineedit, m_rememberpw);
        QWidget::setTabOrder(m_rememberpw, m_pLoginButton);
        QWidget::setTabOrder(m_pLoginButton, m_pRegister);
        QWidget::setTabOrder(m_pRegister, m_pRegisterCancel);
        QWidget::setTabOrder(m_pRegisterCancel, m_closebutton);
        QWidget::setTabOrder(m_closebutton, qLineEdit_UserName);
        QWidget::setTabOrder(qLineEdit_UserName, qLineEdit_PassWord);
        QWidget::setTabOrder(qLineEdit_PassWord, qLineEdit_PhoneNumber);

        retranslateUi(QQLoginClass);

        stackedWidget->setCurrentIndex(0);
        m_pRegister->setDefault(false);


        QMetaObject::connectSlotsByName(QQLoginClass);
    } // setupUi

    void retranslateUi(QWidget *QQLoginClass)
    {
        QQLoginClass->setWindowTitle(QCoreApplication::translate("QQLoginClass", "QQLogin", nullptr));
        m_userNameCom->setItemText(0, QCoreApplication::translate("QQLoginClass", "280761575", nullptr));

        m_userNameCom->setCurrentText(QCoreApplication::translate("QQLoginClass", "280761575", nullptr));
        m_passwordlineedit->setText(QCoreApplication::translate("QQLoginClass", "libingzhi5241.", nullptr));
        m_rememberpw->setText(QCoreApplication::translate("QQLoginClass", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        m_searchpw->setText(QCoreApplication::translate("QQLoginClass", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        m_registaccount->setText(QCoreApplication::translate("QQLoginClass", "+", nullptr));
#if QT_CONFIG(shortcut)
        m_pLoginButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        qLabel_HeadIcon->setText(QString());
        m_pRegister->setText(QCoreApplication::translate("QQLoginClass", "\346\263\250\345\206\214", nullptr));
        m_pRegisterCancel->setText(QCoreApplication::translate("QQLoginClass", "\345\217\226\346\266\210", nullptr));
        m_closebutton->setText(QString());
        label_13->setText(QCoreApplication::translate("QQLoginClass", "\346\211\213\346\234\272\345\217\267", nullptr));
        qLineEdit_UserName->setText(QString());
        qLineEdit_UserName->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("QQLoginClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        qLineEdit_PassWord->setText(QString());
        qLineEdit_PassWord->setPlaceholderText(QString());
        label_19->setText(QCoreApplication::translate("QQLoginClass", "\345\257\206\347\240\201", nullptr));
        qLineEdit_PhoneNumber->setInputMask(QString());
        qLineEdit_PhoneNumber->setPlaceholderText(QString());
        qLabel_UserName->setText(QString());
        qLabel_PassWord->setText(QString());
        qLabel_PhoneNumber->setText(QString());
        label_2->setText(QCoreApplication::translate("QQLoginClass", "\346\254\242\350\277\216\346\263\250\345\206\214", nullptr));
        m_minbutton->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QQLoginClass: public Ui_QQLoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQLOGIN_H
