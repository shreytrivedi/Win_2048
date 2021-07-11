
#include "GameRenderer.h"
#include "GameManager.h"
#include <string>

void DrawBoard(HDC hDC)
{
    HPEN hBlackPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    auto hOldPen = SelectObject(hDC, hBlackPen);

    Rectangle(hDC, GRID_TOP_LEFT_X
        , GRID_TOP_LEFT_Y
        , GRID_TOP_LEFT_X + ROWS * CELL_HEIGHT
        , GRID_TOP_LEFT_Y + COLS * CELL_WIDTH);

    //Draw the Horizontal Lines
    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 1 * CELL_HEIGHT, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 1 * CELL_HEIGHT);

    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 2 * CELL_HEIGHT, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 2 * CELL_HEIGHT);

    MoveToEx(hDC, GRID_TOP_LEFT_X, GRID_TOP_LEFT_Y + 3 * CELL_HEIGHT, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 4 * CELL_WIDTH, GRID_TOP_LEFT_Y + 3 * CELL_HEIGHT);

    //Draw the Vertical Lines
    MoveToEx(hDC, GRID_TOP_LEFT_X + 1 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 1 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4 * CELL_HEIGHT);

    MoveToEx(hDC, GRID_TOP_LEFT_X + 2 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 2 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4 * CELL_HEIGHT);

    MoveToEx(hDC, GRID_TOP_LEFT_X + 3 * CELL_WIDTH, GRID_TOP_LEFT_Y, NULL);
    LineTo(hDC, GRID_TOP_LEFT_X + 3 * CELL_WIDTH, GRID_TOP_LEFT_Y + 4 * CELL_HEIGHT);

    SelectObject(hDC, hOldPen);
    DeleteObject(hBlackPen);
}

void RenderCells(HDC hDC)
{
    GameBoard board = GameManager::GetInstance()->GetGameBoard();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int leftTopX     = GRID_TOP_LEFT_X + CELL_WIDTH  * (j);
            int leftTopY     = GRID_TOP_LEFT_Y + CELL_HEIGHT * (i);
            int rightBottomX = GRID_TOP_LEFT_X + CELL_WIDTH  * (j+1);
            int rightBottomY = GRID_TOP_LEFT_Y + CELL_HEIGHT * (i+1);

            RECT r = { leftTopX, leftTopY, rightBottomX, rightBottomY };

            std::string str = "";
            if(board[i][j]!=0)
                str += std::to_string(board[i][j]);

            DrawTextA(hDC, str.c_str(), -1, &r,
                DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        }
    }
}

void RenderBoard(HDC hDC)
{
    DrawBoard(hDC);
    RenderCells(hDC);
}