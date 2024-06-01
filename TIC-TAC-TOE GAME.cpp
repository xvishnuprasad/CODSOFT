#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));
char currentPlayer = 'X';

void displayBoard() {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;
    do {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        bool gameOver = false;
        while (!gameOver) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row column): ";
            cin >> row >> col;
            row--;
            col--;
            if (isValidMove(row, col)) {
                board[row][col] = currentPlayer;
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Thanks for playing!" << endl;
    return 0;
}
