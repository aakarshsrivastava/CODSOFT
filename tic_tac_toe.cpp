#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void displayBoard(const vector<vector<char>>& board) // 2D input as ASCII art
{
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}


bool isWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; ++i) // check rows and col
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // to check diag
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool isDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

// switches players after each move
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool updateBoard(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}


bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}


void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {

        cout << "Current board state:" << endl;
        displayBoard(board);
        

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

      
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter numbers." << endl;
            continue;
        }
        
        row--; 
        col--;

        if (isValidMove(board, row, col)) {
            if (updateBoard(board, row, col, currentPlayer)) {
             
                gameWon = isWin(board, currentPlayer);
                if (!gameWon) {
                    gameDraw = isDraw(board);
                    if (!gameDraw) {
                        switchPlayer(currentPlayer);
                    }
                }
            } else {
                cout << "That cell is already taken. Try again." << endl;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }


    cout << "Final board state:" << endl;
    displayBoard(board);


    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else if (gameDraw) {
        cout << "The game is a draw!" << endl;
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
// to compile code : g++ -std=c++11 tic_tac_toe.cpp -o tic_tac_toe 
//./tic_tac_toe    