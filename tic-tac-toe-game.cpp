/*
Tic-Tac-Toe Game
----------------
Author: Gustavo Borges
Language: C++
Purpose: Academic project (First semester)

Description:
A terminal-based Tic-Tac-Toe game supporting both Player vs Player 
and Player vs Computer modes. 
*/

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#define MAX 3
#define SIZE 20

// Structure to store player data: names and chosen symbols
struct TicTacToe {
    char player1Name[SIZE];
    char player2Name[SIZE];
    char player1Symbol;
    char player2Symbol;
};

// Prints the current state of the board to the terminal
void printBoard(char board[3][3]) {
    int i, j;

    cout << endl;
    cout << "Board: " << endl;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (board[i][j] == '\0')
                cout << " ";
            else
                cout << board[i][j];

            if (j != 2)
                cout << " | ";
        }
        cout << endl;
        if (i != 2)
            cout << "----------" << endl;
    }
    cout << endl;
}

// Resets the board by filling all positions with null characters
void clearBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '\0';
        }
    }
}

// Displays the game mode selection menu
void gameMode(int &choice) {
    cout << "Choose the game mode: " << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;
}

// Handles player input, validates the move, and updates the board
void playerMove(char board[3][3], int &turn, TicTacToe symbols) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Enter row and column (e.g., 1 2): ";
        cin >> row >> col;

        // Validate board boundaries
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid position. Enter values between 1 and 3." << endl;
            continue;
        }

        row--;
        col--;

        // Check if the position is already taken
        if (board[row][col] != '\0') {
            cout << "This position is already occupied. Choose another." << endl;
            continue;
        }

        // Assign the correct symbol based on the turn
        if (turn % 2 != 0) {
            board[row][col] = symbols.player1Symbol;
        } else {
            board[row][col] = symbols.player2Symbol;
        }

        validMove = true;
        turn++;
    }
}

// Generates a random move for the computer
void computerMove(char board[3][3], char computerSymbol, int &turn) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        row = rand() % 3;
        col = rand() % 3;

        if (board[row][col] == '\0') {
            board[row][col] = computerSymbol;
            validMove = true;
        }
    }
    turn++;
}

// Analyzes the board to check for victory, draw, or ongoing game
void analyzeMatch(int &status, char board[3][3], TicTacToe symbols) {

    // Check Player 1 victory (rows and columns)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbols.player1Symbol &&
            board[i][1] == symbols.player1Symbol &&
            board[i][2] == symbols.player1Symbol) {
            cout << symbols.player1Name << " won the game!" << endl;
            status = 0;
            return;
        }

        if (board[0][i] == symbols.player1Symbol &&
            board[1][i] == symbols.player1Symbol &&
            board[2][i] == symbols.player1Symbol) {
            cout << symbols.player1Name << " won the game!" << endl;
            status = 0;
            return;
        }
    }

    // Check Player 1 victory (diagonals)
    if (board[0][0] == symbols.player1Symbol &&
        board[1][1] == symbols.player1Symbol &&
        board[2][2] == symbols.player1Symbol) {
        cout << symbols.player1Name << " won the game!" << endl;
        status = 0;
        return;
    }

    if (board[0][2] == symbols.player1Symbol &&
        board[1][1] == symbols.player1Symbol &&
        board[2][0] == symbols.player1Symbol) {
        cout << symbols.player1Name << " won the game!" << endl;
        status = 0;
        return;
    }

    // Check Player 2 victory (rows and columns)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbols.player2Symbol &&
            board[i][1] == symbols.player2Symbol &&
            board[i][2] == symbols.player2Symbol) {
            cout << symbols.player2Name << " won the game!" << endl;
            status = 0;
            return;
        }

        if (board[0][i] == symbols.player2Symbol &&
            board[1][i] == symbols.player2Symbol &&
            board[2][i] == symbols.player2Symbol) {
            cout << symbols.player2Name << " won the game!" << endl;
            status = 0;
            return;
        }
    }

    // Check Player 2 victory (diagonals)
    if (board[0][0] == symbols.player2Symbol &&
        board[1][1] == symbols.player2Symbol &&
        board[2][2] == symbols.player2Symbol) {
        cout << symbols.player2Name << " won the game!" << endl;
        status = 0;
        return;
    }

    if (board[0][2] == symbols.player2Symbol &&
        board[1][1] == symbols.player2Symbol &&
        board[2][0] == symbols.player2Symbol) {
        cout << symbols.player2Name << " won the game!" << endl;
        status = 0;
        return;
    }

    // Check for draw or continue game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '\0') {
                status = 1; // Moves still available
                return;
            }
        }
    }

    cout << "It's a Draw!" << endl;
    status = 0;
}

int main() {
    int choice, matchStatus, turn = 1;
    char board[3][3] = {0};
    TicTacToe players;

    cout << "Tic-Tac-Toe Game" << endl;

    gameMode(choice);
    cin.ignore();

    // Setup player names and symbols
    if (choice == 1) {
        cout << "First player, enter your name: ";
        cin.getline(players.player1Name, SIZE);
        cout << endl;
        cout << players.player1Name << ", do you prefer X or O? ";
        cin >> players.player1Symbol;
        cin.ignore();

        while (players.player1Symbol != 'X' && players.player1Symbol != 'O' 
            && players.player1Symbol != 'x' && players.player1Symbol != 'o') {
            
            cout << "Invalid input, please enter X or O: ";
            cin >> players.player1Symbol;
        }

        cout << "Second player, enter your name: ";
        cin.getline(players.player2Name, SIZE);
        cout << endl;

        if (players.player1Symbol == 'X' || players.player1Symbol == 'x') {
            cout << "You will play as O" << endl;
            players.player2Symbol = (players.player1Symbol == 'X') ? 'O' : 'o';
        } else {
            cout << "You will play as X" << endl;
            players.player2Symbol = (players.player1Symbol == 'O') ? 'X' : 'x';
        }
    }

    if (choice == 2) {
        cout << "Enter your name: ";
        cin.getline(players.player1Name, SIZE);
        cout << players.player1Name << ", do you prefer X or O? ";
        cin >> players.player1Symbol;

        strcpy(players.player2Name, "Computer");

        while (players.player1Symbol != 'X' && players.player1Symbol != 'O' 
            && players.player1Symbol != 'x' && players.player1Symbol != 'o') {
            
            cout << "Invalid input, please enter X or O: ";
            cin >> players.player1Symbol;
        }

        if (players.player1Symbol == 'X' || players.player1Symbol == 'x') {
            players.player2Symbol = 'O';
        } else {
            players.player2Symbol = 'X';
        }
    }

    srand(time(NULL));

    while (choice != 0) {
        switch (choice) {
        case 1: // Player vs Player
            matchStatus = 1;
            clearBoard(board);
            turn = 1;
            do {
                printBoard(board);
                playerMove(board, turn, players);
                analyzeMatch(matchStatus, board, players);
                if (matchStatus == 0) {
                    printBoard(board);
                }
            } while (matchStatus != 0);
            break;

        case 2: // Player vs Computer
            matchStatus = 1;
            clearBoard(board);
            turn = 1;
            do {
                printBoard(board);
                playerMove(board, turn, players);
                analyzeMatch(matchStatus, board, players);
                if (matchStatus == 0) {
                    printBoard(board);
                    break;
                }
                computerMove(board, players.player2Symbol, turn);
                analyzeMatch(matchStatus, board, players);
                if (matchStatus == 0) {
                    printBoard(board);
                }
            } while (matchStatus != 0);
            break;
        }
        gameMode(choice);
    }

    return 0;
}
