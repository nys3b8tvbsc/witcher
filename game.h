#pragma once

#include "witcher.h"
#include "enemy.h"
#include <memory>

class Game
{
// fight pointer;
	std::unique_ptr<Fight> fight;  // TODO nullptr
	std::unique_ptr<Witcher> witcher;
	std::unique_ptr<Enemy> enemy;

public:
	Game();
	void start();
	void set_fight(); //?? TODO
};