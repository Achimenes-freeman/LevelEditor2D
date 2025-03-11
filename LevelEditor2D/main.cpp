#include "raylib.h"
#include <cmath>
#include "LevelGrid.h"


int main(void) {
	InitWindow(1280, 720, "LevelEditor2D");

	LevelGrid level_grid(40, 22, 12);

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(Color{ 33,33,33,255 });
		level_grid.Draw();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}