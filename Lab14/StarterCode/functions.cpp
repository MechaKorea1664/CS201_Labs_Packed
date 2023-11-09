#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

long factorial_r(long value) {
	if (value == 0) {
		return 1;
	}
	else {
		return value * factorial_r(value - 1);
	}
}

int fibonacci_r(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return fibonacci_r(n - 1) + fibonacci_r(n - 2);
	}
}

bool is_prime_r(int value, int n) {
	if (sqrt(value) < n) {
		return true;
	}
	else if (value % n == 0) {
		return false;
	}
	else {
		return is_prime_r(value, n + 1);
	}
}

int sum_r(int list[], int list_size) {
	if (list_size == 0) {
		return 0;
	}
	else {
		return list[list_size - 1] + sum_r(list, list_size - 1);
	}
}

void output_reverse_list_r(int list[], int list_size) {
	if (list_size == 1) {
		cout << list[list_size-1];
	}
	else {
		cout << list[list_size - 1] << " ";
		return output_reverse_list_r(list, list_size - 1);
	}
}