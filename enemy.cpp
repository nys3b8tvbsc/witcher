#include "enemy.h"
#include "witcher.h"
#include <iostream>

using std::string_view, std::cout, std::endl;

void Enemy::take_damage(int damage)
{
	int pure_damage = (damage > this->armor)? damage - this->armor: 0; 
	this->hp -= pure_damage;
	this->hp = (this->hp > 0)? this->hp: 0;
}

void Enemy::attack(Witcher& witcher) const
{
	cout << this->get_name() << " атакует ведьмака с силой = "<< this->damage << endl;
	witcher.take_damage(this->damage);
}

bool Enemy::is_dead() const
{
	if (this->hp == 0)
		cout << this->get_name() << " мертв" << endl;
	return this->hp == 0;
}

string_view Enemy::get_name() const
{
	return this->name;
}
