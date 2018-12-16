#pragma once

#include "witcher.h"
#include "enemy.h"
#include <memory>

class Fight
{
protected:
	Witcher* witcher;
	Enemy* enemy;

public:
	Fight(Witcher* witcher, Enemy* enemy);
	virtual void start_fight() = 0;
	virtual ~Fight() = default;	
};

struct MonsterFight: Fight
{
	MonsterFight(Witcher* witcher, Enemy* enemy):
	Fight(witcher, enemy)
	{}
};

struct DraconidFight: MonsterFight
{
	DraconidFight(Witcher* witcher, Enemy* enemy):
	MonsterFight(witcher, enemy)
	{}

	void start_fight() override;	
};

struct GhostFight: MonsterFight
{
	GhostFight(Witcher* witcher, Enemy* enemy):
	MonsterFight(witcher, enemy)
	{}

	void start_fight() override;
};

struct NecrophageFight: MonsterFight
{
	NecrophageFight(Witcher* witcher, Enemy* enemy):
	MonsterFight(witcher, enemy)
	{}

	void start_fight() override;
};

struct HumanFight: Fight
{
	HumanFight(Witcher* witcher, Enemy* enemy):
	Fight(witcher, enemy)
	{}

	void start_fight() override;
};

struct RogueFight: HumanFight
{
	RogueFight(Witcher* witcher, Enemy* enemy):
	HumanFight(witcher, enemy)
	{}

	void start_fight() override;
};
