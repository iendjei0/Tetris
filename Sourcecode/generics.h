#ifndef GENERICS_H_INCLUDED
#define GENERICS_H_INCLUDED

#include "raylib.h"

#define windowwidth 800
#define windowheight 640

typedef enum Screen{Menu, Tetris, GameOver} Screen;
Screen ActiveScreen;

typedef enum Actions{Left, Right, Down, FastDrop, Flip, Hold} Actions;
KeyboardKey Controls[6];

void GameInit();

typedef enum Tetromino{EMPTY, BOX, I, T, Z, INVZ, L, INVL} Tetromino;
bool ActiveTetromino[4][4];
Color ActiveColor;
Tetromino ActiveType;
bool TetrominoBuffor[4][4];
Color BufforColor;
bool Bag7[7];
Tetromino CreateTetromino(Tetromino type);
Tetromino RandomTetromino();
void ActivateBuffor();

#endif // GENERICS_H_INCLUDED
