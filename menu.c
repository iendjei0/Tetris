#include "menu.h"

void MenuControl()
{
    if(!IsSetControlsHappening && IsKeyPressed(KEY_SPACE))
    {
        GetKeyPressed();
        IsSetControlsHappening = 1;
        ControlsBeingSet = Left;
        SetControls();
    }
    else if(IsSetControlsHappening)
    {
        SetControls();
    }
    else if(IsKeyPressed(KEY_ENTER))
    {
        TetrisInit();
    }
}
void SetControls()
{
    const int boxwidth = 500;
    const int boxheight = 250;
    DrawRectangle(windowwidth/2-boxwidth/2, windowheight/2-boxheight/2, boxwidth, boxheight, PURPLE);
    if(ControlsBeingSet < 6)
    {
        KeyboardKey key;
        switch(ControlsBeingSet)
        {
            case Left:
            {
                DrawText("Press a key to set Left", windowwidth/2 - MeasureText("Press a key to set Left", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
            case 1:
            {
                DrawText("Press a key to set Right", windowwidth/2 - MeasureText("Press a key to set Right", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
            case Down:
            {
                DrawText("Press a key to set Down", windowwidth/2 - MeasureText("Press a key to set Down", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
            case FastDrop:
            {
                DrawText("Press a key to set Fast Drop", windowwidth/2 - MeasureText("Press a key to set Fast Drop", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
            case Flip:
            {
                DrawText("Press a key to set Flip", windowwidth/2 - MeasureText("Press a key to set Flip", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
            case Hold:
            {
                DrawText("Press a key to set Hold", windowwidth/2 - MeasureText("Press a key to set Hold", 30)/2, windowheight/2-15, 30, VIOLET);
                if((key = GetKeyPressed()))
                {
                    Controls[ControlsBeingSet] = key;
                    ControlsBeingSet++;
                }
            }
            break;
        }
    }
    if(ControlsBeingSet == 6)
    {
        IsSetControlsHappening = 0;
    }
}
void TetrisInit()
{
    player.x = 3;
    player.y = 0;
    field.x = windowwidth/2 - Grid*10/2;
    field.y = windowheight/2 - Grid*20/2;
    queue.x = windowwidth*3/4 - Grid*10/4;
    queue.y = field.y;
    hold.x = windowwidth*1/4 - Grid*10/4;
    hold.y = field.y + Grid;
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            Field[x][y] = 0;
            FieldColor[x][y] = LIGHTGRAY;
        }
    }
    for(int i = 0; i < 7; i++) Bag7[i] = 0;
    ActiveType = CreateTetromino(RandomTetromino());
    ActivateBuffor();
    for(int i = 0; i < 4; i++)
    {
        Queue[i] = CreateTetromino(RandomTetromino());
    }
    Held = EMPTY;
    LinesCleared = 0;

    ActiveScreen = Tetris;
}
