#include "cstdlib"
#include <iostream>
#include <ctime>
#include "game.h"

int main() 
{
	srand(time(0));
	Game(EnemyType::DRACONID, "drac");

	return 0;
}
