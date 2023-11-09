#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;

Node* fillList(string word) {
	Node* head = nullptr;
	Node* next = nullptr;
	Node* prev = nullptr;
	for (int i = 0; i < word.length(); i++) {
		if (head == nullptr) {
			head = new Node;
			head->letter = word[0];
			head->nextPtr = nullptr;
		}
		else {
			prev = head;
			next = head->nextPtr;
			while (next != nullptr) {
				prev = next;
				next = next->nextPtr;
			}
			next = new Node;
			next->letter = word[i];
			next->nextPtr = nullptr;
			prev->nextPtr = next;
		}
	}

	return head;
}

void printList(vector<Node*> head) {
	Node* next = nullptr;
	ofstream outFS;
	outFS.open("output.txt");
	for (int i = 0; i < head.size(); i++) {
		next = head[i];
		while (next != nullptr) {
			outFS << "[" << next->letter << "] -> ";
			next = next->nextPtr;
		}
		outFS << "0\n\n";
	}
	outFS.close();
}

Node* removeCharacter(Node* head, char targetChar) {
	Node* next = head;
	Node* prev = head;
	Node* temp = nullptr;
	while (next != nullptr) {
		if (next->letter == targetChar && next == head) {
			next = head->nextPtr;
			delete head;
			head = next;
			prev = head;
		}
		else if (next->letter == targetChar) {
			temp = next;
			next = next->nextPtr;
			delete temp;
			temp = nullptr;
			prev->nextPtr = next;
		}
		else {
			prev = next;
			next = next->nextPtr;
		}
	}
	return head;
}