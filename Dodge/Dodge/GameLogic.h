#pragma once
#include <iostream>
#include <string>
#include "console.h"

enum class Shape
{
	Clover,
	Diamond,
	Star,
	Heart
};

void SetEnemy();
std::string SelectShape(int n);
int SelectColor(int n);
void PlayerMove();