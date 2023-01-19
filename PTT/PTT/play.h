#pragma once
#include<iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
using namespace std;
class play
{
public:
	play();
	~play();

	void choose();
	void number();
	void snake();
	void rock();
};

