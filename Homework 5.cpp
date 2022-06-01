// Damian Brzoska
#include <iostream>
#include <cmath>
using namespace std;
//This thing make the computer go beep bop boop. It takes the input, mods it by 10 twice into first and second. Then goes into a while loop modding it until input is 0.
// Please NOTE this is an int as specified in the homework, do not put anything larger than what int can hold.
int biggestDigit (int digit) {
	int first = digit % 10, biggestNum = 0;
	digit /= 10;
	int second = digit % 10;

	while (digit > 0) {
		if (first >= second) {
			biggestNum = first;
			digit /= 10;
			second = digit % 10;
		}
		else {
			biggestNum = second;
			digit /= 10;
			first = digit % 10;
		}
	}
	return biggestNum;
}
// This function sqrts n, once n is sqrt it checks if it is divisible by any of the prime numbers smaller than the sqrt, if not it is prime. 
bool isPrime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
			break;
		}
	}
}

int main() {
	int x;
	cout << "Please input a positive integer greater than 1000: ";
	cin >> x;

	if (x < 1000) {
		for (int i = 0; i < 5; i++) {
			cout << "Please enter a number that is greater than 1000, you have " << 5 - i << " attempts remaining: ";
			cin >> x;
			if (x >= 1000) {
				break;
			}
		}
	}
	cout << "The largest number from your input is " << biggestDigit(x) << "." << endl;

	for (int i = 1; i <= 100; i++) {
		if (isPrime(i)) {
			cout << i << " is a prime number." << endl;
		}
	}
	return 0;
}

