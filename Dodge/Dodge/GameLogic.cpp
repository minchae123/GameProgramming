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
		return "¢À";
	}
	else if (n == (int)Shape::Diamond)
	{
		return "¢Â";
	}
	else if (n == (int)Shape::Star)
	{
		return "¡Ú";
	}
	else if (n == (int)Shape::Heart)
	{
		return "¢¾";
	}
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
}

void PlayerMove(OOBJECT object, char map[12][10])
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		--object->tPos.x;
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		++object->tPos.x;
		Sleep(100);
	}
}

void PlayerChange(OOBJECT object)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) 
	{
		object->index++;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		object->index--;
	}
	object->index = std::clamp(object->index, 0, 3);

	object->shape = SelectShape(object->index);
	object->color = SelectColor(object->index);
}

void Map(char map[12][10]) 
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
	strcpy_s(map[10], "1000000001");
	strcpy_s(map[11], "1222222221");
}

void Render(char map[12][10], OOBJECT player)
{
	for (int i = 0; i < 12; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			if (player->tPos.x == j && player->tPos.y == i) 
			{
				SetColor((int)COLOR::BLUE, (int)COLOR::SKYBLUE);
				cout << player->shape;
				SetColor(player->color, (int)COLOR::BLACK);
			}
		}
	}
}

void Update(OOBJECT player, char map[12][10])
{
	PlayerMove(player, map);
	PlayerChange(player);
}
