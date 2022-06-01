#include <iostream>
#include <cmath>
using namespace std;


bool ok(int *board) {
    /*
    if(board[col-i] == r) row
        return false;
    else if (board[col-i] == r-i) diagonal up
        return false;
    else if (board[col-i] == r+i) diagonal down, can be replaced with abs for up and down
        return false;
    */

    for (int col = 0; col < 8; col++) {
        for (int row = 0; row < col; row++) { // reverse because of 1d array
            if ((board[row] == board[col] || (abs(board[col] - board[row])) == (col - row))) {
                return false;
            }
        }
    }
    return true;
}

void print(int *solution) {
    for (int i = 0; i < 8; i++) {
        cout << solution[i] + 1 << " ";
    }
    cout << "\n" << endl;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (solution[j] == i) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

int main() {
    int board[8] = { 0 };
    for (int i0 = 0; i0 < 8; i0++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    board[7] = i7;
                                    board[6] = i6;
                                    board[5] = i5;
                                    board[4] = i4;
                                    board[3] = i3;
                                    board[2] = i2;
                                    board[1] = i1;
                                    board[0] = i0;
                                    if (ok(board)) print(board);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}