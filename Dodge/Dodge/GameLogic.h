#pragma once
#include <iostream>
#include <string>
#include "console.h"
#include <algorithm>
#include <Windows.h>
#include <mmsystem.h>
#include<Digitalv.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

enum class Shape // ��� �̳�
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
	int indexS;
	int indexC;
	int color;
	string shape;
	int heart;
	int score = 0;
	int time = 1000;
}OBJECT, * OOBJECT;


void SetEnemy(OOBJECT enemy, char map[12][11]); // ���� ���� ����� �������� �������ִ� �Լ�
std::string SelectShape(int n); // ��� ���ϴ� �Լ�
int SelectColor(int n); // �� ���ϴ� �Լ�
void PlayerChangeShape(OOBJECT object); // Ű �Է½� �÷��̾��� ��� �ٲ��ֱ�
void PlayerChangeColor(OOBJECT object); // Ű �Է½� �÷��̾��� �� �ٲ��ֱ�
void Map(char map[12][11], OOBJECT player, OOBJECT enemy); // �� ���, �ʹ� ����
void Render(char map[12][11], OOBJECT player, OOBJECT enemy); // �׷��ִ� �Լ�
void Update(OOBJECT player, char map[12][11], OOBJECT enemy); // ��� ���� �Լ�
void EnemyMove(char map[12][11], OOBJECT enemy, OOBJECT player); // ���� ��ĭ�� �������� �Լ�
bool Check(OOBJECT player, OOBJECT enemy); // �÷��̾�� ���� ���¸� Ȯ�����ִ� �Լ� 
void Heart(OOBJECT player); // ��� ����
void Skip(OOBJECT enemy, OOBJECT player); // �����̽��ٸ� ������ ���� ������ ��ŵ���ִ� �Լ�
void PlayBgm(); // ���� ����