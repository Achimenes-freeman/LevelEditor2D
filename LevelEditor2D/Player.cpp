#include "Player.h"

Player::Player() {
	InitSourse();
}

void Player::InitSourse() {
	runningPlant = LoadTexture("../assets/Tileset/AllTiles.png");
}

void Player::Draw() {
	DrawTexturePro(runningPlant, texture, dest, { 0, 0 }, 0, WHITE);
}

void Player::UpdateTexture(int currentFrame) {
	texture.x = 16 + abs(currentFrame * texture.width) + abs(texture.width * 4);
}

void Player::Update() {
	frameCount++;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_LEFT)) {

		if (frameCount >= (60 / frameSpeed)) {

			frameCount = 0;

			currentFrame++;

			if (currentFrame > 3) currentFrame = 0;
				UpdateTexture(currentFrame);

		}

		if (IsKeyDown(KEY_RIGHT)) {
			dest.x += 5;
			if (texture.width < 0) {
				texture.width *= -1;
			}
		}

		if (IsKeyDown(KEY_DOWN)) {
			dest.y += 5;
		}
		if (IsKeyDown(KEY_UP)) {
			dest.y -= 5;
		}
		if (IsKeyDown(KEY_LEFT)) {
			if (texture.width > 0) {
				texture.width *= -1;
			}
			dest.x -= 5;
		}

	}
	else {

		if (frameCount >= (60 / frameSpeed)) {

			frameCount = 0;

			currentFrame++;

			if (currentFrame > 3) currentFrame = 0;

			texture.x = 16 + abs(currentFrame * texture.width);

		}

	}
}