#include <iostream>
#include "LibraryBook.h"

using namespace std;

LibraryBook::LibraryBook(string newTitle, string newAuthor, string newISBN) {
	this->title = newTitle;
	this->author = newAuthor;
	this->ISBN = newISBN;
	this->checkedOut = false;
}
string LibraryBook::getTitle() {
	return this->title;
}
string LibraryBook::getAuthor() {
	return this->author;
}
string LibraryBook::getISBN() {
	return this->ISBN;
}
void LibraryBook::checkOut() {
	this->checkedOut = true;
}
void LibraryBook::checkIn() {
	this->checkedOut = false;
}
bool LibraryBook::isCheckedOut() {
	return this->checkedOut;
}
