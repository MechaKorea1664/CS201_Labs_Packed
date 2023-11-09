#include "functions.h"
#include <iostream>
using namespace std;

int main() {
	int input;

	cout << "Enter an integer\n";
	cin >> input;
	cout << "\n" << input << "! = " << factorial_r(input) << "\n";
	cout << "\nfibonacci(" << input << ") = " << fibonacci_r(input) << "\n\n";
	cout << "Enter a number to check if it is a prime number\n";
	cin >> input;
	if (is_prime_r(input, 2))
		cout << input << " is a prime number\n\n";
	else
		cout << input << " is not a prime number\n\n";

	int intArr[5];
	cout << "Next we will enter 5 values into an array\n";
	for (int i = 0; i < 5; i++) {
		cout << "Enter a value for index " << i << "\n";
		cin >> input;
		intArr[i] = input;
	}
	cout << "\nThe sum of all the values is " << sum_r(intArr, 5) << "\n";
	cout << "The list output in reverse is\n";
	output_reverse_list_r(intArr, 5);

	return 0;
}