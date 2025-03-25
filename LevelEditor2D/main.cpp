#include "raylib.h"
#include <cmath>
#include "LevelGrid.h"
#include "Tileset.h"
#include "Constants.h"


int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LevelEditor2D");

	Tileset tileset(5, 4, 64, 64);
	LevelGrid level_grid(SCREEN_WIDTH, SCREEN_HEIGHT, 22, 16, 0.7);

	SetTargetFPS(120);

	while (!WindowShouldClose())
	{
		//-----------------------------Begin draw--------------------------------------
		BeginDrawing();
		ClearBackground(Color{ 33,33,33,255 });

		Vector2 mouse_position = GetMousePosition();

		if (IsMouseButtonDown(MouseButton::MOUSE_BUTTON_RIGHT)) {
			level_grid.UpdateCell(mouse_position, tileset.GetChosenTilePosition());
		}

		if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT)) {
			tileset.HandleLeftMouseClick(mouse_position);
			level_grid.UpdateCell(mouse_position, tileset.GetChosenTilePosition());
		}

		if ((IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsKeyPressed(KEY_Z)) {
			level_grid.ClearGrid();
		}

		tileset.Draw();
		level_grid.Draw();

		level_grid.HighlightCellUnderCursor(mouse_position);
		tileset.HighlightCellUnderCursor(mouse_position);
		EndDrawing();
		//-----------------------------End draw----------------------------------------
	}

	CloseWindow();

	return 0;
}