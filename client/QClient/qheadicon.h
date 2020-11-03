#ifndef QHEADICON_H
#define QHEADICON_H
#include <QPushButton>
//头像
class QHeadIcon : public QPushButton
{
	Q_OBJECT

public:
	QHeadIcon(QPixmap *Icon, int x, int y, int w, int h, bool isEnabled,QWidget *parent);
	~QHeadIcon();

private:
	QPixmap m_HeadIcon;
	QSize m_IconSize;
	
	
};

#endif // QHEADICON_H
