#pragma once
#include "raylib.h"
#include <vector>

class LevelGrid
{
private:
	std::vector<Vector2> _grid;
	Rectangle _rendered;
	Rectangle _dest;
	Texture2D _empty_cell_texture;
	Texture2D _tileset;
	Vector2 _indent;
	int _cell_size;
	float _relative_width;
	int _columns_qty;
	int _rows_qty;

private:
	void DrawGridLayout();
	void InitSourse();
	float CalcMaxCellWidth(float width, float height);

public:
	~LevelGrid() = default;
	LevelGrid(const float screen_width, const float screen_height, const int columns_qty, const int rows_qty, float relative_width = 1);
	void Draw();
	void UpdateCell(Vector2& mouse_position);
	void ClearGrid();
};

