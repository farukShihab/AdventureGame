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
			case SDLK_RIGHT:
				player.increasePlayerX(true);
				break;
			case SDLK_LEFT:
				player.decreasePlayerX(true);
				break;
			case SDLK_UP:
				player.increasePlayerY(true);
				break;
			case SDLK_DOWN:
				player.decreasePlayerY(true);
				break;
			}
			break;
		case SDL_KEYUP:
			switch (e.key.keysym.sym) {
			case SDLK_RIGHT:
				player.increasePlayerX(false);
				break;
			case SDLK_LEFT:
				player.decreasePlayerX(false);
				break;
			case SDLK_UP:
				player.increasePlayerY(false);
				break;
			case SDLK_DOWN:
				player.decreasePlayerY(false);
				break;
			}
			break;
		}
	}
}

void Game::update() {
	player.update();
}