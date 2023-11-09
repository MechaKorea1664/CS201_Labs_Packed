#pragma once
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix);

vector< vector<int> > createMatrix();

vector<vector<int>> addMatrix(vector<vector<int>> g1, vector<vector<int>> g2);

vector<vector<int>> multiplyMatrix(vector<vector<int>> g1, vector<vector<int>> g2);