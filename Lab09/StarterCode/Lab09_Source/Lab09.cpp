#include <iostream>
#include <vector>
#include "Lab08Utility.h"

#include <string>
using namespace std;

int main() {
	vector<itemInfo> itemVector;
	itemVector = importCost("input1.txt");
	outputItemInfo(itemVector);
	return 0;
}