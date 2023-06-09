#pragma once
#include<Windows.h>
#include<algorithm>
#include <string>
#include "GameLogic.h"
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	~Player();
	int color;
	std::string shape;
	int index;
private:
	POINT m_tPos;
public:
	void SetPos(int _x, int _y) { m_tPos.x = _x; m_tPos.y = _y; }
	int GetX() { return m_tPos.x; }
	int GetY() { return m_tPos.y; }
public:
	void Update();
	void SetCS();
};

