#pragma once
#include <iostream>
#include <string>
#include "console.h"
#include<algorithm>
using namespace std;

enum class Shape
{
	Clover,
	Diamond,
	Star,
	Heart
};

typedef struct _tagpos {
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagObject {
	POS tPos;
	POS tNewpos; // 플레이어 새 위치
	int indexS;
	int indexC;
	int color;
	string shape;
	int heart;
}OBJECT, * OOBJECT;


void SetEnemy();
std::string SelectShape(int n);
int SelectColor(int n);
//void PlayerMove(OOBJECT object, char map[12][11]);
void PlayerChangeShape(OOBJECT object);
void PlayerChangeColor(OOBJECT object);
void Map(char map[12][11], OOBJECT player);
void Render(char map[12][11], OOBJECT player);
void Update(OOBJECT player, char map[12][11]);

bool Check(OOBJECT player, OOBJECT enemy);