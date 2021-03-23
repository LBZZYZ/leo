#pragma once

#include <QWidget>

#include <string>

#include "ui_FriendNoteDialog.h"

using namespace std;


class FriendNoteDialog : public QWidget
{
	Q_OBJECT

public:
	FriendNoteDialog(QWidget *parent = Q_NULLPTR);
	~FriendNoteDialog();

	FriendNoteDialog(string _name, string _note)
	{
		name = _name;
		note = _note;
	}


private:
	string name;
	string note;


private:
	void Init();

private:
	Ui::FriendNoteDialog ui;
};
