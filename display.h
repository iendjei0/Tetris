#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "generics.h"

#define Grid 20

typedef struct point
{
    int x;
    int y;
} point;

point player;
point field;
point queue;
point hold;
point shadow;

bool Field[20][20];
Color FieldColor[20][20];
Tetromino Queue[4];
Tetromino Held;
int LinesCleared;

void DrawMenu();
void DrawGame();
void DrawGameOver();

#endif // DISPLAY_H_INCLUDED
