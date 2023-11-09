#include <iostream>
#include <vector>
#include <stdexcept>
#include "Functions.h"

using namespace std;

int main() {
	char choice = 'Y';
	vector<double> miles, gallons;
	double temp;
	while (toupper(choice) == 'Y') {
		temp = GetMiles();
		if (temp != 0) {
			miles.push_back(temp);
		}
		temp = GetGallons();
		if (temp != 0) {
			gallons.push_back(temp);
		}
		cout << "Would you like to enter another tank? >>> ";
		cin >> choice;
	}

	cout << "The MPG is " << GetMPG(miles, gallons);
	return 0;
}