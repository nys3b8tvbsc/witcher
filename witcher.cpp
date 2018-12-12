#include "witcher.h"

using std::make_unique;

Witcher::Witcher() {
	
	hp = 200 + rand() % 201;
	armor = 5 + rand() % 21;

	draconid_oil = rand() % 2;
	ghost_oil = rand() % 2;
	necrophage_oil = rand() % 2;
	
	fists = make_unique<Fists>(2 + rand() % 9);
	steel_sword = make_unique<SteelSword>(50 + rand() % 21);
	silver_sword = make_unique<SilverSword>(45 + rand() % 51);
}

void Witcher::take_damage(int damage)
{
	int pure_damage = (damage > this->armor)? damage - this->armor: 0; 
	this->hp -= pure_damage;
	this->hp = (this->hp > 0)? this->hp: 0;
}


//??
void Witcher::attack(Enemy& enemy) const {
	auto weapon = active_weapon.lock();
	weapon->attack(enemy);
}