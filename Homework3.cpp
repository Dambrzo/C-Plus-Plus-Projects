#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Make a triangle with X's. Enter a number: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int i = 1; i <= n; i++) {
			for (int c = n; c >= i; c--) {
				cout << "X";
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++) {
			cout << "-";
		}
	cout << endl;
	}

}