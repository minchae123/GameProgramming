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
	POS tNewpos; // �÷��̾� �� ��ġ
	int index;
	int color;
	string shape;
}OBJECT, * OOBJECT;


void SetEnemy();
std::string SelectShape(int n);
int SelectColor(int n);
void PlayerMove(OOBJECT object, char map[12][10]);
void PlayerChange(OOBJECT object);
void Map(char map[12][10]);
void Render(char map[12][10], OOBJECT player);
void Update(OOBJECT player, char map[12][10]);