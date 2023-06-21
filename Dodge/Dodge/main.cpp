#include <iostream>
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include "console.h"
#include "Start.h"
#include "GameLogic.h"
#include "End.h"

#pragma comment(lib, "winmm.lib")
using namespace std;

int main() 
{
	srand((unsigned int)time(NULL));
	CursorSet(false, 1);

	char map[12][11] = {};
	OBJECT Player = {};
	OBJECT Enemy = {};

	Map(map, &Player, &Enemy);

	while (true)
	{
		system("cls");
		GameTitle();
		int iMenu = MenuDraw();
		if (iMenu == 0)
			break;
		else if (iMenu == 1)
			InfoDraw();
		else if (iMenu == 2)
		{
			system("cls");
			cout << endl << "게임을 종료합니다" << endl;
			for (int i = 0; i < 3; i++) {
				cout << "\r" << 3 - i;
				Sleep(1000);
			}
			system("cls");
			return 0;
		}
	}
	system("cls"); // 스타트 화면
	
	fontsize(30, 27, 27);
	while (true)
	{
		Gotoxy(0, 0);
		PlayerChangeColor(&Player);
		PlayerChangeShape(&Player);
		Render(map, &Player, &Enemy);

		Update(&Player, map, &Enemy);

		if (Player.heart <= 0)
		{
			break;
		}
	}

	system("cls");
	DrawEnd(Player.score);
}