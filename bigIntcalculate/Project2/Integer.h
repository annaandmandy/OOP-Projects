#pragma once
#include<vector>
#include<iostream>

using namespace std;

class SetI {
public:
	string a;
	struct Set_re {
		string type;
		string name;
		string value;
	};
	vector<Set_re>re;//重載

	SetI() {
		string b;
	}

	void Setto(string type, string name, string value) {
		Set_re newone;
		newone.type = type;
		newone.name = name;
		newone.value = value;
		this->a = value;
		re.push_back(newone);
	}//存數據

	friend string operator-(nextNum a, nextNum b);
	friend string operator+(nextNum a, nextNum b);
	friend string operator*(nextNum a, nextNum b);
	friend string operator/(nextNum a, nextNum b);
	friend string operator^(nextNum a, nextNum b);




};





