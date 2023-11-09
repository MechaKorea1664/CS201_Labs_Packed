#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class StudentInfo {
private:
	string name;
	StudentInfo* nextStudentPtr;
public:
	StudentInfo(string value, StudentInfo* nextItem) { name = value; nextStudentPtr = nextItem; }
	string getName() { return name; }
	StudentInfo* getNextStudent() { return nextStudentPtr; }
	void setNextStudent(StudentInfo* item) { nextStudentPtr = item; }
};

int main() {

	// Declare any extra variables needed
	StudentInfo* head = nullptr;
	ifstream fin("input7.txt");
	StudentInfo* currStudent;
	StudentInfo* prevStudent;
	if (!fin.is_open()) {
		cout << "Could not open the input file input1.txt" << endl;
		return -1;
	}

	while (!fin.eof()) {
		string item, command;
		fin >> item >> command;

		// Logic of handling the input.
		if (command == "add") {
			StudentInfo* newStudent = new StudentInfo(item, nullptr);
			if (head == nullptr) {
				head = newStudent;
			}
			else {
				currStudent = head;
				prevStudent = nullptr;
				while (currStudent != nullptr && currStudent->getName() < item) {
					prevStudent = currStudent;
					currStudent = currStudent->getNextStudent();
				}
				if (prevStudent == nullptr) {
					newStudent->setNextStudent(head);
					head = newStudent;
				}
				else {
					prevStudent->setNextStudent(newStudent);
					newStudent->setNextStudent(currStudent);
				}
			}
		}
		else if (command == "del") {
			currStudent = head;
			prevStudent = nullptr;
			while (currStudent != nullptr && currStudent->getName() != item) {
				prevStudent = currStudent;
				currStudent = currStudent->getNextStudent();
			}
			if (currStudent != nullptr) {
				if (prevStudent == nullptr) {
					head = currStudent->getNextStudent();
				}
				else {
					prevStudent->setNextStudent(currStudent->getNextStudent());
				}
				delete currStudent;
			}
		}
	}
	fin.close();

	// Output the final linked list.
	StudentInfo* currptr = head;
	while (currptr != nullptr) {
		cout << "->" << currptr->getName();
		currptr = currptr->getNextStudent();
	}

	// Free up all memory.
	while (head != nullptr) {
		StudentInfo* temp = head;
		head = head->getNextStudent();
		delete temp;
	}
}