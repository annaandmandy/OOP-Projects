#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef struct {
	string firstName;
	string lastName;
	string phone;
} StRec;

int main() {

	string input;
	vector<StRec> phonebook;
	while (cin >> input)
	{
		if (input == "insert")
		{
			StRec record;
			cin >> record.firstName >> record.lastName >> record.phone;
			for (int i = 0; i < record.phone.size(); i++)
			{
				if (record.phone[i] < '0' || record.phone[i] > '9')
				{
					cout << "Insert Error" << endl;
					continue;
				}
			}
			if (record.firstName.size()> 26 || record.lastName.size() > 31 || record.phone.size() > 16)
				cout << "Insert Error" << endl;
			else if (phonebook.size() > 10)
				cout << "Input Error" << endl;
			else
				phonebook.push_back(record);
		}
		else if (input == "delete")
		{
			StRec dele;
			cin >> dele.firstName >> dele.lastName >> dele.phone;
			int correct;
			int find;
			find = 0;
			for (int i = 0; i < phonebook.size(); i++)
			{
				if (phonebook[i].firstName == dele.firstName && phonebook[i].phone ==dele.phone && phonebook[i].lastName == dele.lastName)
				{
					phonebook.erase(phonebook.begin()+i);
					find += 1;
				}
			}
			if (find == 0)
			{
				cout << "Delete Error" << endl;
			}
		}
		else if (input == "search")
		{
			StRec search;
			cin >> search.firstName >> search.lastName >> search.phone;
			int find;
			find = 0;
			for (int i = 0; i < phonebook.size(); i++)
			{
				if (phonebook[i].firstName == search.firstName&& phonebook[i].phone == search.phone && phonebook[i].lastName == search.lastName)
				{
					cout << i << endl;
					find += 1;
				}
			}	
			if (find == 0)
			{
				cout << "Search Error" << endl;
			}
		}
		else if (input == "print")
		{
			if (phonebook.empty())
			{
				cout << "Print Error" << endl;
			}
			else
			{
				for (int i = 0; i < phonebook.size(); i++)
				{
					cout << phonebook[i].firstName << " " << phonebook[i].lastName << " " << phonebook[i].phone << endl;
				}
			}
		}
	}
	return 0;
}
