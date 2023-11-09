#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

int main() {
	vector<vector<int>> g1, g2, addedMatrix, multipliedMatrix;
	char choice = 'A';
	while (toupper(choice) != 'Q'){
		g1 = createMatrix();
		cout << "You entered the grid g1 as" << endl;
		printMatrix(g1);

		g2 = createMatrix();
		cout << "You entered grid g2 as" << endl;
		printMatrix(g2);

		addedMatrix = addMatrix(g1,g2);
		if (!addedMatrix[0].empty()) {
			cout << "g1 + g2 is" << endl;
			printMatrix(addedMatrix);
		}
				

		multipliedMatrix = multiplyMatrix(g1, g2);
		if (!multipliedMatrix[0].empty()) {
			cout << "g1 * g2 is" << endl;
			printMatrix(multipliedMatrix);
		}

		cout << "Press Q to quit, any other key to do another grid." << endl;
		cin >> choice;
		g1,g2,addedMatrix,multipliedMatrix = { {} };
	}
	return 0;
}