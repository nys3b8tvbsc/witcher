#pragma once

#include "witcher.h"
#include "enemy.h"
#include <memory>

class Game
{
	std::unique_ptr<Witcher> witcher;

	EnemyType id;
	std::unique_ptr<Enemy> enemy;

public:
	Game(EnemyType id, std::string_view enemy_name);
	void start();
};
