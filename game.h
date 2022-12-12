#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "display.h"

int MoveLeftCounter;
int MoveRightCounter;
int GravityCounter;

void SetCounters();
void Movement();
void PlayerControl();
    void PlayerFlip();
    void Freeze();
    void PlayerFastDrop();
        void ShadowPlacement();
    void PlayerHold();
        bool UsedHold;

bool CollisionCheck(bool Tetromino[4][4]);

void LineClear();
void NextQueue();
void HighscoreCheck();

#endif // GAME_H_INCLUDED
