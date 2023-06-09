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

void PlayerMove()
{

}
