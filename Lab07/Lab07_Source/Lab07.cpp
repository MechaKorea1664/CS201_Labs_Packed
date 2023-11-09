#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
	vector<vector<double>> coordinates;
	vector<double> distanceVector;
	double distance;
	
	coordinates = readCoordinateFromFile("input.txt");
	for (int i = 0; i < coordinates.size(); i++) {
		distance = calcDistance(coordinates[i][0], coordinates[i][1], 
			coordinates[i][2], coordinates[i][3], coordinates[i][4], coordinates[i][5]);
		distanceVector.push_back(distance);
	}
	sortVectorDouble(distanceVector);
	writeToFile(distanceVector, "output_sorted.txt");

	return 0;
}