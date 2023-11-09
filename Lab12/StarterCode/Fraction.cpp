// Kevin Yu
// April 10, 2023
// Lab 12

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}
}

int Fraction::getNumerator() {
	return numerator;
}

int Fraction::getDenominator() {
	return denominator;
}

void Fraction::setNumerator(int newNum) {
	numerator = newNum;
}

void Fraction::setDenominator(int newNum) {
	denominator = newNum;
}

const Fraction Fraction::operator+(Fraction rhs) {
	Fraction newFrac;
	int newNum, newDenom;
	newNum = (numerator * rhs.getDenominator()) + (rhs.getNumerator() * denominator);
	newDenom = (denominator * rhs.getDenominator());
	newFrac.setNumerator(newNum);
	newFrac.setDenominator(newDenom);
	newFrac.reduce();
	return newFrac;
}

const Fraction Fraction::operator-(Fraction rhs) {
	Fraction newFrac;
	int newNum, newDenom;
	newNum = (numerator * rhs.getDenominator()) - (rhs.getNumerator() * denominator);
	newDenom = denominator * rhs.getDenominator();
	newFrac.setNumerator(newNum);
	newFrac.setDenominator(newDenom);
	newFrac.reduce();
	return newFrac;
}

const Fraction Fraction::operator*(Fraction rhs) {
	Fraction newFrac;
	newFrac.setNumerator(numerator * rhs.numerator);
	newFrac.setDenominator(denominator * rhs.getDenominator());
	newFrac.reduce();
	return newFrac;
}

const Fraction Fraction::operator/(Fraction rhs) {
	Fraction newFrac;
	newFrac.setNumerator(numerator * rhs.getDenominator());
	newFrac.setDenominator(denominator * rhs.getNumerator());
	newFrac.reduce();
	return newFrac;
}

bool Fraction::operator==(Fraction rhs) {
	reduce();
	rhs.reduce();
	return ((numerator == rhs.getNumerator()) && (denominator == rhs.getDenominator()));
}
