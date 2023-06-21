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
	int score = 0;
	int time = 1000;
}OBJECT, * OOBJECT;


void SetEnemy(OOBJECT enemy, char map[12][11]);
std::string SelectShape(int n);
int SelectColor(int n);
//void PlayerMove(OOBJECT object, char map[12][11]);
void PlayerChangeShape(OOBJECT object);
void PlayerChangeColor(OOBJECT object);
void Map(char map[12][11], OOBJECT player, OOBJECT enemy);
void Render(char map[12][11], OOBJECT player, OOBJECT enemy);
void Update(OOBJECT player, char map[12][11], OOBJECT enemy);
void EnemyMove(char map[12][11], OOBJECT enemy, OOBJECT player);
bool Check(OOBJECT player, OOBJECT enemy);
void Heart(OOBJECT player);
void Skip(OOBJECT enemy, OOBJECT player);