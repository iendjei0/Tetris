#include <stdio.h>
#include "display.h"


void DrawMenu()
{
    ClearBackground(VIOLET);
    DrawText("TETRIS", windowwidth/2-MeasureText("TETRIS", 50)/2, 60, 50, PINK);
    DrawText("Press ENTER to start game.\nPress SPACE to customize controls.", windowwidth/2-MeasureText("Press ENTER to start game.\nPress SPACE to customize controls.", 30)/2, windowheight - 120, 30, PINK);

    int highscore;
    FILE *f = fopen("highscore.txt", "r");
    fscanf(f, "%d", &highscore);
    fclose(f);
    DrawText(TextFormat("Current highscore: %03i", highscore), windowwidth/2 - MeasureText(TextFormat("Current highscore: %03i", highscore), 30)/2, windowheight/2-30, 30, PINK);

}
void DrawGame()
{

    ClearBackground(PINK);
    //Gamefield Background
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            DrawRectangle(field.x+x*Grid, field.y+y*Grid, Grid, Grid, FieldColor[x][y]);
        }
    }
    //Player & Shadow
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(ActiveTetromino[i][j])
            {
                DrawRectangle((shadow.x+i)*Grid+field.x, (shadow.y+j)*Grid+field.y, Grid, Grid, (Color){ 80, 80, 80, 85});
                DrawRectangle((player.x+i)*Grid+field.x, (player.y+j)*Grid+field.y, Grid, Grid, ActiveColor);
            }
        }
    }
     //Gamefield Grid
    for(int x = field.x; x <= Grid*10+field.x; x += Grid)
    {
        for(int y = field.y; y <= Grid*20+field.y; y += Grid)
        {
            DrawLine(x, y, Grid*10+field.x, y, GRAY);
            DrawLine(x, y, x, Grid*20+field.y, GRAY);
        }
    }

    //Queue
    int q = 0;
    for(int y = 1; y < 20; y+=5)
    {
        DrawRectangle(queue.x, queue.y+y*Grid, Grid*4, Grid*4, LIGHTGRAY);
        CreateTetromino(Queue[q]);
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(TetrominoBuffor[i][j])
                {
                    DrawRectangle(queue.x+i*Grid, queue.y+(j+y)*Grid, Grid, Grid, BufforColor);
                }
            }
        }
        q++;
    }
    //Hold
    DrawRectangle(hold.x, hold.y, Grid*4, Grid*4, LIGHTGRAY);
    if(Held != EMPTY)
    {
        CreateTetromino(Held);
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(TetrominoBuffor[i][j])
                {
                    DrawRectangle(hold.x+i*Grid, hold.y+j*Grid, Grid, Grid, BufforColor);
                }
            }
        }
    }
    //Score
    DrawText(TextFormat("SCORE: %03i", LinesCleared), windowwidth/2 - MeasureText(TextFormat("SCORE: %03i", LinesCleared), 30)/2, 70, 30, LIGHTGRAY);
}
void DrawGameOver()
{
    ClearBackground(MAGENTA);
    DrawText("GAME OVER", windowwidth/2 - MeasureText("GAME OVER", 50)/2, windowheight/2-25, 50, GREEN);
    DrawText("Press ENTER to go to menu.", windowwidth/2-MeasureText("Press ENTER to go to menu.", 30)/2, windowheight - 50, 30, GREEN);
    if(IsKeyPressed(KEY_ENTER)) ActiveScreen = Menu;
}
