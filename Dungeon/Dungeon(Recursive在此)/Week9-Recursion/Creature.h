// Name: B10801019, B10801032
// Date: May 14, 2021 
// Last Update: May 14, 2021 
// Problem statement: 新增Giant, Soldier兩種生物

#pragma once
#include <string>
#include "Position.h"
#include "main.h"



class Creature {//creature class 
public:
	Position	sPos;			// Creature position
	std::string sIcon = "怪";			// Creature icon
	std::string findIcon = "！";        // 找到時改變的Icon
	std::string normalIcon = "怪";      // 沒被找到時的標誌
	std::string name = "怪物";
	int attack;
	int health;
public:
	// Default constructor
	Creature(void) {
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "怪";
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	//void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	std::string getIcon(void) 
	{
		return this->sIcon; 
	}

public:
	virtual void update(Position hPos) {
		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			std::cout << this->name << "在( " << dir.x << ", " << dir.y << " )發現主角\n";
			this->sIcon = this->findIcon;
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += dir.x;
				test.y += dir.y;
				if (isPositionValid(test))
				{
					this->sPos.x += dir.x;
					this->sPos.y += dir.y;
				}
			}
		}
		else {
			this->sIcon = normalIcon;
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += 1;
				if (isPositionValid(test))
				{
					this->sPos.x += 1;
				}
				else
				{
					update(hPos);
				}
			}
			if (randNum == 1)
			{
				Position test = sPos;
				test.x -= 1;
				if (isPositionValid(test))
				{
					this->sPos.x -= 1;
				}
				else
				{
					update(hPos);
				}
			}
			if (randNum == 2)
			{
				Position test = sPos;
				test.y += 1;
				if (isPositionValid(test))
				{
					this->sPos.y += 1;
				}
				else
				{
					update(hPos);
				}
			}
			if (randNum == 3)
			{
				Position test = sPos;
				test.y -= 1;
				if (isPositionValid(test))
				{
					this->sPos.y -= 1;
				}
				else
				{
					update(hPos);
				}
			}
		}
	}

	virtual void upDate(Position hPos)
	{

	}
};

// 敵對生物:巨人
// 功能:碰到的話就多一隻, 4隻為上限
class Giant : public Creature
{
public:
	static int count;
public:
	Giant(void)
	{
		this->sPos.x = 2;
		this->sPos.y = 10;
		this->sIcon = "巨";
		this->findIcon = "巨";
		this->normalIcon = "巨";
		this->name = "巨人";
		this->health = 10;
		this->attack = 1;
	}

	Giant(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "巨";
		this->findIcon = "巨";
		this->normalIcon = "巨";
		this->name = "巨人";
		this->health = 10;
		this->attack = 1;
	}

	int countNum() { return this->count; };

	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y && count < 3)
		{
			count += 1;
		}
	}
};

int Giant::count;

/*
// 敵對生物:士兵
// 功能:越大越痛
class Soldier : public Creature
{

public:
	static int damageS;
public:
	Soldier(void)
	{
		this->sPos.x = 8;
		this->sPos.y = 8;
		this->sIcon = 'S';
		this->findIcon = '@';
		this->normalIcon = 'S';
		this->health = 10;
	}

	Soldier(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = 'S';
		this->findIcon = '@';
		this->normalIcon = 'S';
	}

	// 越大越痛
	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			damageS += 1;
		}
	}
};
int Soldier::damageS;*/

class Jaw_Titan : public Creature
{
public:
	static bool caught;
	Jaw_Titan()
	{
		this->sPos.x = 5;
		this->sPos.y = 9;
		this->sIcon = "顎";
		this->findIcon = "顎";
		this->name = "顎巨人";
		this->normalIcon = "顎";
		this->attack = 3;
	}

	virtual void upDate(Position hPos)
	{
		
	}
};
bool Jaw_Titan::caught;

class Cart_Titan : public Creature
{
public:

	Cart_Titan()
	{
		this->sPos.x = 9;
		this->sPos.y = 5;
		this->sIcon = "車";
		this->findIcon = "力";
		this->name = "車力";
		this->normalIcon = "車";
		this->attack = 2;
	}

	virtual void upDate(Position hPos)
	{
		if (abs(sPos.x - hPos.x) <= 2 && abs(sPos.y - hPos.y) <= 2 || abs(sPos.x - hPos.x) <= 2 && abs(sPos.y - hPos.y) == 0 ||
			abs(sPos.x - hPos.x) == 0 && abs(sPos.y - hPos.y) <= 2)
		{
			
		}
	}
};

class Mikasa : public Creature
{
public:
	static bool withEren;
	Mikasa()
	{
		this->sPos.x = 10;
		this->sPos.y = 10;
		this->sIcon = "米";
		this->findIcon = "莎";
		this->name = "米卡莎";
		this->normalIcon = "米";
	}

	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			std::cout << "已攜帶米卡莎" << std::endl;
			withEren = true;
		}
	}
};

bool Mikasa::withEren;




class War_Hammer_Titan : public Creature
{
public:

	static bool hit;
	War_Hammer_Titan()
	{
		this->sPos.x = 2;
		this->sPos.y = 5;
		this->sIcon = "槌";
		this->findIcon = "戰";
		this->name = "戰槌巨人";
		this->normalIcon = "槌";
		this->attack = 10;
	}

	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			hit = true;
		}
	}

	bool InvalidPlaceForWarHammer(Position pos)
	{
		if (pos.y >= 5 || pos.x >= 5)
		{
			return false;
		}
		return true;
	}

	virtual void update(Position hPos)
	{
		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			this->sIcon = this->findIcon;
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += dir.x;
				test.y += dir.y;
				if (isPositionValid(test))
				{
					if (InvalidPlaceForWarHammer(test))
					{
						this->sPos.x += dir.x;
						this->sPos.y += dir.y;
					}
				}
			}
		}
		else {
			this->sIcon = normalIcon;
			int randNum = rand() % 4;
			if (randNum == 0)
			{
				Position test = sPos;
				test.x += 1;
				if (isPositionValid(test))
				{
					if (InvalidPlaceForWarHammer(test))
					{
						this->sPos.x += 1;
					}
					else
					{
						this->sPos.x -= 1;
					}
				}
				else
				{
					this->sPos.x -= 1;
				}
			}
			if (randNum == 1)
			{
				Position test = sPos;
				test.x -= 1;
				if (isPositionValid(test))
				{
					if (InvalidPlaceForWarHammer(test))
					{
						this->sPos.x -= 1;
					}
					else
					{
						this->sPos.x += 1;
					}
				}
				else
				{
					this->sPos.x += 1;
				}
			}
			if (randNum == 2)
			{
				Position test = sPos;
				test.y += 1;
				if (isPositionValid(test))
				{
					if (InvalidPlaceForWarHammer(test))
					{
						this->sPos.y += 1;
					}
					else
					{
						this->sPos.y -= 1;
					}
				}
				else
				{
					this->sPos.y -= 1;
				}
			}
			if (randNum == 3)
			{
				Position test = sPos;
				test.y -= 1;
				if (isPositionValid(test))
				{
					if (InvalidPlaceForWarHammer(test))
					{
						this->sPos.y -= 1;
					}
					else
					{
						this->sPos.y += 1;
					}
				}
				else
				{
					this->sPos.y += 1;
				}
			}
		}
	}
};

bool War_Hammer_Titan::hit;


class War_Hammer_Titan_realPlace : public Creature
{
public:
	static bool find;
	War_Hammer_Titan_realPlace()
	{
		this->sPos.x = 3;
		this->sPos.y = 2;
		this->sIcon = "　";
		this->findIcon = "藏";
		this->normalIcon = "　";
	}

	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			find = true;
		}
	}

	virtual void update(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			this->sIcon = "藏";
		}
	}
};
bool War_Hammer_Titan_realPlace::find;


class Beast_Titan : public Creature
{
public:
	static bool getcaught;
	Beast_Titan()
	{
		this->sPos.x = 13;
		this->sPos.y = 3;
		this->sIcon = "吉";
		this->findIcon = "吉";
		this->normalIcon = "吉";
	}
	virtual void upDate(Position hPos)
	{
		if (sPos.x == hPos.x && sPos.y == hPos.y)
		{
			getcaught = true;
		}
	}
};
bool Beast_Titan::getcaught;




