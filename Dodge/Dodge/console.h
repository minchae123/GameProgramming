#pragma once
#include <Windows.h>
enum class COLOR {
	BLACK, BLUE, GREEN, SKYBLUE,
	RED, VOILET, YELLO, LIGHT_GRAY,
	GRAY, LIGHT_BLUE, LIGHT_GREEN,
	MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE
};

void FullScreen();
void Gotoxy(int, int);
BOOL GotoxyTest(int, int);
void GotoxyPlayer(int, int);
void CursorSet(bool, DWORD);
void SetColor(int color, int bgcolor);
int GetColor();
int Getbgcolor();
void fontsize(UINT _weight, UINT _sizex, UINT _sizey);