#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the current state of the board
void print_board(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if the current player has won
bool check_win(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the board is full (draw)
bool check_draw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the game
void play_game() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    vector<char> players = {'X', 'O'};
    int current_player = 0;

    while (true) {
        print_board(board);
        char player = players[current_player];
        cout << "Player " << player << "'s turn." << endl;

        int row, col;
        while (true) {
            cout << "Enter row (0, 1, 2): ";
            cin >> row;
            cout << "Enter column (0, 1, 2): ";
            cin >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = player;
                break;
            } else {
                cout << "Invalid move! Please try again." << endl;
            }
        }

        if (check_win(board, player)) {
            print_board(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        } else if (check_draw(board)) {
            print_board(board);
            cout << "It's a draw!" << endl;
            break;
        }

        current_player = 1 - current_player;
    }

    char play_again;
    cout << "Do you want to play again? (y/n): ";
    cin >> play_again;
    if (play_again == 'y' || play_again == 'Y') {
        play_game();
    } else {
        cout << "Thanks for playing!" << endl;
    }
}

// Main function
int main() {
    play_game();
    return 0;
}
