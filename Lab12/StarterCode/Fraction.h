#pragma once
// Kevin Yu
// April 10, 2023
// Lab 12

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;

public:
	Fraction();
	void reduce();
	int getNumerator();
	int getDenominator();
	void setNumerator(int newNum);
	void setDenominator(int newNum);

	// Originally wanted to put these definitions in Fraction.cpp,
	// but couldn't get it to work. Put them in .h instead.
	friend ostream& operator<< (ostream& output, const Fraction& fract) {
		output << fract.numerator;
		output << "/";
		output << fract.denominator;
		return output;
	}
	friend istream& operator>> (istream& input, Fraction& fract) {
		string slash;
		input >> fract.numerator;
		input >> slash;
		input >> fract.denominator;
		return input;
	}
	const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	bool operator==(Fraction rhs);
};

