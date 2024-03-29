#pragma once
#include "SDL.h"
#include<string>
#include<vector>

class Player {
private:
	int speed;
	SDL_Rect playerRect;
	std::string currentImg;
	int currentImgIndex;


	int playerBorderLeft;
	int playerBorderRight;
	int playerBorderTop;
	int playerBorderBottom;
	void setPlayerBorders();

	std::vector<std::string> idleImg;
	std::vector<std::string> runImg;
	void initIdleImg();
	void initRunImg();

	int playerState;

	void initPlayerRect(int x,int y,int w,int h);

	bool increaseX = false;
	bool decreaseX = false;
	bool increaseY = false;
	bool decreaseY = false;

	void updateIdleImg();
	void updatePlayerImg(std::vector<std::string> &currentImgs,int changeRate);
	void updatePlayerPosition();

	bool flipped;
	void setFlipped(bool value);

	void controlMovement(bool flag, int direction);

	
public:
	Player();
	~Player();
	void showPlayer(SDL_Renderer* &renderer);
	void update();
	void increasePlayerX(bool flag);
	void decreasePlayerX(bool flag);
	void increasePlayerY(bool flag);
	void decreasePlayerY(bool flag);
};