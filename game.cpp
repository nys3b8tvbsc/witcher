#include "game.h"

using std::make_unique;

Game::Game(EnemyType id, std::string_view enemy_name):
	id(id) 
{
	witcher = make_unique<Witcher>();
	switch(id) {
		case EnemyType::DRACONID:
			enemy = make_unique<Draconid>(enemy_name);
			break;
		case EnemyType::GHOST:
			enemy = make_unique<Ghost>(enemy_name);
			break;
		case EnemyType::NECROPHAGE:
			enemy = make_unique<Necrophage>(enemy_name);
			break;
		case EnemyType::HUMAN:
			enemy = make_unique<Human>(enemy_name);
			break;
		case EnemyType::ROGUE:
			enemy = make_unique<Rogue>(enemy_name);
			break;
	}
}

void Game::start()
{
	witcher->set_fight_style(id, enemy.get());
	witcher->start_fight();
}
