#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return board[i][0];
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return board[0][i];
        }

        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return board[0][0];
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return board[0][2];

        // Check for a tie or ongoing game
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return ' '; // Game is still ongoing

        return 'T'; // Tie
    }

    bool isValidInput(int row, int col) {
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter two numbers separated by a space (e.g., '1 1').\n";
            return false;
            }
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input. Please enter row and column numbers between 1 and 3.\n";
            return false;
        }
        if (board[row - 1][col - 1] != ' ') {
            cout << "That spot is already taken. Please choose another spot.\n";
            return false;
        }
        return true;
    }

    void playGame() {
        char winner = ' ';
        printBoard();
        while (winner == ' ') {
            int row = 0, col = 0;
            cout << "Player " << currentPlayer << ", enter your move (row and column, ex: '1 1'): ";
            cin >> row >> col;
            if(isValidInput(row, col)){
                if (makeMove(row - 1, col - 1)) {
                    printBoard();
                    winner = checkWin();
                    if (winner == ' ') switchPlayer();
                }
            } else {
                cin.clear();
            }
        }

        if (winner == 'T')
            cout << "It's a tie!\n";
        else
            cout << "Player " << winner << " wins!\n";
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
