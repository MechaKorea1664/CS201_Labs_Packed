#include <iostream>
#include <stdexcept>
#include <vector>
#include "Functions.h"

using namespace std;

double GetMiles() {
	double number;
	cout << "Enter the number of miles: ";
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input recieved, you must enter a decimal number." << endl;
	}
	return number;
}

double GetGallons() {
	double number;
	cout << "Enter the number of gallons: ";
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input recieved, you must enter a decimal number." << endl;
	}
	return number;
}

double GetMPG(vector<double> miles, vector<double> gallons) {
	try {
		if (miles.size() == 0 || gallons.size() == 0) {
			throw runtime_error("No values recorded MPG is nan");
		}
		
		double totalMiles = 0, totalGallons = 0;
		for (int i = 0; i < miles.size(); i++) {
			totalMiles += miles[i];
		}
		for (int i = 0; i < gallons.size(); i++) {
			totalGallons += gallons[i];
		}
		return (totalMiles / totalGallons);
	}
	catch (runtime_error &e) {
		cout << e.what() << endl;
	}
}