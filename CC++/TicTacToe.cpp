#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<char>& board) {
    cout << "-------------" << endl;
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
    cout << "-------------" << endl;
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }

    return false;
}

int main() {
    vector<char> board(9, ' '); // Initialize an empty board
    int currentPlayer = 1; // Player 1 starts

    while (true) {
        // Draw the board
        drawBoard(board);

        // Get the current player's move
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Check if the move is valid
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the move
        board[move - 1] = currentPlayer == 1 ? 'X' : 'O';

        // Check if the current player has won
        if (checkWin(board, currentPlayer == 1 ? 'X' : 'O')) {
            // Draw the final board
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if it's a tie
        if (count(board.begin(), board.end(), ' ') == 0) {
            // Draw the final board
            drawBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}