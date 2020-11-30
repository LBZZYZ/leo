#ifndef _QPERSONLIST_H_
#define _QPERSONLIST_H_

#include <QTreeWidget>
#include <QMenu>
#include <QMouseEvent>
#include <QLineEdit>
#include <QMap>

#include "QFrdListItem.h"

typedef enum  
{ 
	E_NODE_GROUP, 
	E_NODE_USER

}EN_NODE_TYPES;

class QPersonList : public QTreeWidget
{
	Q_OBJECT

public:
	QPersonList(list<FRINENDLISTMSG> *,QWidget *parent);
	~QPersonList();

public:
	void InitMenu();
	void mousePressEvent(QMouseEvent *);//鼠标点击事件
	void contextMenuEvent(QContextMenuEvent*);	//菜单事件
	//------------------------加载好友列表---------------------------------
	void InitFriendTree(list<FRINENDLISTMSG> *);
	void addMyFriendInfo(QTreeWidgetItem * pRootGroupItem,QFrdListItem*, FRINENDLISTMSG *pFriendlistmsg);
	//------------------------加载好友列表---------------------------------
	//void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击事件 
	bool eventFilter(QObject * Watched, QEvent * event);//事件处理器
	void  ModifyNoteDlg(QFrdListItem*);
	
private:
	QMenu* m_pBlankMenu;									//点击空白区域时弹出的菜单
	QMenu* m_pPresonMenu;									//点击好友区域弹出的菜单
	QMenu* m_pGroupMenu;									//组区域弹出的菜单
	QMap<QTreeWidgetItem*, QTreeWidgetItem*> m_GroupMap;	//组的map
	QMap<QTreeWidgetItem*, bool> m_IsGroupHide;				//判断组是否隐藏
	QLineEdit* m_pModifyGroupNameEdit;						//修改组名
	QTreeWidgetItem* TempDeleteItem;						//要删除的项
	QTreeWidgetItem* m_pCurrentItem;						//当前的项
	QTreeWidgetItem *pRootFriendItem;
	
signals:
	void deletefriendsignal(const char*, int);	//修改备注窗口函数
	void openchatwidget(QString);				//打开聊天窗口信号

public slots:
	void AddGroupSlot();//添加qq分组
	void DelFriendSlot();//删除好友
	void DealDeletefrslot(bool result);
	void DelDroupSlot();//删除组
	void ReGroupName();//重名，名组
	void RenameEditFshed();//命名完成
	void  onItemExpanded(QTreeWidgetItem *);//展开好友列表
	void  onItemCollapsed(QTreeWidgetItem *);//收缩好友列表
	void AddGroupTreeSlot();//添加分组树
	void ModifyNoteSlot();//修改好友备注

};

#endif // _QPERSONLIST_H_
