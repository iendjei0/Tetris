# Struktura programu:


# Moduły:

## generics.h

### Opis:

Zawiera bibliotekę raylib, podstawowe definicje związane ekranem i sterowaniem, zajmuje
się tworzeniem i generacją klocków tetromino oraz funkcję wywołującą okno aplikacji.

### Zawartość:

**windowwidth** - szerokość okna aplikacji
**windowheight** - wysokość okna aplikacji
**struct point** - reprezentuje punkt na płaszczyźnie, zawiera współrzędne x i y
**enum Screen** - określa “ekrany” w których może znajdować się gracz
**Screen ActiveScreen** - zawiera ekran w którym aktualnie znajduje się gracz
**enum Actions** - określa możliwe akcje gracza podczas gry
**KeyboardKey Controls[6]** - przechowuje klawisze sterowania
**void GameInit()** - inicjalizuje aplikację
**enum Tetromino** - określa typy klocków tetromino
**bool ActiveTetromino[4][4]** - reprezentuje klocek tetromino sterowany przez gracza
**Color ActiveColor** - zawiera kolor klocka tetromino sterowanego przez gracza
**Tetromino ActiveType** - zawiera typ klocka tetromino sterowanego przez gracza
**bool TetrominoBuffor[4][4]** - buffor klocka tetromino
**Color BufforColor -** zawiera kolor bufforowanego klocka tetromino
**bool Bag7[7]** - zawiera informacje typów następnych losowanych klocków tetromino
**Tetromino CreateTetromino(Tetromino type)** - tworzy klocek tetromino o zadanym typie w
bufforze, jednocześnie zwraca stworzony typ
**Tetromino RandomTetromino()** - zwraca losowy typ klocka tetromino w oparciu o system 7-
bag (każde następne wylosowane 7 klocków tetromino zawiera wszystkie 7 typów)
**void ActivateBuffor()** - kopiuje bufforowany klocek tetromino do ActiveTetromino


## display.h

### Opis:

Odpowiada za rysowanie wszystkich komponentów gry w każdym etapie gry (jedynie za
wyjątkiem wyboru sterowania). Zawiera wszystkie zmienne posiadające niezbędne
informacje do poprawnego rysowania.

### Zawartość:

**Grid** - ilość pikseli w krawędzi jednej kratki w grze
**struct point** - reprezentuje punkt na płaszczyźnie, zawiera współrzędne x i y
**point player -** pozycja gracza
**point field -** pozycja pola do gry
**point queue -** pozycja kolejki klocków tetromino
**point hold -** pozycja okna trzymanego klocka tetromino
**point shadow -** pozycja cienia rzucanego przez gracza
**bool Field[20][20]** - reprezentuje pole gry
**Color FieldColor[20][20]** - zawiera kolory kratek pola gry
**Tetromino Queue[4]** - typy następnych 4 klocków tetromino w kolejce
**Tetromino Held** - typ trzymanego klocka tetromino
**int LinesCleared** - ilość wyczysczonych linijek w trakcie gry
**void DrawMenu()** - funkcja rysująca główne menu gry
**void DrawGame()** - funkcja rysująca grę
**void DrawGameOver()** - rysuje ekran końca gry i zmienia spowrotem na menu główne

## menu.h

### Opis:

Odpowiada za kontrolę menu, rysowanie oraz ustawianie sterowania gracza oraz
rozpoczyna grę w Tetrisa.

### Zawartość:

**Actions ControlsBeingSet -** akcja której sterowanie jest aktualnie ustawiane
**bool IsSetControlsHappening** - mówi czy jest aktualnie ustawiane sterowanie
**void MenuControl()** - steruje funkcjami menu głównego
**void SetControls()** - rysuje okno ustawiania sterowania oraz zajmuje się ustawianiem
sterowania
**void TetrisInit()** - inicjalizuję grę w Tetrisa


## game.h

### Opis:

Odpowiada za funkcjonalność Tetrisa, sterowanie graczem i ustawianie highscore’a

### Zawartość:

**int MoveLeftCounter** - licznik klatek od ostatniego ruchu w lewo
**int MoveRightCounter** - licznik klatek od ostatniego ruchu w prawo
**int GravityCounter** - licznik klatek od ostatniego ruchu w dół
**void SetCounters()** - ustawia liczniki ruchu na 0
**void Movement()** - inkrementuje liczniki ruchu oraz steruje grawitacją
**void PlayerControl()** - odpowiada za sterowanie graczem
**void PlayerFlip()** - akcja obrotu
**void Freeze()** - odpowiada za umieszczenie klocka tetromino na polu gry jak i za wszystko
następujące w wyniku tego (ustawianie następnego klocka tetromino z kolejki, aktualizacja
wyczyszczonych linii, sprawdzanie czy gracz nie przegrał)
**void PlayerFastDrop()** - akcja szybkiego upuszczenia
**void ShadowPlacement()** - ustawia pozycję cienia rzucanego przez gracza
**bool CollisionCheck(bool Tetromino[4][4])** - sprawdza pozycję klocka z polem
**void LineClear()** - sprawdza obecność linijek do wyczyszczenia i je czyści, aktualizując wynik
**void NextQueue()** - tworzy następną kolejkę klocków tetromino
**void HighscoreCheck()** - sprawdza czy należy zaktualizować highscore i go aktualizuje


