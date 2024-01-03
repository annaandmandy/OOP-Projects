#include "calculation.h"
#include"Integer.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void Delay()
{
	for (int i = 0; i < 60; i++)
	{
		
	}
}

int main()
{
	
	formula F;
	string s;
	SetI I;


	while (getline(cin, s))
	{/*
		for (int i = 1; i <= 100; i++)
		{
			
			cout << "Doing calculating : ";
			if (i % 4 == 0)
			{
				cout << i <<"%";
			}

			else if (i % 4 == 1)
			{
				cout << i << "%";
			}

			else if (i % 4 == 2)
			{
				cout << i << "%";
			}

			else if (i % 4 == 3)
			{
				cout << i << "%";
			}
			system("color 3");

			Delay();
			system("CLS");
		}*/


		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '!' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0' || s[i] == '(' || s[i] == ')' || s[i] == ' ')
			{
				continue;
			}
			else
			{
				std::cout << "wrong!!!" << endl;
				return 0;
			}
		}

		F.setEquation(s);

		while (F.equation.size() != 1)
		{
			bool parenthese = 0; // 有沒有括號
			for (int i = 0; i < F.equation.size(); i++)
			{

				if (F.equation[i] == "(")
				{
					F.parenthesePlace = i + 1;
					parenthese = 1;
				}
			}

			// 將括弧內的算式丟入
			for (int i = F.parenthesePlace; i < F.equation.size(); i++)
			{
				if (F.equation[i] == ")")
				{
					F.parentheseErase = i;
					F.equation.erase(F.equation.begin() + F.parenthesePlace - 1, F.equation.begin() + i + 1);
					break;
				}
				F.calculateOperator.push_back(F.equation[i]);
			}

			if (parenthese == 1)
			{
				F.minusplusCal(F.calculateOperator);
				F.process(F.calculateOperator);
				F.calculate(F.calculateOperator);
				if (F.equation.size() <= F.parenthesePlace - 1)
				{
					F.equation.push_back(F.ans);
				}
				else
				{
					F.equation.insert(F.equation.begin() + F.parenthesePlace - 1, F.ans);
				}
				vector<string>().swap(F.number);
				vector<string>().swap(F.stack);
				vector<string>().swap(F.deci);
				vector<string>().swap(F.calculateOperator);
			}
			else if (parenthese == 0)
			{
				F.minusplusEqu(F.equation);
				F.process(F.equation);
				F.calculate(F.equation);
				vector<string>().swap(F.number);
				vector<string>().swap(F.stack);
				vector<string>().swap(F.deci);
				vector<string>().swap(F.equation);
				F.equation.push_back(F.ans);
			}
		}

		F.print();
		F.reset();

	}
		return 0;
}