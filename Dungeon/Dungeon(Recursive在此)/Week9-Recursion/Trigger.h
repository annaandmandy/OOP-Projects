#pragma once
#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"


//************************************************************
//Item Class
//************************************************************
class Item {
public:
	Position	sPos;			// Hero location
	std::string sIcon = "��";	// Hero icon


public:
	// Default constructor
	Item(void) {
		this->sPos.x = 6;
		this->sPos.y = 7;
		this->sIcon = "��";
	};

	// Setting constructor
	Item(int x, int y, std::string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	Item(Position& pos, std::string icon = "��") {
		this->sPos = pos;
		this->sIcon = icon;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(std::string& icon) { this->sIcon = icon; }

	

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	std::string getIcon(void) { return this->sIcon; }

	virtual void update()
	{
		this->sIcon = '-';
		
	}

};


// �u��:�w��
// �\��:�i�H�����@�Y���H
class Syringe : public Item
{
public:

	static bool killGiant;

	Syringe(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "�w";
	};

	// Setting constructor
	Syringe(int x, int y, std::string icon = "�w") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	Syringe(Position& pos, std::string icon = "�w") {
		this->sPos = pos;
		this->sIcon = icon;
	};

	// ���A�אּ�i�H�����@�Y���H
	virtual void update()
	{
		std::cout << "�w����w��" << std::endl;
		killGiant = 1;
	}

};
bool Syringe::killGiant;

class Kitchen : public Item
{
public:
	Kitchen(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "�p";
	};
	Kitchen(int x, int y, std::string icon = "�p") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};

class Carpet : public Item
{
public:
	Carpet(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "��";
	};
	Carpet(int x, int y, std::string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};

class Torch : public Item
{
public:
	Torch(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "��";
	};
	Torch(int x, int y, std::string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};

class Sofa : public Item
{
public:
	Sofa(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "�F";
	};
	Sofa(int x, int y, std::string icon = "�F") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};

class Table : public Item
{
public:
	Table(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "��";
	};
	Table(int x, int y, std::string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};

class Book : public Item
{
	public:
	Book(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "��";
	};
	Book(int x, int y, std::string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};