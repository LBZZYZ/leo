#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <qwidget.h>

class MyButton : public QPushButton
{
	Q_OBJECT

public:
	MyButton(QWidget *parent);
	~MyButton();
protected:
	//virtual void enterEvent(QEvent*);
	//virtual void leaveEvent(QEvent*);
	//void timerEvent(QTimerEvent *e);


private:
	int timeId;
	
};

#endif // MYBUTTON_H
