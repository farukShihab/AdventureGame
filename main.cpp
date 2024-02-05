#include "Game.hpp"


int main(int argc,char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	
	Game game;

	int windowWidth = 1000;
	int windowHeight = 700;
	game.init(getWindowWidth(), getWindowHeight(), 50, 50, "Adventure Game");
	game.runGame();



	return 0;
}