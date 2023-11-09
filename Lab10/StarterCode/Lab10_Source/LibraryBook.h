#pragma once

#include <iostream>
#include "LibraryBook.h"

using namespace std;

class LibraryBook {

public:
	LibraryBook(string title, string author, string ISBN);
	string getTitle();
	string getAuthor();
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();

private:
	bool checkedOut;
	string title = "";
	string author = "";
	string ISBN = "";
};