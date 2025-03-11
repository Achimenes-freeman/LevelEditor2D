#pragma once
#include <cmath>
#include "raylib.h"

class Player {
public:
	Rectangle texture = { 16,336, 32, 34 };
	Rectangle dest = { 0, 0, texture.width * 4, texture.height * 4 };
	Texture2D runningPlant;

	int frameCount = 0;
	int currentFrame = 1;

	int frameSpeed = 10;

public:
	Player();
	void UpdateTexture(int currentFrame);
	void Update();
	void Draw();
private:

	void InitSourse();


};
