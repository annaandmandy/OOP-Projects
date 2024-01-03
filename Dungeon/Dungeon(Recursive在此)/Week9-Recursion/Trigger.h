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
	std::string sIcon = "Ｔ";	// Hero icon


public:
	// Default constructor
	Item(void) {
		this->sPos.x = 6;
		this->sPos.y = 7;
		this->sIcon = "Ｔ";
	};

	// Setting constructor
	Item(int x, int y, std::string icon = "Ｔ") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	Item(Position& pos, std::string icon = "Ｔ") {
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


// 工具:針筒
// 功能:可以殺死一頭巨人
class Syringe : public Item
{
public:

	static bool killGiant;

	Syringe(void) {
		this->sPos.x = 4;
		this->sPos.y = 11;
		this->sIcon = "針";
	};

	// Setting constructor
	Syringe(int x, int y, std::string icon = "針") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	Syringe(Position& pos, std::string icon = "針") {
		this->sPos = pos;
		this->sIcon = icon;
	};

	// 狀態改為可以殺死一頭巨人
	virtual void update()
	{
		std::cout << "已拿到針筒" << std::endl;
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
		this->sIcon = "廚";
	};
	Kitchen(int x, int y, std::string icon = "廚") {
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
		this->sIcon = "毯";
	};
	Carpet(int x, int y, std::string icon = "毯") {
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
		this->sIcon = "火";
	};
	Torch(int x, int y, std::string icon = "火") {
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
		this->sIcon = "沙";
	};
	Sofa(int x, int y, std::string icon = "沙") {
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
		this->sIcon = "桌";
	};
	Table(int x, int y, std::string icon = "桌") {
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
		this->sIcon = "書";
	};
	Book(int x, int y, std::string icon = "書") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};
};