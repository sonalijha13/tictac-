#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    // Constructor to initialize the game
    TicTacToe() {
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        currentPlayer = 'X'; // Player 'X' always starts
    }

    // Function to print the board
    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    // Function to handle player move
    bool makeMove(int move) {
        // Convert move to row and column
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the spot is available
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            return true;
        } else {
            return false;
        }
    }

    // Function to switch the player
    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    // Function to check if a player has won
    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    // Function to check if the game is a draw
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

    // Function to play the game
    void play() {
        int move;
        bool validMove;
        bool gameWon = false;

        while (true) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            // Validate the move
            validMove = makeMove(move);
            if (!validMove) {
                cout << "Invalid move, try again.\n";
                continue;
            }

            // Check for a win
            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for a draw
            if (checkDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
