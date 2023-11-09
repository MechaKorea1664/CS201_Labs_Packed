#pragma once
#include <vector>
using namespace std;

vector<vector<double>> readCoordinateFromFile(string filename);

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2);

void sortVectorDouble(vector<double>& targetVector);

void writeToFile(vector<double> targetVector, string filename);