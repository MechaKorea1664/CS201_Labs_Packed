#pragma once
#include <string>
using namespace std;

void deposit(float& account, float amount);

char MainMenu();

float GetValue(string userPrompt);

float GetValue(string userPrompt, float upperLimit);

float GetInterestRate(int creditScore);

void Withdraw(float& accountBalance, float amountWithdraw);

int GetLoanMonths();

int GetCreditrating();

float CalculateLoanAmount(float principal, float interest, int numMonth);

void OutputAccount(float amount);