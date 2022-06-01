#include <iostream>
using namespace std;

int main() {
	int i = 0, num = 0 ;
	while (num == 0) {
		if (i * i % 2 && i * i / 10 % 10 % 2) {
			num = i * i; 
			cout << num;
			break;
		}
		i++;
	}
}
// This code WOULD get you the result if there was a perfect square that ended in two odd numbers, although that answer doesn't exist
// So in reality this code should just be int main () { return 0; }