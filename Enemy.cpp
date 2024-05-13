#include "Enemy.hpp"

Enemy::Enemy() {

}

Enemy::Enemy(int speed) {
	this->speed = speed;
	enemyState = 1;
	isFlipped = false;
}

Enemy::~Enemy() {}

void Enemy::showEnemy(SDL_Renderer* &renderer) {
	renderImageX(currentImg.c_str(),renderer, &enemyRenderRect, NULL, isFlipped);
}

void Enemy::update() {

}

void Enemy::attack() {

}

void Enemy::initEnemyRect(int x,int y,int w,int h) {
	enemyRect.x = x;
	enemyRect.y = y;
	enemyRect.w = w;
	enemyRect.h = h;
}

void Enemy::initEnemyRenderRect(int x, int y, int w, int h) {
	enemyRenderRect.x = x;
	enemyRenderRect.y = y;
	enemyRenderRect.w = w;
	enemyRenderRect.h = h;
}

void Enemy::initRunImgs(std::vector<std::string> vectSt) {
	runImgs = vectSt;
}
