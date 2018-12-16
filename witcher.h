#pragma once

#include "weapon.h"
#include "enemy.h"
#include <memory>
#include "fight.h"

class Fight;

enum class WeaponType 
{
	FISTS,
	STEELSWORD,
	SILVERSWORD
};

class Witcher
{
	int hp;
	int armor;

	bool draconid_oil;
	bool ghost_oil;
	bool necrophage_oil;

	std::unique_ptr<Fists> fists;
	std::unique_ptr<SteelSword> steel_sword;
	std::unique_ptr<SilverSword> silver_sword;

	Weapon* active_weapon;
	std::unique_ptr<Fight> fight_style;

public:
	Witcher();
	void take_damage(int damage);
	void attack(Enemy& enemy) const;
	void set_fight_style(EnemyType id, Enemy* enemy);
	void start_fight();
	void set_weapon(WeaponType type);
	void oil_silver_sword(OilType type);
	bool is_dead() const;
};
