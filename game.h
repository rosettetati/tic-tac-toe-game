#ifndef GAME_H
#define GAME_H

// Menu
void showMainMenu();

// Game control
void startNewGame();
void gameLoop();

// Board handling
void initializeBoard();
void drawBoard();

// Player actions
bool makeMove(int row, int col);
void switchPlayer();

// Game checks
bool checkWin();
bool checkDraw();

// Save / Load
void saveGame();
void loadGame();

#endif
