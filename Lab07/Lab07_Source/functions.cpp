#include <fstream>
#include <vector>
#include <cmath>
#include "functions.h"

using namespace std;

vector<vector<double>> readCoordinateFromFile(string filename) {
	ifstream inFS;
	double tempX1, tempX2, tempY1, tempY2, tempZ1, tempZ2;
	vector<double> coordinates;
	vector<vector<double>> output;
	inFS.open(filename);
	while (!inFS.eof() && inFS.good()) {
		inFS >> tempX1 >> tempX2 >> tempY1 >> tempY2 >> tempZ1 >> tempZ2;
		if (!inFS.fail()) {
			coordinates.push_back(tempX1);
			coordinates.push_back(tempX2);
			coordinates.push_back(tempY1);
			coordinates.push_back(tempY2);
			coordinates.push_back(tempZ1);
			coordinates.push_back(tempZ2);
			output.push_back(coordinates);
			coordinates = {};
		}
	}
	return output;
}

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
	return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2)));
}

void sortVectorDouble(vector<double> &targetVector) {
	int vectorSize = targetVector.size();
	double temp;
	for (int i = 0; i < vectorSize - 1; i++) {
		if (targetVector[i] > targetVector[i + 1]) {
			temp = targetVector[i];
			targetVector[i] = targetVector[i + 1];
			targetVector[i + 1] = temp;
		}
	}
}

void writeToFile(vector<double> targetVector,string filename) {
	ofstream outFS;
	int vectorSize = targetVector.size();
	outFS.open(filename);
	outFS << targetVector[0];	// Separated this to not leave newline at the end.
	for (int i = 1; i < vectorSize; i++) {
		outFS << endl << targetVector[i];
	}
	outFS.close();
}