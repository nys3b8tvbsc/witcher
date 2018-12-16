#include "enemy.h"
#include "witcher.h"

using std::string_view;

void Enemy::take_damage(int damage)
{
	int pure_damage = (damage > this->armor)? damage - this->armor: 0; 
	this->hp -= pure_damage;
	this->hp = (this->hp > 0)? this->hp: 0;
}

void Enemy::attack(Witcher& witcher) const
{
	witcher.take_damage(this->damage);	
}

bool Enemy::is_dead() const
{
	return this->hp == 0;
}

string_view Enemy::get_name() const
{
	return this->name;
}
