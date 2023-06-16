#include "GameLogic.h"
using namespace std;

void SetEnemy()
{
	int sr = rand() % 4;
	int cr = rand() % 4;

	SetColor(SelectColor(cr), (int)COLOR::BLACK);
	cout << SelectShape(sr) << " " << endl;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

std::string SelectShape(int n)
{
	if (n == (int)Shape::Clover) 
	{
		return "♣";
	}
	else if (n == (int)Shape::Diamond)
	{
		return "◈";
	}
	else if (n == (int)Shape::Star)
	{
		return "★";
	}
	else if (n == (int)Shape::Heart)
	{
		return "♥";
	}
	else
		return "♣";
}

int SelectColor(int n)
{
	if (n == 0)
	{
		return (int)COLOR::LIGHT_GREEN;
	}
	else if (n == 1)
	{
		return (int)COLOR::LIGHT_BLUE;
	}
	else if (n == 2)
	{
		return (int)COLOR::LIGHT_YELLOW;
	}
	else if (n == 3)
	{
		return (int)COLOR::LIGHT_VIOLET;
	}
	else
		return 10;
}

//void PlayerMove(OOBJECT object, char map[12][11])
//{
//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
//	{
//		--object->tPos.x;
//		Sleep(100);
//	}
//	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
//	{
//		++object->tPos.x;
//		Sleep(100);
//	}
//	object->tPos.x = std::clamp(object->tPos.x, 1, 8);
//}

void PlayerChangeShape(OOBJECT object)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
	{
		object->indexS++;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		object->indexS--;
		Sleep(100);
	}
	object->indexS = std::clamp(object->indexS, 0, 3);

	object->shape = SelectShape(object->indexS);
}

void PlayerChangeColor(OOBJECT object)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		object->indexC++;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		object->indexC--;
		Sleep(100);
	}
	object->indexC = std::clamp(object->indexC, 0, 3);

	object->color = SelectColor(object->indexC);
}

void Map(char map[12][11], OOBJECT player) 
{
	strcpy_s(map[0],  "1222222221");
	strcpy_s(map[1],  "1000000001");
	strcpy_s(map[2],  "1000000001");
	strcpy_s(map[3],  "1000000001");
	strcpy_s(map[4],  "1000000001");
	strcpy_s(map[5],  "1000000001");
	strcpy_s(map[6],  "1000000001");
	strcpy_s(map[7],  "1000000001");
	strcpy_s(map[8],  "1000000001");
	strcpy_s(map[9],  "1000000001");
	strcpy_s(map[10], "1333333331");
	strcpy_s(map[11], "1222222221");

	player->tPos.x = 1;
	player->tPos.y = 10;
	player->shape = SelectShape(1);
	player->color = SelectColor(1);
	player->heart = 5;
}

void Render(char map[12][11], OOBJECT player)
{
	for (int i = 0; i < 12; i++) 
	{
		for (int j = 0; j < 11; j++) 
		{
			if (player->tPos.x == j && player->tPos.y == i)
			{
				SetColor(player->color, (int)COLOR::BLACK);
				for (int m = 0; m < 8; m++)
				{
					cout << player->shape;
				}
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (map[i][j] == '1')
			{
				cout << "l";
			}
			else if (map[i][j] == '0')
			{
				cout << "  ";
			}
			else if (map[i][j] == '2')
			{
				cout << "ㅡ";
			}
			else if (map[i][j] == '3')	continue;
		}
		cout << endl;
	}

	cout << endl;
	cout << "모양 바꾸는 키 : 오른쪽, 왼쪽 방향키" << endl;
	cout << "색   바꾸는 키 : 위쪽, 아래쪽 방향키" << endl;

	int heart = player->heart;
	cout << "남은 목숨 : ";
	for (int i = 0; i < heart; i++) {
		SetColor((int)COLOR::RED, (int)COLOR::BLACK);
		cout << "♡ ";
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	}
}

void Update(OOBJECT player, char map[12][11])
{
	//PlayerMove(player, map);
	PlayerChangeShape(player);
	PlayerChangeColor(player);
	if (GetAsyncKeyState(VK_F1) & 0x8000)
		player->heart--;

}

bool Check(OOBJECT player, OOBJECT enemy)
{
	if (enemy->tPos.y == 10)
	{
		if (player->color == enemy->color && player->shape == enemy->shape)
		{
			return true;
		}
	}
	player->heart--;
	return false;
}
