#include <iostream>
#include <string>
using namespace std;
const int rows = 5;
const int cols = 6; 

string path[rows][cols];

int cost(int i, int j) {
    static int costs[rows][cols] = { 0 };
    static int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4} };

    //base case
    if (j == 0) {
        costs[i][0] = weight[i][0];
        path[i][j] = to_string(i);
        return weight[i][0];
    }

    // Checks if the value of i is 0 or 4.
    // If it is 0, it will go to the 4th row of that column, otherwise it will go one above the value which is i - 1.
    int row_above = (i == 0 ? 4 : (i - 1)); 
    // If it is 4, it will go to the 0th row of that column, otherwise it will go one below the value which is i + 1.
    int row_below = (i == 4 ? 0 : (i + 1));

    //recursive call
    int directions[3]; // Three directions ~ 0 = left, 1 = up, 2 = down.
    int left = 0, up = 1, down = 2;
    directions[left] = weight[i][j] + cost(i, j - 1); 
    directions[up] = weight[i][j] + cost(row_above, j - 1);
    directions[down] = weight[i][j] + cost(row_below, j - 1);

    //find the value of the shortest path through cell(i,j)
    int minimum = directions[0];
    for (int i = 1; i <= 2; i++) {
        if (directions[i] < minimum)
            minimum = directions[i];
    }


    // Assigns path with the minimum rows to reach answers. 
    if (minimum == directions[0]) 
        path[i][j] = path[i][j - 1] + to_string(i);

    if (minimum == directions[1])
        path[i][j] = path[row_above][j - 1] + to_string(i);

    if (minimum == directions[2]) 
        path[i][j] = path[row_below][j - 1] + to_string(i);

    costs[i][j] = minimum;
    return minimum;
}

int main() {
    int minRow = 0;
    int ex[rows];

    // Shortest path out of each cell on the right
    for (int i = 0; i < rows; i++) {
        ex[i] = cost(i,cols-1);
    }
    int minimum = ex[0];

    for (int i = 0; i < rows; i++) {
        if (ex[i] < minimum) {
            minimum = ex[i];
            minRow = i;
        }
    }

    cout << "The shortest path has a length of: " << minimum << endl;
    cout << "The path from left to right passes through rows: " << path[minRow][cols - 1];
    return 0;
}