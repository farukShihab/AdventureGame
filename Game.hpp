#pragma once
#include "SDL.h"
#include "Game.hpp"
#include "GameSurroundings.h"
#include "Player.hpp"
#include "ImageRenderer.h"

class Game {
public:
	Game();
	~Game();
	void init(int windowWidth, int windowHeight, int windowPosX, int windowPosY, const char* windowTitle);
	void runGame();
	void update();

private:
	bool gameIsRunning;
	SDL_Renderer* renderer;
	SDL_Window* window;
	Player player;
	GameSurroundings gameSurroundings;

	void handleEvent();
};