#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int c) {
    for (int i = 0; i < c; i++)
        if (q[i] == q[c] || abs(q[c] - q[i]) == c - i)
            return false;
    return true;
}

void print(int* q) {
    static int solutionCounter = 0;

    typedef char box[5][7];
    box bb, wb, *board[8][8];

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 7; c++) {
            bb[r][c] = ' ';
            wb[r][c] = char(219);
        }
    }

    static box bq = { {char(219), char(219), char(219), char(219), char(219),char(219),char(219)}, // black queen box
                      {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                      {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                      {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                      {char(219), char(219), char(219), char(219), char(219),char(219),char(219)},
    };
    static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }, // white queen box
                      {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                      {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                      {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                      {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
    };

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if ((r + c) % 2 == 0)
                board[r][c] = &wb;
            else board[r][c] = &bb;
        }
    }
    for (int i = 0; i < 8; i++) {
        if ((i + q[i]) % 2 == 0)
            board[q[i]][i] = &bq;
        else board[q[i]][i] = &wq;
    }
    
    cout << "Solution: " << ++solutionCounter << endl;
    for (int i = 0; i < 7 * 8; i++) {
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 5; j++) { 
            cout << char(179);
            for (int z = 0; z < 8; z++) {
                for (int x = 0; x < 7; x++) {
                    cout << (*board[i][z])[j][x];

                }

            }
            cout << char(179) << endl;
        }
    }
    
    cout << " ";
    for (int i = 0; i < 7 * 8; i++) {
        cout << char(196);
    }
    cout << endl;

}

void next(int col, int *q) {                                    
    if (col == 8) {                                                                
        print(q);
    } else for (int row = 0; row < 8; row++) {
        q[col] = row;
        if (ok(q, col)) next(col + 1, q);
    }                                                                       
    return;
}

int main() {
    int q[8];
    q[0] = 0;
    next(0, q);
    return 0;
}