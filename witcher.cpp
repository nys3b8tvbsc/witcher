#include "witcher.h"

using std::make_unique;

Witcher::Witcher()
{
	hp = 200 + rand() % 201;
	armor = 5 + rand() % 21;

	draconid_oil = rand() % 2;
	ghost_oil = rand() % 2;
	necrophage_oil = rand() % 2;
	
	fists = make_unique<Fists>(2 + rand() % 9);
	steel_sword = make_unique<SteelSword>(50 + rand() % 21);
	silver_sword = make_unique<SilverSword>(45 + rand() % 51);

	active_weapon = nullptr;
}

void Witcher::take_damage(int damage)
{
	int pure_damage = (damage > this->armor)? damage - this->armor: 0; 
	this->hp -= pure_damage;
	this->hp = (this->hp > 0)? this->hp: 0;
}

void Witcher::attack(Enemy& enemy) const
{
	cout << "Ведьмак атакует" << endl;	
	active_weapon->attack(enemy);
}

void Witcher::set_fight_style(EnemyType id, Enemy* enemy)
{
	switch(id) {
		case EnemyType::DRACONID:
			fight_style = make_unique<DraconidFight>(this, enemy);
			break;
		case EnemyType::GHOST:
			fight_style = make_unique<GhostFight>(this, enemy);
			break;
		case EnemyType::NECROPHAGE:
			fight_style = make_unique<NecrophageFight>(this, enemy);
			break;
		case EnemyType::HUMAN:
			fight_style = make_unique<HumanFight>(this, enemy);
			break;
		case EnemyType::ROGUE:
			fight_style = make_unique<RogueFight>(this, enemy);
			break;
	}
}

void Witcher::start_fight()
{
	this->fight_style->start_fight();
}

void Witcher::set_weapon(WeaponType type)
{
	switch(type) {
		case WeaponType::FISTS:
			active_weapon = fists.get();
			break;
		case WeaponType::STEELSWORD:
			active_weapon = steel_sword.get();
			break;
		case WeaponType::SILVERSWORD:
			active_weapon = silver_sword.get();
			break;
	}
}

void Witcher::oil_silver_sword(OilType type)
{
	switch(type) {
		case OilType::DRACONID:
			if (draconid_oil) {
				draconid_oil = false;
				this->silver_sword->oil(type);
				cout << "Намазал масло от драконидов" << endl;
			}
			else{
				this->silver_sword->oil(OilType::NONE);
				cout << "Нет масла от драконидов" << endl;
			}
			break;

		case OilType::GHOST:
			if (ghost_oil) {
				ghost_oil = false;
				this->silver_sword->oil(type);
				cout << "Намазал масло от призраков" << endl;
			}
			else {
				this->silver_sword->oil(OilType::NONE);
				cout << "Нет масла от призраков" << endl;
			}
			break;

		case OilType::NECROPHAGE:
			if (necrophage_oil) {
				necrophage_oil = false;
				this->silver_sword->oil(type);
				cout << "Намазал масло от трупоедов" << endl;
			}
			else {
				this->silver_sword->oil(OilType::NONE);
				cout << "Нет масла от трупоедов" << endl;
			}
			break;
	}
}

bool Witcher::is_dead() const
{
	if (hp == 0)
		cout << "Ведьмак умер" << endl;
	return hp == 0;
}