#pragma once
#include <vector>
#include <string>
#include "raylib.h"
#include "Constants.h"

class Tileset
{
private:
	Vector2 _chosen_tile_position;
	Vector2 _sprite_start_position;
	Rectangle _dest;
	Rectangle _rendered;
	Texture2D _texture;
	std::string _ground_resource_path = "Terrain\\Ground\\Tilemap_Flat.png";
	int _tiles_wide;
	int _tiles_high;
	int _one_tile_width;
	int _one_tile_height;

public:
	Tileset(int tiles_wide, int tiles_high, int one_tile_width, int one_tile_height);
	~Tileset() = default;
	void Draw();
	void HandleLeftMouseClick(Vector2& mouse_position);
	const Vector2& GetChosenTilePosition();
	Vector2 FindeSelectedCell(Vector2& mouse_position);
	void HighlightCellUnderCursor(Vector2& mouse_position);

private:
	void InitSourse();
};

