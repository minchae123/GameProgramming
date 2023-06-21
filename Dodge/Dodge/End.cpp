#include "End.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "console.h"
#include <conio.h>

using namespace std;

void DrawEnd(int score)
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTitle(TEXT("Dodge CS"));

	SetColor((int)COLOR::BLUE, (int)COLOR::SKYBLUE);
	wcout << L"	██████╗  ██████╗ ██████╗  ██████╗ ███████╗     ██████╗███████╗	" << endl;
	wcout << L"	██╔══██╗██╔═══██╗██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██╔════╝	" << endl;
	wcout << L"	██║  ██║██║   ██║██║  ██║██║  ███╗█████╗      ██║     ███████╗	" << endl;
	wcout << L"	██║  ██║██║   ██║██║  ██║██║   ██║██╔══╝      ██║     ╚════██║	" << endl;
	wcout << L"	██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗    ╚██████╗███████║	" << endl;
	wcout << L"	╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝     ╚═════╝╚══════╝	" << endl;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	int Curmode = _setmode(_fileno(stdout), prevmode);

	cout << endl;

	cout << "---------------------------------" << endl << endl << endl;
	cout << "     "<<"최종 점수 : "<<score<<"" << endl << endl << endl;
	cout << "---------------------------------" << endl;
}
