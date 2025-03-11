#include "Constants.h"
#include "LevelGrid.h"

LevelGrid::LevelGrid(float cell_size, int width, int height) :
	_cell_size(cell_size), _grid_width(width), _grid_height(height) {

	_grid.resize(width * height);

	_rendered.height = _cell_size;
	_rendered.width = _cell_size;

	_grid_indent_x = SCREEN_WIDTH - _grid_width * _cell_size;
	_grid_indent_y = (SCREEN_HEIGHT - _grid_height * _cell_size) / 2;
}

void LevelGrid::DrawGridLayout() {
	float start_y = _grid_indent_y;
	float end_y = SCREEN_HEIGHT - _grid_indent_y;

	float start_x = _grid_indent_x;
	float end_x = SCREEN_WIDTH;


	for (int i = 0; i <= _grid_width; i++) {
		DrawLine(_grid_indent_x + _cell_size * i, start_y, _grid_indent_x + _cell_size * i, end_y, Color{ 100, 255, 100, 255 });
	}

	for (int i = 0; i <= _grid_height; i++) {
		DrawLine(start_x, start_y + _cell_size * i, end_x, start_y + _cell_size * i, Color{ 100, 255, 100, 255 });
	}
}

void LevelGrid::Draw() {

	///*for (int i = _grid.size() - 1; i >= 0; i--) {
	//	_rendered.x = _grid_indent_x + (i % _grid_width) * _cell_size;
	//	_rendered.y = _grid_indent_y + (i / _grid_width) * _cell_size;

	//	drawrectanglelinesex(_rendered, 1, color{ 100, 255, 100, 255 });
	//}*/
	DrawGridLayout();
}

void LevelGrid::UpdateCell() {

}