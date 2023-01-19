#include "Mail.h"

Mail::Mail()
{
}

Mail::~Mail()
{
}

void Mail::sendMail(string name)
{
	mail m;
	string s;

	cout << "收件人ID: ";
	while (cin >> s) {
		m.Recipient = s;
		cout << "輸入信件標題: ";
		cin >> m.title;
		cout << "輸入信件內容: ";
		cin >> m.article;
		m.sender = name;
		MailBox.push_back(m);
		return;
		break;

	}
}

void Mail::inBox(string name)
{
	vector<mail>::iterator iter = MailBox.begin();
	for (iter;iter != MailBox.end();++iter) {
		if (name == iter->Recipient) {
			cout << "寄件人: " << iter->sender << endl;
			cout << "信件標題: " << iter->title << endl;
			cout << "內文:" << iter->article << endl;
		}
		else {
			if (iter == MailBox.end() - 1) {
				cout << "無信件!\n";
				system("pause");
			}
		}
	}
}