#pragma once
#include "raylib.h"
#include <vector>

class LevelGrid
{
private:
	std::vector<Vector2> _grid;
	Rectangle _rendered;
	float _grid_indent_x;
	float _grid_indent_y;
	float _cell_size;
	int _grid_width;
	int _grid_height;

private:
	void DrawGridLayout();

public:
	~LevelGrid() = default;
	LevelGrid(float cell_size, int width, int height);
	void Draw();
	void UpdateCell();
};

