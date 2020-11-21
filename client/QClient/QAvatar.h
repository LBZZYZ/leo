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
	QAvatar(QPixmap* avatar, QSize size, EN_AVATAR_SHAPE shape, int x, int y, bool isclickable, QWidget* parent); 
	QAvatar(QWidget *parent);
	~QAvatar();

	
private:
    //avatar nature
    QPixmap         m_AvaFile;
    QSize           m_AvaSize;
    EN_AVATAR_SHAPE m_AvaShape;
    bool            m_AvaIsClickable;
    int             m_AvaPosX;
    int             m_AvaPosY;
	
	
};

#endif //_QAVATAR_H_
