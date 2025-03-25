#include "Tileset.h"

Tileset::Tileset(int tiles_wide, int tiles_high, int one_tile_width, int one_tile_height) :
	_tiles_wide(tiles_wide),
	_tiles_high(tiles_high),
	_one_tile_width(one_tile_width),
	_one_tile_height(one_tile_height)
{
	_chosen_tile_position.x = 0;
	_chosen_tile_position.y = 0;

	_rendered.x = 0;
	_rendered.y = 0;
	_rendered.width = _one_tile_width * _tiles_wide;
	_rendered.height = _one_tile_height * _tiles_high;

	_dest.x = 0;
	_dest.y = 0;
	_dest.width = _rendered.width;
	_dest.height = _rendered.height;

	_sprite_start_position.x = _one_tile_width;
	_sprite_start_position.y = 0;

	InitSourse();
}

void Tileset::InitSourse() {
	_texture = LoadTexture((MainResourcePath + _ground_resource_path).c_str());
}

void Tileset::Draw() {
	DrawTexturePro(_texture, _rendered, _dest, { 0,0 }, 0, WHITE);
}

void Tileset::HandleLeftMouseClick(Vector2& mouse_position) {
	_chosen_tile_position = FindeSelectedCell(mouse_position);
}
const Vector2& Tileset::GetChosenTilePosition()
{
	return _chosen_tile_position;
}

Vector2 Tileset::FindeSelectedCell(Vector2& mouse_position) {
	if (mouse_position.x < _dest.x ||
		mouse_position.x >= _dest.width ||
		mouse_position.y < _dest.y ||
		mouse_position.y >= _dest.height) {
		return _chosen_tile_position;
	}

	Vector2 vect = { static_cast<int>(mouse_position.x / (_one_tile_width)), static_cast<int>(mouse_position.y / (_one_tile_height)) };
	return vect;
}

void  Tileset::HighlightCellUnderCursor(Vector2& mouse_position) {

	Vector2 cell_under_cursor = FindeSelectedCell(mouse_position);

	cell_under_cursor.x *= _one_tile_width;
	cell_under_cursor.y *= _one_tile_width;

	DrawRectangleV(cell_under_cursor, { static_cast<float>(_one_tile_width), static_cast<float>(_one_tile_height) }, Color{ 255, 255, 255, 100 });
}