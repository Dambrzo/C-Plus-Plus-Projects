#include <iostream>
#include <string>
using namespace std;
string happyBirthday(string name, int age) {
	string pronoun;
	if (age == 11 || age == 12 || age == 13) {
		pronoun = "th";
	}
	else if (age % 10 == 1) {
		pronoun = "st";
	}
	else if (age % 10 == 2) {
		pronoun = "nd";
	}
	else if (age % 10 == 3) {
		pronoun = "rd";
	}
	else pronoun = "th";

	string ageStr = to_string(age); // to_string converts the input, in this case (age) to a string.
	string output = "Happy " + ageStr + pronoun + " birthday, " + name + "!";
	return output;
}
int userInput(string input) {
	if (input == "stop") {
		return 0;
	}
}
int main() {
	string userName, checker;
	int userAge = 0;

	do {
		cout << "What is your name? ";
		cin >> userName;
		if (userInput(userName) == 0) return 0;
		cout << "What is your age? ";
		cin >> checker;
		if (userInput(checker) == 0) return 0;
		userAge = stoi(checker); // stoi converts a string, in this case (checker) to an int. 

		if (userAge > 120 || userAge <= 0) {
			cout << "Error. What is your age? ";
			cin >> userAge;
			if (userAge > 0 && userAge <= 120) {
			}
			else return 0;
		}
		cout << happyBirthday(userName, userAge) << endl << endl;
	} while (true);
}







