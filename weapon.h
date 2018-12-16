#pragma once

#include <cstdlib>
#include "enemy.h"
#include <iostream>

using std::cout, std::endl;

enum class OilType
{
	DRACONID,
	GHOST,
	NECROPHAGE,
	NONE
};

class Weapon
{
protected:
	int damage;

	Weapon(int damage): damage(damage) 
	{}

public:
	virtual void attack(Enemy& enemy) const = 0;
	virtual ~Weapon() = default;
};

struct Fists: Weapon
{
	Fists(int damage): Weapon(damage) 
	{}

	void attack(Enemy& enemy) const override 
	{
		cout << "Кулак нанес " << this->damage << " урона " << endl;
		enemy.take_damage(this->damage);
	}
};

struct Sword: Weapon
{
	Sword(int damage): Weapon(damage) 
	{}
};

struct SteelSword: Sword
{
	SteelSword(int damage): Sword(damage)
	{}

	void attack(Enemy& enemy) const override
	{
		cout << "Стальной меч нанес " << this->damage << " урона" << endl;
		enemy.take_damage(this->damage);
	}
};

struct SilverSword: Sword
{
private:
	mutable int oiled_draconid = 0;
	mutable int oiled_ghost = 0;
	mutable int oiled_necrophage = 0;

public:
	SilverSword(int damage): Sword(damage)
	{}

	void oil(OilType type)
	{
		switch(type) {
			case OilType::DRACONID:
				oiled_draconid = 10;
				oiled_ghost = 0;
				oiled_necrophage = 0;
				break;
			case OilType::GHOST:
				oiled_draconid = 0;
				oiled_ghost = 10;
				oiled_necrophage = 0;
				break;
			case OilType::NECROPHAGE:
				oiled_draconid = 0;
				oiled_ghost = 0;
				oiled_necrophage = 10;
				break;
			case OilType::NONE:
				oiled_draconid = 0;
				oiled_ghost = 0;
				oiled_necrophage = 0;
				break;
		}
	}

	void attack(Enemy& enemy) const override
	{
		int damage;
		if(oiled_draconid) {
			damage = 1.5 * this->damage;
			--oiled_draconid;
		} else if(oiled_ghost) {
			damage = 1.5 * this->damage;
			--oiled_ghost;
		} else if(oiled_necrophage) {
			damage = 1.5 * this->damage;
			--oiled_necrophage;
		} else {
			damage = this->damage;;	
		}

		cout << "Серебряный меч " << damage << " урона" << endl; 
		enemy.take_damage(damage);
	}
};
