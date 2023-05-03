# Program structure:


# Modules:

## generics.h

### Description:

Contains raylib library, basic definitions related to screen and control, deals with
deals with the creation and generation of tetromino blocks, and a function that calls the application window.

### Contents:

**windowwidth** - width of the application window.

**windowheight** - the height of the application window.

**struct point** - represents a point on the plane, contains x and y coordinates.

**enum Screen** - defines the "screens" in which the player can be located.

**Screen ActiveScreen** - contains the screen in which the player is currently located.

**enum Actions** - defines the possible actions of the player during the game.

**KeyboardKey Controls[6]** - stores the control keys.

**void GameInit()** - initializes the application.

**enum Tetromino** - defines the types of tetromino blocks.

**bool ActiveTetromino[4][4]** - represents a tetromino block controlled by the player.

**Color ActiveColor** - contains the color of the tetromino block controlled by the player.

**Tetromino ActiveType** - contains the type of tetromino block controlled by the player.

**bool TetrominoBuffor[4][4]** - buffor of the tetromino block.

**Color BufforColor -** contains the color of the tetromino block being buffered.

**bool Bag7[7]** - contains information of the types of the next tetromino blocks to be drawn.

**Tetromino CreateTetromino(Tetromino type)** - creates a tetromino block of the specified type in the
buffer, at the same time returns the created type

**Tetromino RandomTetromino()** - returns a random type of tetromino block based on the 7-
bag (each next 7 tetromino blocks drawn contains all 7 types).

**void ActivateBuffor()** - copies the buffered tetromino block to ActiveTetromino.


## display.h

### Description:

Responsible for drawing all game components in each stage of the game (with the only
exception of control selection). It contains all the variables that have the necessary
information for correct drawing.

### Contents:

**Grid** - the number of pixels in the edge of one grid in the game.

**struct point** - represents a point on the plane, contains x and y coordinates.

**point player -** position of the player

**point field -** position of the playing field

**point queue -** position of the queue of tetromino blocks.

**point hold -** position of the window of the tetromino block held.

**point shadow -** position of the shadow cast by the player

**bool Field[20][20]** - represents the field of play.

**Color FieldColor[20][20]** - contains the colors of the game field grids.

**Tetromino Queue[4]** - types of the next 4 tetromino blocks in the queue.

**Tetromino Held** - type of tetromino block held.

**int LinesCleared** - the number of cleared lines during the game.

**DrawMenu()** - function that draws the main menu of the game.

**void DrawGame()** - function that draws the game.

**void DrawGameOver()** - draws the end game screen and changes back to the main menu.

## menu.h

### Description:

Responsible for menu control, drawing and setting player controls and
starts the Tetris game.

### Contents:

**Actions ControlsBeingSet -** the action whose control is currently being set.

**bool IsSetControlsHappening** - says whether the control is currently being set.

**void MenuControl()** - controls the main menu functions.

**void SetControls()** - draws the control setting window and takes care of setting the
control

**void TetrisInit()** - initializes the Tetris game.

## game.h

### Description:

Responsible for Tetris functionality, player control and highscore setting.

### Contents:

**int MoveLeftCounter** - frame counter since the last move to the left.

**int MoveRightCounter** - frame counter from the last move to the right.

**int GravityCounter** - frame counter from last move down.

**void SetCounters()** - sets the movement counters to 0.

**void Movement()** - increments the movement counters and controls gravity.

**void PlayerControl()** - is responsible for controlling the player.

**void PlayerFlip()** - rotates action.

**void Freeze()** - is responsible for placing the tetromino block on the playing field as well as everything
following as a result (placing the next tetromino block from the queue, updating the
cleared lines, checking if the player has lost)

**void PlayerFastDrop()** - quick drop action.

**void ShadowPlacement()** - sets the position of the shadow cast by the player.

**bool CollisionCheck(bool Tetromino[4][4])** - checks the position of the block with the field.

**void LineClear()** - checks the presence of lines to be cleared and clears them, updating the result.

**void NextQueue()** - creates the next queue of tetromino blocks.

**void HighscoreCheck()** - checks if the highscore should be updated and updates it.