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

enum class Shape // 모양 이넘
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


void SetEnemy(OOBJECT enemy, char map[12][11]); // 적의 색과 모양을 랜덤으로 설정해주는 함수
std::string SelectShape(int n); // 모양 정하는 함수
int SelectColor(int n); // 색 정하는 함수
void PlayerChangeShape(OOBJECT object); // 키 입력시 플레이어의 모양 바꿔주기
void PlayerChangeColor(OOBJECT object); // 키 입력시 플레이어의 색 바꿔주기
void Map(char map[12][11], OOBJECT player, OOBJECT enemy); // 맵 찍기, 초반 설정
void Render(char map[12][11], OOBJECT player, OOBJECT enemy); // 그려주는 함수
void Update(OOBJECT player, char map[12][11], OOBJECT enemy); // 계속 도는 함수
void EnemyMove(char map[12][11], OOBJECT enemy, OOBJECT player); // 적이 한칸씩 내려오는 함수
bool Check(OOBJECT player, OOBJECT enemy); // 플레이어와 적의 상태를 확인해주는 함수 
void Heart(OOBJECT player); // 목숨 설정
void Skip(OOBJECT enemy, OOBJECT player); // 스페이스바를 누르면 빨리 내려와 스킵해주는 함수
void PlayBgm(); // 음악 설정