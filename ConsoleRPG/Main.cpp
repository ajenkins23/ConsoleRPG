#include "Game.h"

// C:\Users\acer\source\repos\ConsoleRPG\ConsoleRPG

int main() {
	srand(time(NULL));
	
	Game game;
	game.initGame();

	
	while (game.getPlaying()) {
		game.mainMenu();
	}

	return 0;
}