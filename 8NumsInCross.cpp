// Damian Brzoska
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int* board, int c) {
    static int check[8][5] = {
    {-1},
    {0, -1},
    {0, 1, -1},
    {0, 2, -1},
    {1, 2, -1},
    {1, 2, 3, 4, -1},
    {2, 3, 5, -1},
    {4, 5, 6, -1}
    };

    // If a number has previously been used, it will return false
    for (int i = 0; i < c; i++) {
        if (board[c] == board[i])
            return false;
    }

    // The for loop  will check if the previous column is -1 or +1 to the current column
    for (int i = 0; check[c][i] != -1; i++) {
        if (board[check[c][i]] + 1 == board[c] || abs(board[check[c][i]] - 1 == board[c]))
            return false;
    }
    return true;
}

// Prints the board and has a counter 
void printBoard(int* board) {
    static int counter;
    cout << "Numnber of Solutions: " << ++counter << endl;
    cout << " " << board[1] << board[4] << "\n" << board[0] << board[2] << board[5] << board[7] << "\n " << board[3] << board[6] << endl;
}

void next(int* board, int c) {
    // If it has reached the end of the board, it will print
    if (c == 8)
        printBoard(board);
    // Otherwise it will check if the previous pieces are ok, and if they are it will add another
    else for (board[c] = 0; board[c] < 8; board[c]++)
        if (ok(board, c)) {
            next(board, c + 1);
        }
}

int main() {
    int q[8] = { 0 };
    next(q, 0);
}

