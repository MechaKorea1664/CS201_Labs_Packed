#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

void printMatrix(vector<vector<int>> matrix) {
	int numRow, numColumn;
	numRow = matrix.size();
	numColumn = matrix[0].size();
	
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numColumn; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector< vector<int> > createMatrix() {
	int numRow, numColumn, numInput;
	vector<int> matrixRow;
	vector< vector<int> > matrix;
	cout << "Enter the number of rows in the matrix >>> ";
	cin >> numRow;
	cout << endl << "Enter the number of columns in this matrix >>> ";
	cin >> numColumn;
	
	cout << endl << "Please enter the values in this matrix. You can enter each row at once, each cell or all of them separated by spaces." << endl;
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numColumn; j++) {
			cin >> numInput;
			matrixRow.push_back(numInput);
		}
		matrix.push_back(matrixRow);
		matrixRow = {};
	}
	return matrix;
}

vector<vector<int>> addMatrix(vector<vector<int>> g1, vector<vector<int>> g2) {
	int numRowG1, numRowG2, numColumnG1, numColumnG2;
	vector<int> matrixRow;
	vector<vector<int>> matrix;

	numRowG1 = g1.size();
	numRowG2 = g2.size();
	numColumnG1 = g1[0].size();
	numColumnG2 = g2[0].size();

	if ((numRowG1 != numRowG2) || (numColumnG1 != numColumnG1)) {
		cout << "Cannot add 2 grids of this size together, the # of rows and columns in each must be the same." << endl;
		return { {} };
	}
	else {
		for (int i = 0; i < numRowG1; i++) {
			for (int j = 0; j < numColumnG1; j++) {
				matrixRow.push_back(g1[i][j] + g2[i][j]);
			}
			matrix.push_back(matrixRow);
			matrixRow = {};
		}
		return matrix;
	}
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> g1, vector<vector<int>> g2) {
	int numRowG1, numRowG2, numColumnG1, numColumnG2, multVal = 0;
	vector<int> matrixRow;
	vector<vector<int>> matrix;

	numRowG1 = g1.size();
	numRowG2 = g2.size();
	numColumnG1 = g1[0].size();
	numColumnG2 = g2[0].size();

	if (numColumnG1 == numRowG2) {
		for (int i = 0; i < numRowG1; i++) {
			for (int j = 0; j < numColumnG2; j++) {
				for (int l = 0; l < numColumnG1; l++) {
					multVal += g1[i][l] * g2[l][j];
				}
				matrixRow.push_back(multVal);
				multVal = 0;
			}
			matrix.push_back(matrixRow);
			matrixRow = {};
		}
		return matrix;
	}
	else {
		cout << "Multiplication not possible." << endl;
		return { {} };
	}
}