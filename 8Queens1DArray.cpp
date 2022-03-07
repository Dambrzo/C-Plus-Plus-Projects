#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int q[8], c = 0, counter = 0;
	q[0] = 0;
nc:
	c++;
	// If the array is full, it prints out the array
	if (c == 8) goto print;
	q[c] = -1;
nr:
	q[c]++;
	if (q[c] == 8) goto backtrack;
	// Test the diagnol and the row
	for (int r = 0; r < c; r++) {
		if ((q[r] == q[c]) || (c - r == abs(q[c] - q[r])))
			goto nr;
	}
	goto nc;
backtrack:
	c--;
	// checks if c is out of bounds (board is 8x8)
	if (c == -1)
		return 0;
	goto nr;
print:
	// Prints the solution set
	cout << "\nSolution set: " << ++counter << endl;
	// Prints out the array +1 to match the board
	for (int r = 0; r < 8; r++) {
		if (r < 7 && r > 0) {
			cout << q[r] + 1 << ",";
		}
		else if (r == 0) {
			cout << "{" << q[r] + 1 << ",";
		} else cout << q[r] + 1<< "}" << endl;	
	} 

	// Prints out a 8x8 board, which fills in the locations the queen doesn't occupy with 0's. 
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++)
			// Checks if the array's number is equal to the column of the for loop, if it is it places a 1, if not it places a 0
			if (q[c] == r) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		cout << endl;
	}
	goto backtrack;
}