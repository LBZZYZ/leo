#ifndef MYBUTTONONE_H
#define MYBUTTONONE_H

#include <QPushButton>

class Mybuttonone : public QPushButton
{
	Q_OBJECT

public:
	Mybuttonone(QWidget *parent);
	~Mybuttonone();
	
protected:
	/*void timerEvent(QTimerEvent *e);
	void enterEvent(QEvent * e);*/
private:
	
};

#endif // MYBUTTONONE_H
