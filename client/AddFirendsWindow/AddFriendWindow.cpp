#include "AddFriendWindow.h"
#include "FriendNoteDialog.h"
#include "../../../leo-client/net/Protocol/Protocol.h"
AddFriendWindow* AddFriendWindow::addfriend_window = NULL;

AddFriendWindow::AddFriendWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->Init();
}


void AddFriendWindow::Init()
{
	setAttribute(Qt::WA_DeleteOnClose);

	friend_note_dialog = new FriendNoteDialog;
	ui.AgeComboBox->setView(new QListView());
	ui.SexComboBox->setView(new QListView());

	connect(ui.SearchFriendsButton, &QPushButton::pressed, this, &AddFriendWindow::OnSearchFriendsButtonPressed);
}

void AddFriendWindow::OnSearchFriendsButtonPressed()
{
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
	STRU_SEARCH_FRIENDS_REQUEST* search_friends_request = new STRU_SEARCH_FRIENDS_REQUEST;
	strncpy_s(search_friends_request->friend_id, ui.SearchInfoEditor->text().toStdString().c_str(), strlen(ui.SearchInfoEditor->text().toStdString().c_str()));
	
	emit SearchFriendsRequestSignal((const char*)search_friends_request, sizeof(STRU_SEARCH_FRIENDS_REQUEST));
}


void AddFriendWindow::OnRecvSearchFriendsResponse(const char* data, int size)
{
	SetSearchResultToListWidget(data, size);
}



void AddFriendWindow::SetSearchResultToListWidget(const char* data, int size)
{

	SearchResultStorage* item = ParseSearchResult(data, size);
	ShowSearchResult(item);
}


SearchResultStorage* AddFriendWindow::ParseSearchResult(const char* data, int size)
{
	STRU_SEARCH_USER_RS* rs = (STRU_SEARCH_USER_RS*)data;
	SearchResultStorage* storage = new SearchResultStorage;
	string name(rs->szUserName);
	string sex(rs->szSex == 'f' ? "女" : "男");
	string age(rs->szBirth);

	return storage;
}


SearchResultStorage* AddFriendWindow::ShowSearchResult(SearchResultStorage* item)
{
	UiSearchResultItem* _item = new UiSearchResultItem(nullptr, "test", "female", "nine");
	QListWidgetItem* temp = new QListWidgetItem;
	
	ui.listWidget->addItem(temp);
	ui.listWidget->setItemWidget(temp, _item);
	return nullptr;
}


void AddFriendWindow::OnAddFriendButtonPressed()
{
	MakeAddFriendsRequestData();
	
	emit AddFriendRequestSignal();
}


void AddFriendWindow::MakeAddFriendsRequestData()
{
	//To Do
}



AddFriendWindow::~AddFriendWindow()
{
	ui.retranslateUi(this);
	this->DeInit();

}

void AddFriendWindow::DeInit()
{
	delete friend_note_dialog;
	friend_note_dialog = nullptr;
}


AddFriendWindow* AddFriendWindow::GetInstance()
{
	if (nullptr == addfriend_window)
	{
		addfriend_window = new AddFriendWindow;
	}
	return addfriend_window;
}

void AddFriendWindow::DeleteInstance()
{
	delete addfriend_window;
	addfriend_window = nullptr;
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