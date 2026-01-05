# Tic-Tac-Toe Game

## Description
A console-based two-player Tic Tac Toe game written in C++.  
The game uses a 3x3 board, allows two players to play on the same computer, and supports saving/loading game progress.

---

## Features
- Turn-based gameplay
- Two-player local mode
- Save and load game state
- Input validation to prevent illegal moves
- Win and draw detection
- Clean, modular code using multiple functions
- Makefile for easy compilation and execution

## How to Play
- Choose Start New Game from the main menu.
- Players take turns entering row and column numbers (1-3) to place their symbol (X or O) on the board.
- The first player to align three symbols in a row, column, or diagonal wins.
- If the board is full and no one has won, the game ends in a draw.
- After the game ends, the program offers options to restart, return to the main menu, or exit.
- You can also load a previously saved game from the main menu.

---

## How to Compile and Run

### Using Makefile (Recommended)
1. Compile the game and run:
   ```bash
   make
   ./tictactoe

   
