#pragma once;
#include "SDL.h"
#include "ImageRenderer.h"
#include "Essentials.hpp"
#include<iostream>
#include<vector>
#include<string>

class Enemy {
public:
	Enemy();
	Enemy(int speed);
	~Enemy();
	void showEnemy(SDL_Renderer* &renderer);
	void move();
	void update();
	void attack();
	void initEnemyRenderRect(int x, int y, int w, int h);
	void initEnemyRect(int x, int y, int w, int h);
	void setEnemyState(int state);
	void setEnemyRenderRectSize(int w,int h);
	void setEnemyRectSize(int w, int h);
	bool checkCollision(SDL_Rect playerRect);

	int enemyState;
	int attackState;
	SDL_Rect enemyRenderRect;
	SDL_Rect enemyRect;
	int speed;
	int damage;
	int health;
	int level;
	std::string currentImg;
	std::vector<std::string> idleImgs;
	std::vector<std::string> runImgs;
	std::vector<std::string> attackImgs;
	bool isFlipped;

	void initRunImgs(std::vector<std::string> vectSt);
};