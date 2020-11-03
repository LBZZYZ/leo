#include "QPersonList.h"
#include "qaction.h"

#include <QDialog>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <qfile.h>
#include <QTextStream>
#include <qdebug.h>
#include <Protocol\Protocol.h>
QPersonList::QPersonList(list<FRINENDLISTMSG> * pFriendlistmsg,QWidget *parent)
	: QTreeWidget(parent)
{
	TempDeleteItem = nullptr;
	InitMenu();
	setFixedSize(parent->width(), parent->height());
	InitFriendTree(pFriendlistmsg);
	m_pModifyGroupNameEdit = new QLineEdit("未命名", this);
	m_pModifyGroupNameEdit->hide();
	m_pModifyGroupNameEdit->setContextMenuPolicy(Qt::NoContextMenu);
	m_pModifyGroupNameEdit->installEventFilter(this);

}

QPersonList::~QPersonList()
{

}

void QPersonList::InitMenu()
{
	//初始化
	m_pBlankMenu = new QMenu();
	m_pGroupMenu = new QMenu();
	m_pPresonMenu = new QMenu();
	//m_pPresonMenu->setStyleSheet("QMenu::item{padding-left:40px;}");



	//组菜单
	QAction *ReFreshCurrentList = new QAction(QString("刷新好友列表"), this);
	QAction *AddGroup = new QAction(QString("添加分组"), this);
	QAction *ReGroupName = new QAction(QString("重命名"), this);
	QAction *DelCurrentGroup = new QAction(QString("删除该组"), this);

	//好友菜单
	QAction *ViewInfo = new QAction(QString("查看好友资料"), this);
	QAction *MoveFriend = new QAction(QString("移动联系人至"), this);
	QAction *DelFriend = new  QAction(QString("删除好友"), this);
	QAction *ModifyNote = new QAction(QString("修改备注"), this);
	QAction *AddFriend = new QAction(QString("添加好友"), this);

	//布局
	m_pGroupMenu->addAction(ReFreshCurrentList);
	m_pGroupMenu->addSeparator();
	m_pGroupMenu->addAction(AddGroup);
	m_pGroupMenu->addAction(ReGroupName);
	m_pGroupMenu->addAction(DelCurrentGroup);

	m_pPresonMenu->addAction(ViewInfo);
	m_pPresonMenu->addAction(ModifyNote);
	m_pPresonMenu->addAction(DelFriend);
	m_pPresonMenu->addAction(MoveFriend);
	m_pPresonMenu->addAction(AddFriend);

	m_pBlankMenu->addAction(AddGroup);

	//信号槽
	//connect(m_pGroupNameEdit, SIGNAL(editingFinished()), this, SLOT(RenameEditFshed()));
	connect(AddGroup, SIGNAL(triggered()), this, SLOT(AddGroupTreeSlot()));
	connect(DelCurrentGroup, SIGNAL(triggered()), this, SLOT(DelDroupSlot()));
	connect(ReGroupName, SIGNAL(triggered()), this, SLOT(ReGroupNameSLot()));
	connect(AddFriend, SIGNAL(triggered()), this, SLOT(AddFriendSlot()));
	connect(DelFriend, SIGNAL(triggered()), this, SLOT(DelFriendSlot()));
	connect(ModifyNote, SIGNAL(triggered()), this, SLOT(ModifyNoteSlot()));


}

/*初始化好友列表*/
void QPersonList::InitFriendTree(list<FRINENDLISTMSG> *pFriendlistmsg)
{
	//if (NULL == pFriendlistmsg)return;

	this->setHeaderHidden(true);		//隐藏标题头
	this->setColumnCount(1);			//QPersonList的列数
	//this->setIndentation(0);			//子项相对与父项的缩进

	pRootFriendItem = new QTreeWidgetItem(this,QStringList(QString("我的好友")));
	pRootFriendItem->setData(0, Qt::UserRole, 0);		//设置Data用于区分，Item是分组节点还是子节点，0代表分组节点，1代表子节点

	int nMyFriendNum = 3;

	for (int nIndex = 0; nIndex < nMyFriendNum; ++nIndex)
	{
		addMyFriendInfo(pRootFriendItem, nullptr, /*&(pFriendlistmsg->front()*/NULL);		//添加子节点
	}

	this->addTopLevelItem(pRootFriendItem);

	connect(this, SIGNAL(itemExpanded(QTreeWidgetItem *)), this, SLOT(onItemExpanded(QTreeWidgetItem *)));
	connect(this, SIGNAL(itemCollapsed(QTreeWidgetItem *)), this, SLOT(onItemCollapsed(QTreeWidgetItem *)));
	expandItem(pRootFriendItem);
}


/*添加好友结点*/
void QPersonList::addMyFriendInfo(QTreeWidgetItem* pRootGroupItem, QMessageItem* pContactItem, FRINENDLISTMSG *pFriendlistmsg)
{
	QTreeWidgetItem *pChild = new QTreeWidgetItem();
	pChild->setSizeHint(0, QSize(size().width(),70));

	if (pContactItem != nullptr)
	{
		pChild->setData(0, Qt::UserRole, 1);
		pContactItem = new QMessageItem(this);
		pContactItem->setSizeIncrement(size().width(), 70);

		pRootGroupItem->addChild(pChild);
		setItemWidget(pChild, 0, pContactItem);
	}
	else
	{
		pChild->setData(0, Qt::UserRole, 1);
		QMessageItem * ptemp = new QMessageItem(this,nullptr,"F","",0);
		ptemp->setSizeIncrement(size().width(), 70);

		//ptemp->SetName("");
		//ptemp->SetSignatrue("This event handler, for event event, can be reimplemented in a subclass to receive mouse double click events for the widget ");
		//ptemp->setNameLabelText();
		pRootGroupItem->addChild(pChild);
		setItemWidget(pChild, 0, ptemp);
	}

}
void QPersonList::AddGroupTreeSlot()
{
	QTreeWidgetItem *pAddGroupItem = new QTreeWidgetItem();
	//设置Data用于区分，Item是分组节点还是子节点，0代表分组节点，1代表子节点
	pAddGroupItem->setData(0, Qt::UserRole, 0);
	QLabel* ItemName = new QLabel("未命名");
	this->addTopLevelItem(pAddGroupItem);
	this->setItemWidget(pAddGroupItem, 0, ItemName);
	m_pModifyGroupNameEdit->show();
	m_pModifyGroupNameEdit->setFocus();
	m_pModifyGroupNameEdit->selectAll();
	m_pModifyGroupNameEdit->setGeometry(itemWidget(topLevelItem(topLevelItemCount() - 1), 0)->geometry());
}
void QPersonList::ModifyNoteSlot()
{
	QMessageItem* PersonItem = (QMessageItem*)itemWidget(currentItem(), 0);

	ModifyNoteDlg(PersonItem);

}

bool QPersonList::eventFilter(QObject * Watched, QEvent * event)
{
	if (Watched == m_pModifyGroupNameEdit)
	{
		switch (event->type())
		{
		case QKeyEvent::KeyPress:
		{

			if (event->type() == QKeyEvent::KeyPress)
			{
				QKeyEvent* q = static_cast<QKeyEvent*>(event);
				if (q->key() == Qt::Key_Enter)
				{
					//拿到原来的组名
					QLabel* ItemName = (QLabel*)itemWidget(topLevelItem(topLevelItemCount() - 1), 0);
					ItemName->setText(m_pModifyGroupNameEdit->text());
					//topLevelItem(topLevelItemCount() - 1)->setText(0, m_pModifyGroupNameEdit->text());
					m_pModifyGroupNameEdit->setText("未命名");
					m_pModifyGroupNameEdit->hide();
					return true;
				}
			}
			break;
		}
		case  QEvent::FocusOut:
		{
			QLabel* ItemName = (QLabel*)itemWidget(topLevelItem(topLevelItemCount() - 1), 0);
			ItemName->setText(m_pModifyGroupNameEdit->text());
			m_pModifyGroupNameEdit->setText("未命名");
			m_pModifyGroupNameEdit->hide();
			return true;
		}
		break;

		}
	}

	return  QWidget::eventFilter(Watched, event); ;
	//return QWidget::eventFilter(Watched, event);
}

void QPersonList::onItemExpanded(QTreeWidgetItem *pItem)
{
	bool bIsChild = pItem->data(0, Qt::UserRole).toBool();
	if (!bIsChild)
	{
		QWidget *pWidget = this->itemWidget(pItem, 0);
		if (pWidget)
		{
			//pWidget->setStyleSheet("border-image: url(:/Demo/Resources/common/arrow_down.png);border-width:0 0 0 20;");
		}
	}
}

void QPersonList::onItemCollapsed(QTreeWidgetItem *pItem)
{
	bool bIsChild = pItem->data(0, Qt::UserRole).toBool();
	if (!bIsChild)
	{
		QWidget *pWidget = this->itemWidget(pItem, 0);
		if (pWidget)
		{
			//pWidget->setStyleSheet("border-image: url(:/Demo/Resources/common/arrow_up.png);border-width:0 0 0 20;");
		}
	}
}


void QPersonList::AddFriendSlot()
{

}
void QPersonList::AddGroupSlot()
{

}
void QPersonList::DelFriendSlot()//删除操作
{
	if (currentItem()->data(0, Qt::UserRole).toBool())//是否是好友item
	{
		TempDeleteItem = currentItem();
		STRU_USER_DELETE_RQ rq;
		rq.packtype = PROTOCOL_GROUP_ADD_RS;
		rq.llUserID = userId;
		QMessageItem* tempitem = (QMessageItem*)itemWidget(currentItem(), 0);//拿到好友的自定义item	
		rq.llSearchID = tempitem->GetUserId();

		deletefriendsignal((const char*)&rq, sizeof(STRU_USER_DELETE_RQ));
	}

}
void QPersonList::DealDeletefrslot(bool result)//确认是否要删除
{
	if (result)
	{
		TempDeleteItem->~QTreeWidgetItem();
		QMessageBox tempmessag(QMessageBox::Information, QString("%1-删除好友").arg(userId), QString("删除成功"), QMessageBox::Ok | QMessageBox::Close);
	}
	else
	{
		QMessageBox tempmessag(QMessageBox::Information, QString("%1-删除好友").arg(userId), QString("删除失败"), QMessageBox::Ok | QMessageBox::Close);
	}
}

void QPersonList::DelDroupSlot()
{

}
void QPersonList::ReGroupName()
{



}
void QPersonList::RenameEditFshed()
{

}
void QPersonList::mousePressEvent(QMouseEvent *event)//鼠标点击事件
{
	setCurrentItem(itemAt(event->pos()));//设置鼠标按下的Item为当前Item；
	if (currentItem() == NULL)
		return;
	switch (event->button())
	{
	case Qt::LeftButton:
		if (currentItem()->data(0, Qt::UserRole) == 0)
		{
			if (currentItem()->isExpanded())
			{
				// emit itemCollapsed(currentItem());
				collapseItem(currentItem());//展开
			}
			else
			{
				// emit itemExpanded(currentItem());
				expandItem(currentItem());//收缩
			}
		}
		break;
	default:
		break;
	}



}

/*双击左键发送打开聊天窗口的信号*/
void QPersonList::mouseDoubleClickEvent(QMouseEvent *event)
{
	QTreeWidgetItem* tempItem = itemAt(event->pos());
	if (tempItem == NULL)return;

	if (event->button() == Qt::LeftButton)
	{
		if (tempItem->data(0, Qt::UserRole) == 1)//是否是好友item
		{
			QMessageItem* item = (QMessageItem*)itemWidget(tempItem, 0);
			emit openchatwidget(item->GetNameLabel()->text());
		}
	}

}
void QPersonList::contextMenuEvent(QContextMenuEvent* event)//菜单事件，为了显示菜单 
{
	setCurrentItem(itemAt(event->pos()));
	QTreeWidget::contextMenuEvent(event); //调用基类事件 

	if (currentItem() == NULL)                           //如果点击到的是空白处  
		m_pBlankMenu->exec(QCursor::pos());
	else if (currentItem()->data(0, Qt::UserRole).toBool() == false)    // 如果点击到的是组
		m_pGroupMenu->exec(QCursor::pos());
	else                                            //否则点击到的是好友  
		m_pPresonMenu->exec(QCursor::pos());
}
void QPersonList::ModifyNoteDlg(QMessageItem* pItem)
{
	//窗口
	QDialog dlg(nullptr, Qt::Dialog | Qt::WindowCloseButtonHint);

	dlg.setWindowTitle(tr("重命名"));
	//按钮
	QDialogButtonBox buttonBox;
	buttonBox.setParent(&dlg);
	//buttonBox.setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
	buttonBox.addButton("确定", QDialogButtonBox::YesRole);
	buttonBox.addButton("取消", QDialogButtonBox::NoRole);
	connect(&buttonBox, SIGNAL(accepted()), &dlg, SLOT(accept()));
	connect(&buttonBox, SIGNAL(rejected()), &dlg, SLOT(rejecte()));
	//备注编辑框
	QLineEdit qName(&dlg);
	qName.setText(pItem->GetNameLabel()->text());
	qName.setFocus();
	qName.selectAll();
	//布局管理
	QVBoxLayout *layout = new QVBoxLayout;
	//添加布局要管理的控件
	layout->addWidget(&qName);
	layout->addWidget(&buttonBox);
	dlg.setLayout(layout);

	//按下按钮返回的消息
	int res = dlg.exec();
	if (res == QDialog::Accepted)
	{
		if (qName.text().isEmpty())
		{
			pItem->setNameLabelText();
		}
		else
		{
			pItem->SetNote(qName.text());
			pItem->setNameLabelText();
		}
	}
	if (res == QDialog::Rejected)//取消键有问题
	{
		QMessageBox::about(NULL, "提示", " 您点击了关闭按钮！");
		//添加关闭时你要的行为

	}
}

