#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

// Global game state
char board[3][3];
char currentPlayer;

// Displays the main menu and handles user selection
void showMainMenu() {
    int choice;

    do {
        cout << "\n===== TIC TAC TOE =====\n";
        cout << "1. Start New Game\n";
        cout << "2. Load Game\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                startNewGame();
                break;
            case 2:
                loadGame();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Starts a new game
void startNewGame() {
    currentPlayer = 'X';
    initializeBoard();
    gameLoop();
}

// Initializes the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Main game loop
void gameLoop() {
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        drawBoard();
        cout << "\nPlayer " << currentPlayer << "'s turn\n";
        cout << "Enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        if (!makeMove(row - 1, col - 1)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (checkWin()) {
            drawBoard();
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            saveGame();
            gameOver = true;
        } else if (checkDraw()) {
            drawBoard();
            cout << "\nIt's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}

// Draws the board to the terminal
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

// Attempts to place the current player's symbol
bool makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;

    if (board[row][col] != ' ')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

// Switches between players X and O
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Checks if the current player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        // Columns
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Checks if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Saves the current game state to a file
void saveGame() {
    ofstream file("savegame.txt");

    if (!file) {
        cout << "Error saving game.\n";
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            file << board[i][j];
        }
    }

    file << currentPlayer;
    file.close();
}

// Loads a saved game from a file
void loadGame() {
    ifstream file("savegame.txt");

    if (!file) {
        cout << "No saved game found.\n";
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            file >> board[i][j];
        }
    }

    file >> currentPlayer;
    file.close();

    gameLoop();
}
