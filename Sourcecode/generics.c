#include "generics.h"

void GameInit()
{
    InitWindow(windowwidth, windowheight, "Tetris");
    SetTargetFPS(60);
    ActiveScreen = Menu;
    Controls[Left] = KEY_LEFT;
    Controls[Right] = KEY_RIGHT;
    Controls[Down] = KEY_DOWN;
    Controls[FastDrop] = KEY_SPACE;
    Controls[Flip] = KEY_C;
    Controls[Hold] = KEY_X;
}

Tetromino CreateTetromino(Tetromino type)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            TetrominoBuffor[i][j] = 0;
        }
    }

    switch(type)
    {
        case EMPTY:
        {
            for(int x = 0; x < 4; x++)
            {
                for(int y = 0; y < 4; y++)
                {
                    if(TetrominoBuffor[x][y]) TetrominoBuffor[x][y] = 1;
                }
            }
        } break;
        case BOX:   {TetrominoBuffor[1][1] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[2][1] = 1; TetrominoBuffor[2][2] = 1; BufforColor = YELLOW;} break;
        case I:     {TetrominoBuffor[1][0] = 1; TetrominoBuffor[1][1] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[1][3] = 1; BufforColor = SKYBLUE;} break;
        case T:     {TetrominoBuffor[0][2] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[2][2] = 1; TetrominoBuffor[1][1] = 1; BufforColor = VIOLET;} break;
        case Z:     {TetrominoBuffor[0][1] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[2][2] = 1; TetrominoBuffor[1][1] = 1; BufforColor = RED;} break;
        case INVZ:  {TetrominoBuffor[0][2] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[2][1] = 1; TetrominoBuffor[1][1] = 1; BufforColor = LIME;} break;
        case L:     {TetrominoBuffor[0][2] = 1; TetrominoBuffor[1][2] = 1; TetrominoBuffor[2][2] = 1; TetrominoBuffor[2][1] = 1; BufforColor = DARKBLUE;} break;
        case INVL:  {TetrominoBuffor[0][1] = 1; TetrominoBuffor[1][1] = 1; TetrominoBuffor[2][1] = 1; TetrominoBuffor[2][2] = 1; BufforColor = ORANGE;} break;
    }
    return type;
}

Tetromino RandomTetromino()
{
    int check = 0;
    for(int i = 0; i < 7; i++) check += Bag7[i];
    if(check == 0)
    {
        for(int i = 0; i < 7; i++) Bag7[i] = 1;
    }
    Tetromino x = GetRandomValue(1, 7);
    while(Bag7[x-1] == 0) x = GetRandomValue(1, 7);
    Bag7[x-1] = 0;
    return x;
}

void ActivateBuffor()
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            ActiveTetromino[x][y] = TetrominoBuffor[x][y];
            ActiveColor = BufforColor;
        }
    }
}

