#pragma once

#include <cstdlib>
#include "enemy.h"

class Weapon
{
protected:
	int damage;

	Weapon(int damage): damage(damage) 
	{}

public:
	virtual void attack(Enemy& enemy) const = 0;
};

struct Fists: Weapon
{
	Fists(int damage): Weapon(damage) 
	{}

	void attack(Enemy& enemy) const override {
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

	void attack(Enemy& enemy) const override {
		enemy.take_damage(this->damage);
	}
};

struct SilverSword: Sword
{
private:
	mutable int oiled = 0;

public:
	void oil() { oiled = 10; }

	SilverSword(int damage): Sword(damage)
	{}

	void attack(Enemy& enemy) const override {
		int damage;
		if(oiled) {
			damage = 1.5 * this->damage;
			--oiled;
		} else {
			damage = this->damage;;	
		} 
		enemy.take_damage(damage);
	}
};