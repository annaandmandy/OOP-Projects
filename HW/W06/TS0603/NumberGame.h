#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class NumberGame{
public:
	vector<int> save;
	int input;
	ifstream ifs;
	vector<int> answer;

	void SetInput(int a);
	void ProcessInput();
	void SetFileName(string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();

};

void NumberGame::SetInput(int a)
{
	this->input = a;
}

void NumberGame::ProcessInput()
{
	string inPut = to_string(this->input);
	for (int i = 0; i < inPut.size(); i++)
	{
		this->save.push_back(inPut[i]);
		this->answer.push_back(inPut[i]);
	}
}

void NumberGame::SetFileName(string txt)
{
	this->ifs.open(txt);
}

void NumberGame::LoadNumberList()
{
	int count = 0;
	int countNum = this->save.size();
	for (int i = 0; i < this->save.size(); i++)
	{
		while (count < countNum)
		{
			
		}

	}
	
	int read;
	while (this->ifs >> read)
	{
		if()
	}
}

void NumberGame::PrintAllValid()
{
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
	
}

void NumberGame::Reset()
{
	vector<int>().swap(save);
}