#include "Game.h"

// C:\Users\acer\source\repos\ConsoleRPG\ConsoleRPG
// cd source/repos/ConsoleRPG/


int main() {
	srand(time(NULL));
	
	Game game;
	game.initGame();

	
	while (game.getPlaying()) {
		game.mainMenu();
	}

	return 0;
}