#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "LibraryBook.h"


int main() {
	string title, author, ISBN;
	vector<LibraryBook> bookVector;
	ifstream inFS;
	ofstream outFS;

	inFS.open("books.txt");
	while (inFS.eof() == false && inFS.good()) {
		getline(inFS, title);
		getline(inFS, author);
		getline(inFS, ISBN);
		LibraryBook book(title, author, ISBN);
		bookVector.push_back(book);
	}
	inFS.close();
	inFS.open("isbns.txt");
	while (inFS.eof() == false && inFS.good()) {
		inFS >> ISBN;
		for (int i = 0; i < bookVector.size(); i++) {
			if (bookVector[i].getISBN() == ISBN) {
				if (bookVector[i].isCheckedOut() == true) {
					bookVector[i].checkIn();
				}
				else {
					bookVector[i].checkOut();
				}
			}
		}
	}

	outFS.open("checkedout.txt");
	outFS << "Books checked out:\n------------------\n\n\nTitle\tAuthor\tISBN\n";
	for (int i = 0; i < bookVector.size(); i++) {
		if (bookVector[i].isCheckedOut() == true) {
			outFS << bookVector[i].getTitle() << "\t" << bookVector[i].getAuthor() << "\t" << bookVector[i].getISBN() << "\n" << endl;
		}
	}
	outFS.close();

	return 0;
}