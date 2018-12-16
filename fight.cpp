#include "fight.h"

Fight::Fight(Witcher* witcher, Enemy* enemy):
	witcher(witcher),
	enemy(enemy)
{}

void DraconidFight::start_fight()
{
	witcher->set_weapon(WeaponType::SILVERSWORD);
	witcher->oil_silver_sword(OilType::DRACONID);
	while(not witcher->is_dead() and not enemy->is_dead()) {
		witcher->attack(*enemy);
		enemy->attack(*witcher);
	}
}

void GhostFight::start_fight()
{
	witcher->set_weapon(WeaponType::SILVERSWORD);
	witcher->oil_silver_sword(OilType::GHOST);
	while(not witcher->is_dead() and not enemy->is_dead()) {
		witcher->attack(*enemy);
		enemy->attack(*witcher);
	}
}

void NecrophageFight::start_fight()
{
	witcher->set_weapon(WeaponType::SILVERSWORD);
	witcher->oil_silver_sword(OilType::NECROPHAGE);
	while(not witcher->is_dead() and not enemy->is_dead()) {
		witcher->attack(*enemy);
		enemy->attack(*witcher);
	}
}

void HumanFight::start_fight()
{	
	witcher->set_weapon(WeaponType::FISTS);
	while(not witcher->is_dead() and not enemy->is_dead()) {
		enemy->attack(*witcher);
		witcher->attack(*enemy);
	}
}

void RogueFight::start_fight()
{
	witcher->set_weapon(WeaponType::STEELSWORD);
	while(not witcher->is_dead() and not enemy->is_dead()) {
		enemy->attack(*witcher);
		witcher->attack(*enemy);
	}
}
