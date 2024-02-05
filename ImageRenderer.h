#pragma once
#include "SDL.h"
#include "SDL_image.h"
void renderImage(const char* fileName, SDL_Renderer*& renderer, SDL_Rect* dstRect, SDL_Rect* srcRect);
void renderImageX(const char* fileName, SDL_Renderer*& renderer, SDL_Rect* dstRect, SDL_Rect* srcRect,bool flipped);
static int frameNumber=0;
void updateFrameNumber();
int getFrameNumber();
static int windowWidth = 1000;
static int windowHeight = 700;
int getWindowWidth();
int getWindowHeight();