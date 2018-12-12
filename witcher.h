#pragma once

#include "weapon.h"
#include "enemy.h"
#include <memory>

class Witcher //??
{
	int hp;
	int armor;

	bool draconid_oil;
	bool ghost_oil;
	bool necrophage_oil;

	std::unique_ptr<Fists> fists;
	std::unique_ptr<SteelSword> steel_sword;
	std::unique_ptr<SilverSword> silver_sword;

	std::weak_ptr<Weapon> active_weapon; //??

public:
	Witcher();

	void take_damage(int damage);
	void attack(Enemy& enemy) const; //??
};