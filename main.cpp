#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));
char currentPlayer = 'X';

void displayBoard() 
{
    cout << "  1   2   3" << endl;
    for (int row = 0; row < 3; row++) 
    {
        cout << row + 1 << " ";
        for (int col = 0; col < 3; col++) 
        {
            cout << board[row][col];
            if (col < 2)
                cout << " | ";
        }
        cout << endl;
        if (row < 2)
            cout << "  ---------" << endl;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

bool checkTie() {
    for (int row = 0; row < 3; row++) 
    {
        for (int col = 0; col < 3; col++) 
        {
            if (board[row][col] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    int row, col;
    bool gameOver = false;

    cout << "Welcome to tic-tac-toe!" << endl;

    while (true) 
    {
        bool gameOver = false;
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';

        while (!gameOver) 
        {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter the row (1-3) and column (1-3): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') 
            {
                cout << "Invalid play. Try again." << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " Won!" << endl;
                gameOver = true;
            } else if (checkTie()) {
                displayBoard();
                cout << "Tie!" << endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char choice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y') 
        {
            break;
        }
    }

    return 0;
}