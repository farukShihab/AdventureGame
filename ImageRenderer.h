#pragma once
#include "SDL.h"
#include "SDL_image.h"
void renderImage(const char* fileName, SDL_Renderer*& renderer, SDL_Rect* dstRect, SDL_Rect* srcRect);
void renderImageX(const char* fileName, SDL_Renderer*& renderer, SDL_Rect* dstRect, SDL_Rect* srcRect,bool flipped);
