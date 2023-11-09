#include <iostream>
#include <string>
#include "checkingmodule.h"
using namespace std;

int main() {
	float accountValue = 0.0f, getVal, loanAmount, loanInterest;
	char choice;
	int numMonths;
	
	choice = MainMenu();
	
	while (toupper(choice) != 'Q') {
		switch (choice)
		{
		case 'd':
		case 'D':
			getVal = GetValue("How much do you want to deposit? ==> ");
			deposit(accountValue, getVal);
			OutputAccount(accountValue);
			break;
		case 'w':
		case 'W':
			getVal = GetValue("How much do you want to withdraw? ==> ");
			Withdraw(accountValue, getVal);
			OutputAccount(accountValue);
			break;
		case 'l':
		case 'L':
			loanInterest = GetInterestRate(GetCreditrating());
			numMonths = GetLoanMonths();
			getVal = GetValue("How much do you want to borrow? ");
			loanAmount = CalculateLoanAmount(getVal,loanInterest,numMonths);
			cout << "Interest Rate : " << loanInterest << endl;
			cout << "Principal : " << getVal << endl;
			cout << "Months : " << numMonths << endl;
			cout << "Your total loan amount is " << loanAmount << endl;
			break;
		default:
			break;
		}
		choice = MainMenu();
	}

	return 0;
}

