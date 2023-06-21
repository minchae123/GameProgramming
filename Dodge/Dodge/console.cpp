#include "console.h"

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
void FullScreen()
{
	SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, NULL);
}

void Gotoxy(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(hOut, Cur);
}

BOOL GotoxyTest(int x, int y)
{
	COORD Cur = { x, y };
	return SetConsoleCursorPosition(hOut, Cur);
}

void GotoxyPlayer(int x, int y)
{
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(hOut, Cur);
}

void CursorSet(bool _bVis, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = _bVis;
	info.dwSize = _dwSize;
	SetConsoleCursorInfo(hOut, &info);
}

void SetColor(int color, int bgcolor)
{
	SetConsoleTextAttribute(hOut, (bgcolor << 4) | color);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

int Getbgcolor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	int color = (info.wAttributes & 0xf) >> 4;
	return color;
}

void fontsize(UINT _weight, UINT _sizex, UINT _sizey)
{
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizex;
	font.dwFontSize.Y = _sizey;
	SetCurrentConsoleFontEx(hout, false, &font);
}
