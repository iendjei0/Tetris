#include "menu.h"
#include "game.h"

int main()
{
    GameInit();
    SetCounters();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        switch(ActiveScreen)
        {
            case Menu:
            {
                DrawMenu();
                MenuControl();
            }
            break;
            case Tetris:
            {
                Movement();
                PlayerControl();
                DrawGame();
            }
            break;
            case GameOver:
            {
                DrawGameOver();
            }
            break;
        }
        EndDrawing();
    }
    return 0;
}
