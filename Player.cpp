#include "Player.hpp"
#include "ImageRenderer.h"
#include<iostream>

Player::Player() {
	initIdleImg();
	initRunImg();
	initMeleeImg();
	initPlayerRect(100, 300, 240, 200);
	initPlayerRect();
	initAttackRect();
	currentImg = idleImg[0];
	currentImgIndex = 0;
	playerState = 1;
	speed = 10;
	setPlayerBorders();
	setFlipped(false);
}
Player::~Player() {}

void Player::initIdleImg() {
	idleImg.resize(10);
	idleImg[0] = "Assets//Images//Player//Idle//1.png";
	idleImg[1] = "Assets//Images//Player//Idle//2.png";
	idleImg[2] = "Assets//Images//Player//Idle//3.png";
	idleImg[3] = "Assets//Images//Player//Idle//4.png";
	idleImg[4] = "Assets//Images//Player//Idle//5.png";
	idleImg[5] = "Assets//Images//Player//Idle//6.png";
	idleImg[6] = "Assets//Images//Player//Idle//7.png";
	idleImg[7] = "Assets//Images//Player//Idle//8.png";
	idleImg[8] = "Assets//Images//Player//Idle//9.png";
	idleImg[9] = "Assets//Images//Player//Idle//10.png";
}

void Player::initRunImg() {
	runImg.resize(8);
	runImg[0] = "Assets//Images//Player//Run//1.png";
	runImg[1] = "Assets//Images//Player//Run//2.png";
	runImg[2] = "Assets//Images//Player//Run//3.png";
	runImg[3] = "Assets//Images//Player//Run//4.png";
	runImg[4] = "Assets//Images//Player//Run//5.png";
	runImg[5] = "Assets//Images//Player//Run//6.png";
	runImg[6] = "Assets//Images//Player//Run//7.png";
	runImg[7] = "Assets//Images//Player//Run//8.png";
}

void Player::initMeleeImg() {
	meleeImg.resize(7);
	meleeImg[0] = "Assets//Images//Player//Melee//1.png";
	meleeImg[1] = "Assets//Images//Player//Melee//2.png";
	meleeImg[2] = "Assets//Images//Player//Melee//3.png";
	meleeImg[3] = "Assets//Images//Player//Melee//4.png";
	meleeImg[4] = "Assets//Images//Player//Melee//5.png";
	meleeImg[5] = "Assets//Images//Player//Melee//6.png";
	meleeImg[6] = "Assets//Images//Player//Melee//7.png";
}

void Player::initPlayerRect(int x, int y, int w, int h) {
	playerRenderRect.x = x;
	playerRenderRect.y = y;
	playerRenderRect.w = w;
	playerRenderRect.h = h;
}


void Player::showPlayer(SDL_Renderer* &renderer) {
	renderImageX(currentImg.c_str(), renderer, &playerRenderRect, NULL,flipped);
	SDL_RenderDrawRect(renderer, &playerRect);
	SDL_RenderDrawRect(renderer, &attackRect);
	
}

void Player::update() {
	switch (playerState) {
	case 1:
		updatePlayerImg(idleImg,5);
		break;
	case 2:
		if(playerState!=3)updatePlayerImg(runImg,2);
		break;
	case 3:
		updatePlayerImg(meleeImg, 3);
		break;
	}
	updatePlayerPosition();
	initPlayerRect();
	initAttackRect();
}


void Player::increasePlayerX(bool flag) {
	increaseX = flag;
	if (flag) {
		if (playerState == 1) {
			playerState = 2;
			currentImgIndex = 0;
		}
	}
	else if(!increaseX && !decreaseX  && !increaseY && !decreaseY && playerState!=3) playerState = 1;
}
void Player::decreasePlayerX(bool flag) {
	decreaseX = flag;
	if (flag) {
		if (playerState == 1) {
			playerState = 2;
			currentImgIndex = 0;
		}
	}
	else if (!increaseX && !decreaseX && !increaseY && !decreaseY && playerState != 3) playerState = 1;
}
void Player::increasePlayerY(bool flag) {
	increaseY = flag;
	if (flag) {
		if (playerState == 1) {
			playerState = 2;
			currentImgIndex = 0;
		}
	}
	else if (!increaseX && !decreaseX && !increaseY && !decreaseY && playerState != 3) playerState = 1;
}
void Player::decreasePlayerY(bool flag) {
	decreaseY = flag;
	if (flag) {
		if (playerState == 1) {
			playerState = 2;
			currentImgIndex = 0;
		}
	}
	else if (!increaseX && !decreaseX && !increaseY && !decreaseY && playerState != 3) playerState = 1;
}

void Player::updatePlayerImg(std::vector<std::string> &currentImgs,int changeRate) {
	currentImg = currentImgs[currentImgIndex];

	if (getFrameNumber() % changeRate == 0)currentImgIndex++;

	
	if (currentImgIndex >= currentImgs.size()) {
		if (playerState == 3 || playerState == 4)
			playerState = 1;
		currentImgIndex = 0;
	}
}

void Player::updatePlayerPosition() {
	if (increaseX)playerRenderRect.x += speed,setFlipped(false);
	if (decreaseX)playerRenderRect.x -= speed,setFlipped(true);
	if (increaseY)playerRenderRect.y -= speed;
	if (decreaseY)playerRenderRect.y += speed;
	if (playerRenderRect.x <= playerBorderLeft)playerRenderRect.x = playerBorderLeft;
	if (playerRenderRect.x + playerRenderRect.w >= playerBorderRight)playerRenderRect.x = playerBorderRight - playerRenderRect.w;
	if (playerRenderRect.y <= playerBorderTop)playerRenderRect.y = playerBorderTop;
	if (playerRenderRect.y + playerRenderRect.h >= playerBorderBottom)playerRenderRect.y = playerBorderBottom - playerRenderRect.h;
}

void Player::setPlayerBorders() {
	playerBorderLeft = 10;
	playerBorderRight = getWindowWidth() - 10;
	playerBorderTop = 130;
	playerBorderBottom = getWindowHeight() - 100;
}

void Player::setFlipped(bool value) {
	flipped = value;
}

void Player::meleeAttack() {
	playerState = 3;
	currentImgIndex = 0;
}

void Player::initPlayerRect() {
	playerRect.x = playerRenderRect.x + 60;
	playerRect.y = playerRenderRect.y+10;
	playerRect.w = playerRenderRect.w - 145;
	playerRect.h = playerRenderRect.h-20;
	if(flipped)
		playerRect.x = playerRect.x + 25;
	if (playerState == 2) {
		playerRect.w = playerRect.w + 15;
		if (flipped)
			playerRect.x = playerRect.x - 15;
	}
}

void Player::initAttackRect() {
	attackRect.x = playerRect.x + playerRect.w;
	attackRect.y = playerRect.y;
	attackRect.w = 55;
	attackRect.h = playerRect.h;
	if (flipped)
		attackRect.x = playerRect.x - 55;
}