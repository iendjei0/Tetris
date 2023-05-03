#include <stdio.h>
#include "game.h"

void SetCounters()
{
    MoveLeftCounter = 0;
    MoveRightCounter = 0;
    GravityCounter = 0;
}
void Movement()
{
    MoveRightCounter++;
    MoveLeftCounter++;
    GravityCounter++;
    if(GravityCounter > 60/((LinesCleared+10)/10))
    {
        player.y++;
        if(CollisionCheck(ActiveTetromino))
        {
            player.y--;
            Freeze();
        }
        GravityCounter = 0;
    }
}

void PlayerControl()
{
    if(IsKeyDown(Controls[Down]) && GravityCounter > 2)
    {
        GravityCounter = 0;
        player.y++;
        if(CollisionCheck(ActiveTetromino))
        {
            player.y--;
            Freeze();
        }
    }
    if(IsKeyDown(Controls[Left]) && MoveLeftCounter > 4)
    {
        MoveLeftCounter = 0;
        player.x--;
        if(CollisionCheck(ActiveTetromino)) player.x++;
    }
    if(IsKeyDown(Controls[Right]) && MoveRightCounter > 4)
    {
        MoveRightCounter = 0;
        player.x++;
        if(CollisionCheck(ActiveTetromino)) player.x--;
    }
    if(IsKeyPressed(Controls[Flip]))
    {
        PlayerFlip();
    }
    if(IsKeyPressed(Controls[Hold]))
    {
        PlayerHold();
    }
    if(IsKeyPressed(Controls[FastDrop]))
    {
        PlayerFastDrop();
    }
    ShadowPlacement();
}
void PlayerFlip()
{
    bool Flipped1[4][4];
    for(int x = 0 ; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            if(ActiveTetromino[x][y])
            {
                Flipped1[y][x] = 1;
            }
            else Flipped1[y][x] = 0;
        }
    }
    bool Flipped2[4][4];
    for(int x = 0 ; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            Flipped2[x][y] = Flipped1[3-x][y];
        }
    }
    if(!CollisionCheck(Flipped2))
    {
        for(int x = 0 ; x < 4; x++)
        {
            for(int y = 0; y < 4; y++)
            {
                ActiveTetromino[x][y] = Flipped2[x][y];
            }
        }
    }
}
void Freeze()
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            if(ActiveTetromino[x][y])
            {
                Field[x+player.x][y+player.y] = 1;
                FieldColor[x+player.x][y+player.y] = ActiveColor;
            }
        }
    }
    ActiveType = CreateTetromino(Queue[0]);
    ActivateBuffor();
    NextQueue();
    player.x = 3;
    player.y = 0;
    LineClear();
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            if(ActiveTetromino[x][y] && Field[x+player.x][y+player.y])
            {
                HighscoreCheck();
                ActiveScreen = GameOver;
            }
        }
    }
    UsedHold = 0;
}
void PlayerFastDrop()
{
    player.y = shadow.y;
    Freeze();
}
void PlayerHold()
{
    if(!UsedHold)
    {
        UsedHold = 1;
        if(Held == EMPTY)
        {
            Held = ActiveType;
            CreateTetromino(Queue[0]);
            ActivateBuffor();
            NextQueue();
        }
        else
        {
            Tetromino temp = Held;
            Held = ActiveType;
            CreateTetromino(temp);
            ActivateBuffor();
        }
        player.x = 3;
        player.y = 0;
    }
}
void ShadowPlacement()
{
    shadow.x = player.x;
    shadow.y = player.y;
    int ShadowCollisions;
    do
    {
        ShadowCollisions = 0;
        for(int x = 0; x < 4; x++)
        {
            for(int y = 0; y < 4; y++)
            {
                if(ActiveTetromino[x][y])
                {
                    if(Field[shadow.x+x][shadow.y+y] || shadow.y+y > 19) ShadowCollisions++;
                }
            }
        }
        shadow.y++;
    } while(ShadowCollisions == 0);
    shadow.y-=2;
}
bool CollisionCheck(bool Tetromino[4][4])
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            if(Tetromino[x][y])
            {
                if(player.x+x < 0 || player.x+x > 9 || player.y+y < 0 || player.y+y > 19) return 1;
                if(Field[player.x+x][player.y+y]) return 1;
            }
        }
    }
    return 0;
}

void LineClear()
{
    for(int y = 0; y < 20; y++)
    {
        int LineCounter = 0;
        for(int x = 0; x < 10; x++)
        {
            if(Field[x][y]) LineCounter++;
        }
        if(LineCounter == 10)
        {
            LinesCleared++;
            for(int i = y; i > 0; i--)
            {
                for(int j = 0; j < 20; j++)
                {
                    Field[j][i] = Field[j][i-1];
                    FieldColor[j][i] = FieldColor[j][i-1];
                }
            }
            for(int i = 0; i < 10; i++)
            {
                Field[i][0] = 0;
                FieldColor[i][0] = LIGHTGRAY;
            }
        }
    }
}
void NextQueue()
{
    for(int i = 0; i < 3; i++)
    {
        Queue[i] = Queue[i+1];
    }
    Queue[3] = CreateTetromino(RandomTetromino());
}
void HighscoreCheck()
{
    int highscore;
    FILE *f = fopen("highscore.txt", "r");
    fscanf(f, "%d", &highscore);
    fclose(f);

    if(highscore < LinesCleared)
    {
        FILE *f = fopen("highscore.txt", "w");
        fprintf(f, "%d", LinesCleared);
        fclose(f);
    }
}
