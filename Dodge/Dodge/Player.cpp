#include "Player.h"

using namespace std;
Player::Player(): m_tPos{0,0}, color{15}, shape{"¢À"}, index{0}
{

}

Player::~Player()
{
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--m_tPos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++m_tPos.x;
}

void Player::SetCS()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		index++;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		index--;
	}
	index = std::clamp(index, 0, 3);

	shape = SelectShape(index);
	color = SelectColor(index);
}
