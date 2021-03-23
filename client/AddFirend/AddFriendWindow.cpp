#include "AddFriendWindow.h"
#include "FriendNoteDialog.h"

AddFriendWindow::AddFriendWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->Init();
}


void AddFriendWindow::Init()
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(ui.SearchFriendsButton, &QPushButton::pressed, this, &AddFriendWindow::OnSearchFriendsButtonPressed);
	//connect(AddFriend, SIGNAL(triggered()), this, SLOT(AddFriendSlot()));
}

//bool AddFriendWindow::eventFilter(QObject *obj, QEvent *event)
//{
//	if (obj == ui.tableWidget)
//	{
//		if (event->type() == QEvent::ContextMenu)
//		{
//			QMouseEvent* e = static_cast<QMouseEvent*>(event);
//			if (ui.tableWidget->itemAt(e->pos()) != 0)
//			{
//				m_pmenu->exec(QCursor::pos());
//				return true;
//			}
//			event->ignore();
//		}
//	}
//	return false;
//}


void AddFriendWindow::OnSearchFriendsButtonPressed()
{
	ShowSearchResult(nullptr);
	bool ret = CheckIfDataValid();
	if (ret)
	{
		SendSearchRequest();
	}
}

bool AddFriendWindow::CheckIfDataValid()
{
	//string input_key = ui.SearchInfoEditor->text().toStdString();


	return true;
}

void AddFriendWindow::SendSearchRequest()
{
	//STRU_SEARCH_USER_RQ & search_friends_request;
	//emit sendsearchsignal((const char*)&search_friends_request, sizeof(STRU_SEARCH_USER_RQ));
}


void AddFriendWindow::SetSearchResultToListWidget(STRU_SEARCH_USER_RS* rs)
{

	SearchResultItem* item = ParseSearchResult(rs);
	ShowSearchResult(item);
}


SearchResultItem* AddFriendWindow::ParseSearchResult(STRU_SEARCH_USER_RS* rs)
{
	SearchResultItem* storage = new SearchResultItem;
	string name(rs->szUserName);
	string sex(rs->szSex == 'f' ? "女" : "男");
	string age(rs->szBirth);


	return nullptr;
}


SearchResultItem* AddFriendWindow::ShowSearchResult(SearchResultItem* item)
{
	UiSearchResultItem* _item = new UiSearchResultItem(nullptr, "test", "female", "nine");
	QListWidgetItem* temp = new QListWidgetItem;
	
	ui.listWidget->addItem(temp);
	ui.listWidget->setItemWidget(temp, _item);
	return nullptr;
}


void AddFriendWindow::OnAddFriendButtonPressed()
{

}

void AddFriendWindow::AddFriendSlot()
{

}



AddFriendWindow::~AddFriendWindow()
{
	ui.retranslateUi(this);
	//this->DeInit();

}


UiSearchResultItem::UiSearchResultItem(QAvatar* _avatar, string _name, string _sex, string _age)
{
	avatar = _avatar;
	name = _name;
	sex = _sex;
	age = _age;
	avatar_container = new QAvatar(NULL);
	name_container = new QLabel(QString::fromStdString(name));
	sex_container = new QLabel(QString::fromStdString(sex));
	age_container = new QLabel(QString::fromStdString(age));
	addfriends_button = new QPushButton("Add");

	this->Init();
}

void UiSearchResultItem::Init()
{
	DrawItemUi();
}

void UiSearchResultItem::DrawItemUi()
{
	QHBoxLayout *frame = new QHBoxLayout;

	frame->addWidget(name_container);
	frame->addWidget(sex_container);
	frame->addWidget(age_container);
	frame->addWidget(addfriends_button);

	this->setLayout(frame);
}


void UiSearchResultItem::DeInit()
{
	delete avatar_container;
	avatar_container = nullptr;

	delete name_container;
	name_container = nullptr;

	delete sex_container;
	sex_container = nullptr;

	delete age_container;
	age_container = nullptr;

	delete addfriends_button;
	addfriends_button = nullptr;
}


UiSearchResultItem::~UiSearchResultItem()
{
	this->DeInit();
}