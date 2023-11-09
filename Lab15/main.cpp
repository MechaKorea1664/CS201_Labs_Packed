#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main() {
	ifstream inFS;
	vector<Node*> headerList;
	string line;
	inFS.open("input.txt");
	while (getline(inFS, line)) {
		if (line != "END")
			headerList.push_back(fillList(line));
	}
	for (int i = 0; i < headerList.size(); i++) {
		headerList[i] = removeCharacter(headerList[i], 'a');
		headerList[i] = removeCharacter(headerList[i], 'A');
		headerList[i] = removeCharacter(headerList[i], 'e');
		headerList[i] = removeCharacter(headerList[i], 'E');
		headerList[i] = removeCharacter(headerList[i], 'i');
		headerList[i] = removeCharacter(headerList[i], 'I');
		headerList[i] = removeCharacter(headerList[i], 'o');
		headerList[i] = removeCharacter(headerList[i], 'O');
		headerList[i] = removeCharacter(headerList[i], 'u');
		headerList[i] = removeCharacter(headerList[i], 'U');
	}
	printList(headerList);
	return 0;
}