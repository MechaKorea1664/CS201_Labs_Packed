#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Lab08Utility.h"

using namespace std;

vector<itemInfo> importCost(string filename) {
	ifstream inFS;
	itemInfo currItem;
	vector<itemInfo> output;
	string element;
	float cost;
	
	inFS.open(filename);
	while (inFS.eof() != true && inFS.good()) {
		inFS >> currItem.type;
		inFS >> currItem.cost;
		output.push_back(currItem);
	}
	return output;
}

void outputItemInfo(vector<itemInfo> vin) {
	vector<itemInfo> DVDvector, TVvector, MUSICvector;
	ofstream outFS;

	for (int i = 0; i < vin.size(); i++) {
		if (vin[i].type == "DVD") {
			DVDvector.push_back(vin[i]);
		}
		else if (vin[i].type == "TV") {
			TVvector.push_back(vin[i]);
		}
		else if (vin[i].type == "MUSIC") {
			MUSICvector.push_back(vin[i]);
		}
	}

	outFS.open("output.txt");

	outFS << "DVD\t" << total(DVDvector) << "\t" << median(DVDvector) << "\t" << mean(DVDvector) << endl;
	outFS << "TV\t" << total(TVvector) << "\t" << median(TVvector) << "\t" << mean(TVvector) << endl;
	outFS << "MUSIC\t" << total(MUSICvector) << "\t" << median(MUSICvector) << "\t" << mean(MUSICvector) << endl;

	outFS.close();
}

float median(vector<itemInfo> vin) {
	try {
		int size = vin.size(), smallestIndex;

		if (size == 0) {
			throw runtime_error("No values in vector.");
		}

		sortItemVector(vin);
		
		if (size % 2 != 0) {
			return vin[size / 2].cost;
		}
		else if (size % 2 == 0) {
			int medianIndex = (size / 2)-1;
			return (vin[medianIndex].cost + vin[medianIndex + 1].cost) / 2;
		}
	}
	catch (runtime_error e) {
		// cout << e.what() << endl;
		return NAN;
	}
}

void sortItemVector(vector<itemInfo>& vin) {
	int size = vin.size(), smallestIndex = 0;
	float temp, smallest = vin[0].cost;
	bool isSmall = false;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (vin[j].cost < smallest) {
				smallest = vin[j].cost;
				smallestIndex = j;
				isSmall = true;
			}
		}
		if (isSmall) {
			temp = vin[smallestIndex].cost;
			vin[smallestIndex] = vin[i];
			vin[i].cost = temp;
			if (i != size - 1) {
				smallest = vin[i + 1].cost;
				isSmall = false;
			}
			else
				break;
		}
		else
			break;
	}
}

float mean(vector<itemInfo> vin) {
	try {
		int size = vin.size();
		float total = 0;
		
		if (size == 0) {
			throw runtime_error("No values in vector.");
		}

		for (int i = 0; i < size; i++) {
			total += vin[i].cost;
		}

		return total / size;
	}
	catch (runtime_error e) {
		// cout << e.what() << endl;
		return NAN;
	}
}

float total (vector<itemInfo> vin) {
	int size = vin.size();
	
	if (size == 0) {
		return 0;
	}
	
	float total = 0;
	for (int i = 0; i < size; i++) {
		total += vin[i].cost;
	}

	return total;
}

void printVector(vector<itemInfo> vin) {
	try {
		int size = vin.size();
		if (size == 0) {
			throw runtime_error("No value in vector.");
		}
		for (int i = 0; i < size; i++) {
			cout << vin[i].cost << " ";
		}
		cout << endl;
	}
	catch (runtime_error e) {
		cout << "NULL" << endl;
	}
}