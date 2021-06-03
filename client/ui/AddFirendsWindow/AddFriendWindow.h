#ifndef _AddFriendWindow_H_
#define _AddFriendWindow_H_

#include <QWidget>
#include <QLabel>
#include "ui_AddFriendWindow.h"
#include "../../../leo-client/base/QAvatar.h"
#include "FriendNoteDialog.h"


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


class SearchResultStorage
{

private:
	QAvatar *avatar;
	string name;
	string sex;
	string age;

public:
	SearchResultStorage(QAvatar* _avatar, string _name, string _sex, string _age)
	{
		avatar = _avatar;
		name = _name;
		sex = _sex;
		age = _age;

	}

public:
	SearchResultStorage() {}
	~SearchResultStorage();

};

class AddFriendWindow : public QWidget
{
	Q_OBJECT

public	slots:
	void OnSearchFriendsButtonPressed();
	void OnAddFriendButtonPressed();
	void OnRecvSearchFriendsResponse(const char* data, int size);
	
signals:
		void SearchFriendsRequestSignal(const char*, int);
		void AddMsgToMsgList(long long,const char*,int);
		void AddFriendRequestSignal();

private:
	AddFriendWindow(QWidget* parent = 0);
	~AddFriendWindow();

	void Init();
	void DeInit();

	
	bool CheckIfDataValid();
	void SendSearchRequest();

	void SetSearchResultToListWidget(const char* data, int size);
	SearchResultStorage* ParseSearchResult(const char* data, int size);
	SearchResultStorage* ShowSearchResult(SearchResultStorage* item);


	void MakeAddFriendsRequestData();

public:
	static AddFriendWindow* GetInstance();
	static void DeleteInstance();


private:
	Ui::AddFriendWindow ui;
	FriendNoteDialog* friend_note_dialog;
	static AddFriendWindow* addfriend_window;
};

#endif // _AddFriendWindow_H_
