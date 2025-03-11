#include "raylib.h"
#include <cmath>
#include "LevelGrid.h"
#include "Constants.h"


int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LevelEditor2D");

	LevelGrid level_grid(SCREEN_WIDTH, SCREEN_HEIGHT, 22, 12, 0.7);

	SetTargetFPS(120);

	while (!WindowShouldClose())
	{
		//-----------------------------Begin draw--------------------------------------
		BeginDrawing();
		ClearBackground(Color{ 33,33,33,255 });

		if (IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT)) {
			Vector2 mouse_position = GetMousePosition();
			level_grid.UpdateCell(mouse_position);
		}

		if (IsKeyDown(KEY_Z) && (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))) {
			level_grid.ClearGrid();
		}

		level_grid.Draw();
		EndDrawing();
		//-----------------------------End draw----------------------------------------
	}

	CloseWindow();

	return 0;
}