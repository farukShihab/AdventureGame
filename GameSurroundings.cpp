#include "GameSurroundings.h"
#include "ImageRenderer.h"

GameSurroundings::GameSurroundings() {
	fileName = "Assets//Images//Backgrounds//Game Background - 1.png";
}
GameSurroundings::~GameSurroundings() {}

void GameSurroundings::showSurroundings(SDL_Renderer* &renderer) {
	renderImage(fileName, renderer, NULL, NULL);
}
