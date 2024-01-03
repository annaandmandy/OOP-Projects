#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "nextNum.h"
using namespace std;





class formula
{

public:

	string equ;
	vector<string> equation; // 數字跟算式分開
	int parenthesePlace = 0;//"("
	int parentheseErase = 0;//")"
	vector<string> calculateOperator;// 括弧內的算式，先計算
	string ans;//
	string num1;//運算數字1
	string num2;//運算數字2

	vector<string> deci; // 看除法要不要換成小數
	vector<string> stack; // 算式
	vector<string> number; // 數字

	int placeFront;//數字前面
	int placeBack;

	formula()
	{
	}


	void setEquation(string s);

	string operator=(nextNum a);
	friend string operator-(nextNum a, nextNum b);
	friend string operator+(nextNum a, nextNum b);
	friend string operator*(nextNum a, nextNum b);
	friend string operator/(nextNum a, nextNum b);
	friend string operator^(nextNum a, nextNum b);
	friend string operator/(nextNum anext, string b);


	void minusplusEqu(vector<string> s);
	void minusplusCal(vector<string> s);
	int priority(char c);
	void process(vector<string> s);
	void calculate(vector<string> s);

	void print();

	void reset();
	void Delay();
	/***********************/
	vector<char>set;
	string type;
	string name;
	string value;

	bool include_p = false;
};

