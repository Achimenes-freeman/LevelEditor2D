#include "LevelGrid.h"
#include <iostream>

LevelGrid::LevelGrid(const float screen_width, const float screen_height, const int columns_qty, const int rows_qty, float relative_width) :
	_relative_width(relative_width),
	_columns_qty(columns_qty),
	_rows_qty(rows_qty)
{
	InitSourse();

	_rendered.width = 64;
	_rendered.height = 64;

	_cell_size = CalcMaxCellWidth(screen_width, screen_height);
	_dest.width = _dest.height = _cell_size;
	_grid.resize(columns_qty * rows_qty);
	InitGrid();

	_indent.x = screen_width - _columns_qty * _cell_size;
	_indent.y = (screen_height - _rows_qty * _cell_size) / 2;
}

void LevelGrid::InitSourse() {
	_tileset = LoadTexture((MainResourcePath + _ground_resource_path).c_str());
}

void LevelGrid::InitGrid() {
	for (auto& cell : _grid) {
		cell.x = -1;
		cell.y = -1;
	}
}

void LevelGrid::DrawGridLayout() {
	float start_y = _indent.y;
	float end_y = _indent.y + _rows_qty * _cell_size;

	float start_x = _indent.x;
	float end_x = start_x + _columns_qty * _cell_size;
	Color side_color = Color{ 60, 40, 40, 255 };

	for (int i = 0; i <= _columns_qty; i++) {
		DrawLineEx({ _indent.x + _cell_size * i, start_y }, { _indent.x + _cell_size * i, end_y }, 3, side_color);
	}

	for (int i = 0; i <= _rows_qty; i++) {
		DrawLineEx({ start_x, start_y + _cell_size * i }, { end_x, start_y + _cell_size * i }, 3, side_color);
	}
}

void LevelGrid::Draw() {

	DrawGridLayout();

	for (int i = _grid.size() - 1; i >= 0; i--) {

		_dest.x = _indent.x + (i % _columns_qty) * _cell_size;
		_dest.y = _indent.y + (i / _columns_qty) * _cell_size;

		_rendered.x = _grid[i].x;
		_rendered.y = _grid[i].y;

		if (_rendered.x >= 0 && _rendered.y >= 0) {
			DrawTexturePro(_tileset, _rendered, _dest, { 0,0 }, 0, Color{ 255, 255, 255, 255 });
		}
	}
}

int LevelGrid::FindeSelectedCell(Vector2& mouse_position) {
	if (mouse_position.x < _indent.x ||
		mouse_position.x >= _indent.x + _columns_qty * _cell_size ||
		mouse_position.y < _indent.y ||
		mouse_position.y >= _indent.y + _rows_qty * _cell_size) {
		return -1;
	}

	int row = (mouse_position.y - _indent.y) / _cell_size;
	int column = (mouse_position.x - _indent.x) / _cell_size;
	return row * _columns_qty + column;
}

void LevelGrid::UpdateCell(Vector2& mouse_position, const Vector2& chosen_cell) {
	int cell_index = FindeSelectedCell(mouse_position);

	if (cell_index >= 0) {
		_grid[cell_index].x = chosen_cell.x * 64;
		_grid[cell_index].y = chosen_cell.y * 64;
	}

}

float LevelGrid::CalcMaxCellWidth(float screen_width, float screen_height) {
	float max_grid_width = screen_width * _relative_width;
	return std::min(max_grid_width / _columns_qty, screen_height / _rows_qty);
}

void LevelGrid::ClearGrid() {
	for (Vector2& cell : _grid) {
		cell.x = -1;
		cell.y = -1;
	}
}

void  LevelGrid::HighlightCellUnderCursor(Vector2& mouse_position) {
	int cell_index = FindeSelectedCell(mouse_position);
	if (cell_index >= 0) {
		Rectangle rect = { _indent.x + (cell_index % _columns_qty) * _cell_size, _indent.y + (cell_index / _columns_qty) * _cell_size, _cell_size, _cell_size };

		DrawRectangleRec(rect, Color{ 255, 255, 255, 30 });
	}
}
	