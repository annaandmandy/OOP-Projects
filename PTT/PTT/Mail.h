#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"User.h"
#pragma once
using namespace std;

struct mail {
	string title;
	string article;
	string sender;
	string Recipient;
};


class Mail :public User
{
public:
	vector<mail>MailBox;
	Mail();
	~Mail();
	void sendMail(string name);
	void inBox(string name);
};
