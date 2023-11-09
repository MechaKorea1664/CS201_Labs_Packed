#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	char letter;
	Node* nextPtr;
};

Node* fillList(string);

void printList(vector<Node*>);

Node* removeCharacter(Node* head, char);