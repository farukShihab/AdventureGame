#include "ImageRenderer.h"
#include<iostream>

void renderImage(const static char* fileName, static SDL_Renderer*& renderer, static SDL_Rect* dstRect, static SDL_Rect* srcRect) {
	SDL_Surface* surface;
	SDL_Texture* texture;
	surface = IMG_Load(fileName);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, srcRect, dstRect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void renderImageX(const static char* fileName, static SDL_Renderer*& renderer, static SDL_Rect* dstRect, static SDL_Rect* srcRect,bool flipped) {
	SDL_Surface* surface;
	SDL_Texture* texture;
	surface = IMG_Load(fileName);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(!flipped)SDL_RenderCopy(renderer, texture, srcRect, dstRect);
	else SDL_RenderCopyEx(renderer, texture, srcRect, dstRect, 0, NULL,SDL_FLIP_HORIZONTAL);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void updateFrameNumber() {
	frameNumber++;
	if (frameNumber == INT_MAX)frameNumber = 0;
}

int getFrameNumber() {
	return frameNumber;
}

int getWindowWidth() {
	return windowWidth;
}

int getWindowHeight() {
	return windowHeight;
}