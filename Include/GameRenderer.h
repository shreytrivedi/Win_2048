#pragma once

#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <windows.h>

#define CELL_HEIGHT 100
#define CELL_WIDTH  100
#define GRID_TOP_LEFT_X 50
#define GRID_TOP_LEFT_Y 50
#define ROWS 4
#define COLS 4

void RenderBoard(HDC hdc);

#endif //GAME_RENDERER_H