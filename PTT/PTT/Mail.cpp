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

	cout << "����HID: ";
	while (cin >> s) {
		m.Recipient = s;
		cout << "��J�H����D: ";
		cin >> m.title;
		cout << "��J�H�󤺮e: ";
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
			cout << "�H��H: " << iter->sender << endl;
			cout << "�H����D: " << iter->title << endl;
			cout << "����:" << iter->article << endl;
		}
		else {
			if (iter == MailBox.end() - 1) {
				cout << "�L�H��!\n";
				system("pause");
			}
		}
	}
}