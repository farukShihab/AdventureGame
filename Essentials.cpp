#include "Essentials.hpp"
#include<iostream>

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