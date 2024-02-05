#include "SDL.h"

class GameSurroundings {
private:
	const char* fileName;
public:
	GameSurroundings();
	~GameSurroundings();
	void showSurroundings(SDL_Renderer* &renderer);
};