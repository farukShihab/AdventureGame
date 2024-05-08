#include "Game.hpp"
#include<iostream>


Game::Game() {
	
}
Game::~Game() {}

void Game::init(int windowWidth,int windowHeight,int windowPosX,int windowPosY,const char* windowTitle) {
	gameIsRunning = true;
	this->window = SDL_CreateWindow(windowTitle, windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	//this->window = SDL_CreateWindow(windowTitle, windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_FULLSCREEN);
	this->renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

	
}

void Game::runGame() {
	int FPS = 120;
	int framerate = 1000 / FPS;
	Uint64 a, b;
	while (gameIsRunning) {
		a = SDL_GetTicks();
		updateFrameNumber();

		handleEvent();
		SDL_RenderClear(renderer);

		gameSurroundings.showSurroundings(renderer);
		player.showPlayer(renderer);
		update();

		//SDL_SetRenderDrawColor(renderer,0, 0, 0, 0);
		SDL_RenderPresent(renderer);

		b = SDL_GetTicks();
		Uint64 delay = b - a;
		if (delay > framerate)SDL_Delay(delay - framerate);
	}
}

void Game::handleEvent() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			gameIsRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_ESCAPE:
				gameIsRunning = false;
				break;
			case SDLK_d:
				player.increasePlayerX(true);
				break;
			case SDLK_a:
				player.decreasePlayerX(true);
				break;
			case SDLK_w:
				player.increasePlayerY(true);
				break;
			case SDLK_s:
				player.decreasePlayerY(true);
				break;
			}
			break;
		case SDL_KEYUP:
			switch (e.key.keysym.sym) {
			case SDLK_d:
				player.increasePlayerX(false);
				break;
			case SDLK_a:
				player.decreasePlayerX(false);
				break;
			case SDLK_w:
				player.increasePlayerY(false);
				break;
			case SDLK_s:
				player.decreasePlayerY(false);
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			std::cout << e.button.x << ' ' << e.button.y << std::endl;
			switch (e.button.button) {
			case SDL_BUTTON_LEFT:
				std::cout << "MOUSE LEFT CLICKED" << '\n';
				player.meleeAttack();
				break;
			case SDL_BUTTON_RIGHT:
				std::cout << "MOUSE RIGHT CLICKED" << '\n';
				break;
			}
			break;
		}
	}
}

void Game::update() {
	player.update();
}