#include "SDL.h"
#include "ImageRenderer.h"
#include "Essentials.hpp"

class Enemy {
public:
	Enemy();
	~Enemy();
	void showEnemy(SDL_Renderer* &renderer);
	void move();
	void update();
	void attack();
	void initEnemyRenderRect();
	void initEnemyRect();
	void setEnemyState(int state);
	void setEnemyRenderRectSize(int w,int h);
	void setEnemyRectSize(int w, int h);

	int enemyState;
	int attackState;
	SDL_Rect enemyRenderRect;
	SDL_Rect enemyRect;
	int speed;
	int damage;
	int health;
	int level;
};