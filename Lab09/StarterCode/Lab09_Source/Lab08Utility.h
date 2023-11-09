#pragma once
#include <vector>
using namespace std;

struct itemInfo {
	string type;
	float cost;
};

vector<itemInfo> importCost(string filename);

void outputItemInfo(vector<itemInfo> vin);

float median(vector<itemInfo> vin);

void sortItemVector(vector<itemInfo>& vin);

float mean(vector<itemInfo> vin);

float total(vector<itemInfo> vin);

void printVector(vector<itemInfo> vin);