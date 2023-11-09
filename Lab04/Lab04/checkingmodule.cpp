#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void deposit(float& account, float amount) {
	account = account + amount;
}

char MainMenu() {
	char choice;
	cout << endl << "Main Menu ( Enter one of the following )" << endl;
	cout << "\t(D)eposit, (W)ithdrawl, (L)oan or (Q)uit"<< endl;
	cin >> choice;

	while (toupper(choice) != 'D' && toupper(choice) != 'W' && toupper(choice) != 'L' && toupper(choice) != 'Q') {
		cout << endl << "Invalid choice. Try again. ==> ";
		cin >> choice;
	}

	return choice;
}

float GetValue(string userPrompt) {
	float finput;
	cout << userPrompt;
	cin >> finput;
	while (finput <= 0.0f) {
		cout << userPrompt; 
		cin >> finput;
	}
	return finput;
}

float GetValue(string userPrompt, float upperLimit) {
	float finput;
	cout << userPrompt;
	cin >> finput;
	while (finput <= 0.0f && finput >= upperLimit) {
		cout << userPrompt;
		cin >> finput;
	}
	return finput;
}

float GetInterestRate(int creditScore) {
	float amountInterest;
	if (creditScore <= 500) {
		return 0.05f;
	}
	else if (creditScore <= 700) {
		return 0.03f;
	}
	else {
		return 0.01f;
	}
}

void Withdraw(float& accountBalance, float amountWithdraw) {
	accountBalance -= amountWithdraw;
}

int GetLoanMonths() {
	int numMonth;
	cout << endl << "How many months for the loan? 12, 24, 36, 60 ==> ";
	cin >> numMonth;
	while (numMonth != 12 && numMonth != 24 && numMonth != 36 && numMonth != 60) {
		cout << endl << "You must enter 12, 24, 36 or 60 only" << endl;
		cout << "How many months for the loan? 12, 24, 36, 60 ==> ";
		cin >> numMonth;
	}
	return numMonth;
}

int GetCreditrating() {
	int rating;
	cout << endl <<"What is your credit rating? ==> ";
	cin >> rating;
	while (rating < 300 || rating > 850) {
		cout << endl << "You muse choose a value from 300 - 850 inclusive." << endl;
		cout << "What is your credit rating? ==> ";
		cin >> rating;
	}
	return rating;
}

float CalculateLoanAmount(float principal, float interest, int numMonth) {
	return (principal*pow((1+(interest/12)),(numMonth/12)));
}

void OutputAccount(float amount) {
	cout << endl << "Amount in Account: $" << amount << endl;
}