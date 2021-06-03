#ifndef _QAVATAR_H_
#define _QAVATAR_H_

#include <QPushButton>

typedef enum
{
	E_AVATAR_SHAPE_CIRCLE,
	E_AVATAR_SHAPE_SQUARE
	
}EN_AVATAR_SHAPE;

class QAvatar : public QPushButton
{
	Q_OBJECT

public:
	QAvatar(QPixmap* avatar, QSize size, EN_AVATAR_SHAPE shape, QPoint pos, bool isclickable, QWidget* parent); 
	QAvatar(QWidget *parent);
	~QAvatar();
	void SetAvatar(QPixmap* avatar);

	
private:
    //avatar nature
    QPixmap         m_AvaFile;
    QSize           m_AvaSize;
    EN_AVATAR_SHAPE m_AvaShape;
	QPoint			m_AvaPos;
	bool            m_AvaIsClickable;
};

#endif //_QAVATAR_H_
