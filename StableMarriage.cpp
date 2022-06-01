#include <iostream>
using namespace std;

bool ok(int *q, int col) {
    static int mp[3][3] = { {0,2,1}, // men preference                 
                            {0,2,1},                   
                            {1,2,0} 
    };                   
    static int wp[3][3] = { {2,1,0}, // women preference                
                            {0,1,2},                     
                            {2,0,1} 
    };
    for (int i = 0; i < col; i++) {
        if (q[col] == q[i]  
           || (mp[col][q[i]] < mp[col][q[col]]) && (wp[q[i]][col] < wp[q[i]][i])
           || (mp[i][q[col]] < mp[i][q[i]]) && (wp[q[col]][i] < wp[q[col]][col]))
           return false;
    }
    return true;
}

void print(int *pair) {
    static int counterSolutions = 0;
    cout << "Number of Solutions: " << ++counterSolutions << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Man: " << i << " Woman: " << pair[i] << endl;
    }
    cout << endl;
}

void recursivefunc(int *q, int x) {
    if (x == 3) {
        print(q);
        return;
    }
    for (int value = 0; value < 3; value++) {
        q[x] = value;
        if (ok(q, x))recursivefunc(q, x + 1);
    }
}
int main() {
    int matches[3];
    recursivefunc(matches, 0);
}