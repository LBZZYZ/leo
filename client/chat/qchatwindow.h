#ifndef QCHATWINDOW_H
#define QCHATWINDOW_H

#include <QWidget>
#include "ui_qchatwindow.h"
#include "qnchatmessage.h"
#include <QListWidgetItem>
#include <Protocol\Protocol.h>
class QChatWindow : public QWidget
{
	Q_OBJECT

public:
	explicit QChatWindow(QWidget *parent = 0);
	~QChatWindow();
protected:
	void resizeEvent(QResizeEvent *event);
private slots:
	void DealSendMsgRsSlot(char*, int);
signals:
	void sendchatmsgsignal(const char*,int,int);
private:
	Ui::QChatWindow ui;
};

#endif // QCHATWINDOW_H

