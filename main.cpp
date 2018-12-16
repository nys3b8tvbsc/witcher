#include "cstdlib"
#include <iostream>
#include <ctime>
#include "game.h"

int main() 
{
	srand(time(0));
	auto g = Game(EnemyType::GHOST, "drac");
	g.start();

	return 0;
}
