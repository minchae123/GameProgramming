#include "GameLogic.h"
using namespace std;

void SetEnemy(OOBJECT enemy, char map[12][11])
{
	int sr = rand() % 4;
	int cr = rand() % 4;

	enemy->color = SelectColor(cr);
	enemy->shape = SelectShape(sr);

	enemy->tPos.x = 1;
	enemy->tPos.y = 1;

	for (int m = 0; m < 8; m++)
	{
		map[0][m + 1] = '2';
		map[9][m + 1] = '0';
	}
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

void PlayerChangeShape(OOBJECT object)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001) 
	{
		object->indexS++;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
		object->indexS--;
	}
	if (object->indexS > 3) {
		object->indexS = 0;
	}
	else if (object->indexS < 0)
	{
		object->indexS = 3;
	}

	object->shape = SelectShape(object->indexS);
}

void PlayerChangeColor(OOBJECT object)
{
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		object->indexC++;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
		object->indexC--;
	}

	if (object->indexC > 3) {
		object->indexC = 0;
	}
	else if(object->indexC < 0)
	{
		object->indexC = 3;
	}
	object->color = SelectColor(object->indexC);
}

void Map(char map[12][11], OOBJECT player, OOBJECT enemy)
{
	system("mode con cols=80 lines=27");
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_THICKFRAME);

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
	player->shape = SelectShape(0);
	player->color = SelectColor(0);
	player->heart = 6;

	enemy->tPos.x = 1;
	enemy->tPos.y = 1;
	enemy->shape = SelectShape(1);
	enemy->color = SelectColor(1);
}

void Render(char map[12][11], OOBJECT player, OOBJECT enemy)
{
	system("cls");
	for (int i = 0; i < 12; i++) 
	{
		for (int j = 0; j < 10; j++) 
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
			if (enemy->tPos.x == j && enemy->tPos.y == i)
			{
				SetColor(enemy->color, (int)COLOR::BLACK);
				for (int m = 1; m < 9; m++)		
				{
					cout << enemy->shape;
					if (m >= 1 && m <= 8)
						map[i - 1][m] = '0';
				}
				j = 8;
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			}
			else if (map[i][j] == '1') // 옆 벽
			{
				cout << "l";
				if(j == 10)
					Gotoxy(i, 10);
			}
			else if (map[i][j] == '0') // 빈공간
			{
				cout << "  ";
			}
			else if (map[i][j] == '2') // 맨 위 아래 줄
			{
				cout << "ㅡ";
			}
			else if (map[i][j] == '3') // 플레이어나 적이 있는 위치
			{
				continue;
			}
			
		}
		cout << endl;
	}

	cout << endl;
	cout << "모양 바꾸는 키 : 오른쪽, 왼쪽 방향키" << endl;
	cout << "클로버 ♣ / 하트 ♥ / 별 ★ / 다이아몬드 ◈" << endl;
	cout << "색   바꾸는 키 : 위쪽, 아래쪽 방향키" << endl;
	SetColor((int)COLOR::LIGHT_GREEN, (int)COLOR::BLACK);
	cout << "연두 ";
	SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLACK);
	cout << "파랑 ";
	SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
	cout << "노랑 ";
	SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::BLACK);
	cout << "보라 " << endl;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	cout << "다운 버튼 : 스페이스 바" << endl;

	Heart(player);
	cout << "         ";
	cout << endl;
	cout << "현재 점수 :  " << player->score;
}

void Update(OOBJECT player, char map[12][11], OOBJECT enemy)
{
	SetConsoleTitle(TEXT("Dodge CS"));

	Skip(enemy, player);
	EnemyMove(map, enemy, player);

	if (enemy->tPos.y == 10)
	{
		if (Check(player, enemy))
		{
			player->score += 100;
			Beep(698.46f, 200);
		}
		else
		{
			player->heart--;
			Beep(932.33f, 200);
		}
		SetEnemy(enemy, map);
	}

	for (int m = 0; m < 8; m++)
	{
		map[0][m + 1] = '2';
	}

	if (player->score > 500) // 이부분은 그냥 전부 일일이 설정해주었습니다 ,,
	{
		player->time = 900;
	}
	else if (player->score > 1000)
	{
		player->time = 800;
	}
	else if(player->score > 1500)
	{
		player->time = 700;
	}
	else if (player->score > 2000)
	{
		player->time = 600;
	}
	else if (player->score > 2500)
	{
		player->time = 500;
	}
	else if(player->score > 3000)
	{
		player->time = 300;
	}
	else if (player->score > 4000)
	{
		player->time = 200;
	}
}

bool Check(OOBJECT player, OOBJECT enemy)
{
	if (player->color == enemy->color && player->shape == enemy->shape)
	{
		return true;
	}
	return false;
}

void EnemyMove(char map[12][11], OOBJECT enemy, OOBJECT player)
{
	clock_t oldtime, curtime;
	oldtime = clock();

	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > player->time)
		{
			curtime = oldtime;
			enemy->tPos.y++;
			break;
		}
		else
			continue;
	}
}

void Heart(OOBJECT player)
{
	int heart = player->heart;
	cout << "남은 목숨 : ";
	for (int i = 0; i < heart; i++) {
		SetColor((int)COLOR::RED, (int)COLOR::BLACK);
		cout << "♥ ";
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	}
}

void Skip(OOBJECT enemy, OOBJECT player)
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		enemy->tPos.y = 9;
		if (enemy->shape == player->shape)
		{
			player->score += 150;
		}
	}
}

MCI_OPEN_PARMS openBgm; //여는거
MCI_PLAY_PARMS playBgm; //재생용
UINT Bgmid;

void PlayBgm()
{
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	openBgm.lpstrElementName = TEXT("BGM.mp3");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD_PTR)&openBgm);
	openBgm.wDeviceID;
	Bgmid = openBgm.wDeviceID;
	mciSendCommand(Bgmid, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&openBgm);
}
