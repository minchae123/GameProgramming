#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "console.h"
#include <conio.h>
#include "Start.h"

using namespace std;

void GameTitle()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	SetColor((int)COLOR::BLUE, (int)COLOR::SKYBLUE);
	wcout << L"	██████╗  ██████╗ ██████╗  ██████╗ ███████╗     ██████╗███████╗	" << endl;
	wcout << L"	██╔══██╗██╔═══██╗██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██╔════╝	" << endl;
	wcout << L"	██║  ██║██║   ██║██║  ██║██║  ███╗█████╗      ██║     ███████╗	" << endl;
	wcout << L"	██║  ██║██║   ██║██║  ██║██║   ██║██╔══╝      ██║     ╚════██║	" << endl;
	wcout << L"	██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗    ╚██████╗███████║	" << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝     ╚═════╝╚══════╝	" << endl;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	int Curmode = _setmode(_fileno(stdout), prevmode);
}

int KeyController()
{
	int iKey = _getch();
	if (iKey == 224) {
		iKey = _getch();
		switch (iKey)
		{
		case 72:
			return (int)KEY::UP;
		case 80:
			return (int)KEY::DOWN;
		default:
			break;
		}
	}
	else if (iKey == 32) {
		return (int)KEY::SPACE;
	}
	return 0;
}

int MenuDraw()
{
	int x = 30;
	int y = 12;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";
	while (true) {
		int ikey = KeyController();
		switch (ikey)
		{
		case(int)KEY::UP: {
			if (y > 12) {
				Gotoxy(x - 2, y);
				cout << "  ";
				Gotoxy(x - 2, --y);
				cout << "▶";
			}
		}
		break;
		case(int)KEY::DOWN: {
			if (y < 14) {
				Gotoxy(x - 2, y);
				cout << "  ";
				Gotoxy(x - 2, ++y);
				cout << "▶";
			}
		}
  		break;
		case(int)KEY::SPACE: {
			return y - 12;
		}
		break;
		default:
			break;
		}
	}
	return 0;
}

void InfoDraw()
{
	system("cls");
	cout << endl << endl;
	cout << "[ 조작법 ]" << endl;
	cout << "이동 : 방향키" << endl;
	cout << "[ 게임 설명 ]" << endl;
	cout << "떨어지는 물체의 색과 모양을 똑같이 맞춰 점수를 획득하세요" << endl;
	cout << "하나라도 다른 게 있다면 하트가 감소합니다" << endl;

	while (true) {
		if (KeyController() == (int)KEY::SPACE)
			break;
	}
	_getch();
}
