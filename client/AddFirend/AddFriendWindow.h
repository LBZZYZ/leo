#ifndef _AddFriendWindow_H_
#define _AddFriendWindow_H_

#include <QWidget>
#include <QLabel>
#include "ui_AddFriendWindow.h"
#include "Protocol\Protocol.h"
#include "QAvatar.h"


class UiSearchResultItem : public QWidget
{
	Q_OBJECT

public:
	UiSearchResultItem(QAvatar* _avatar, string _name, string _sex, string _age);
	~UiSearchResultItem();


private:
	QAvatar* avatar;
	string name;
	string sex;
	string age;

	QAvatar *avatar_container;
	QLabel *name_container;
	QLabel *sex_container;
	QLabel *age_container;
	QPushButton *addfriends_button;

private:
	void Init();
	void DrawItemUi();
	void DeInit();
};


class SearchResultItem
{

private:
	QAvatar *avatar;
	string name;
	string sex;
	string age;

public:
	SearchResultItem(QAvatar* _avatar, string _name, string _sex, string _age)
	{
		avatar = _avatar;
		name = _name;
		sex = _sex;
		age = _age;

	}

public:
	SearchResultItem() {}
	~SearchResultItem();

};

class AddFriendWindow : public QWidget
{
	Q_OBJECT

public	slots:
	void OnSearchFriendsButtonPressed();
	void OnAddFriendButtonPressed();
	//void DealserchRS(STRU_SEARCH_USER_RS*);
	void AddFriendSlot();
	
signals:
		void sendsearchsignal(const char*, int);
		void SendAddFriendRequest(const char*,int, int);
		void AddMsgToMsgList(long long,const char*,int);

public:
	AddFriendWindow(QWidget* parent = 0);
	~AddFriendWindow();
	//bool eventFilter(QObject* obj, QEvent* event) override;

private:
	void Init();
	//void DeInit();
	//void Show();
	//void Hide();

	void AddFriendWindow::SetSearchResultToListWidget(STRU_SEARCH_USER_RS* rs);
	bool CheckIfDataValid();
	void SendSearchRequest();

	SearchResultItem* ParseSearchResult(STRU_SEARCH_USER_RS* rs);
	SearchResultItem* AddFriendWindow::ShowSearchResult(SearchResultItem* item);


	

private:
	Ui::AddFriendWindow ui;
};

#endif // _AddFriendWindow_H_
