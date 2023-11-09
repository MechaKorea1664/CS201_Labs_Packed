#include <iostream>
#include <string>

using namespace std;

struct ticketPerGroup{
	string groupName = "Default_Name";
	int numSoldTicket = 0;
	double ticketCost = 0;
} ;

void printMenu() {
	cout << "Enter (C)hild, (A)dult, ";
	cout << "(S)enior, (V)IP or (Q)uit >> ";
}

double printTicketPerGroupAndReturnTicketPrice(ticketPerGroup tpgInput) {
	double ticketPrice = tpgInput.ticketCost * tpgInput.numSoldTicket;
	cout << "\t" << tpgInput.groupName << " " << tpgInput.numSoldTicket << " @ ";
	cout << tpgInput.ticketCost << " = " << ticketPrice << endl;
	return ticketPrice;
}

int main() {
	int numDay = 1;
	int numTicket = 0;
	double totalCost = 0;
	double allDayTotalCost = 0;
	char choice;
	ticketPerGroup childGroup;
	ticketPerGroup adultGroup;
	ticketPerGroup seniorGroup;
	ticketPerGroup vipGroup;

	childGroup.groupName = "Child";
	adultGroup.groupName = "Adult";
	seniorGroup.groupName = "Senior";
	vipGroup.groupName = "VIP";

	childGroup.ticketCost = 10.95;
	adultGroup.ticketCost = 19.99;
	seniorGroup.ticketCost = 18.99;
	vipGroup.ticketCost = 7.99;

	cout << "Welcome to Fun Park Menu System !!" << endl;
	while (numDay <= 3){
		cout << "Starting day " << numDay << endl;
		printMenu();
		cin >> choice;
		while (toupper(choice) != 'Q') {
			switch (toupper(choice)) {
			case 'A':
				cout << "\nHow many adults? >> ";
				cin >> numTicket;
				adultGroup.numSoldTicket += numTicket;
				break;
			case 'C':
				cout << "\nHow many children? >> ";
				cin >> numTicket;
				childGroup.numSoldTicket += numTicket;
				break;
			case 'S':
				cout << "\nHow many seniors? >> ";
				cin >> numTicket;
				seniorGroup.numSoldTicket += numTicket;
				break;
			case 'V':
				cout << "\nHow many VIPs? >> ";
				cin >> numTicket;
				vipGroup.numSoldTicket += numTicket;
				break;
			}
			cout << endl;
			printMenu();
			cin >> choice;
		}
		cout << "\nDay " << numDay << endl;
		totalCost += printTicketPerGroupAndReturnTicketPrice(childGroup);
		totalCost += printTicketPerGroupAndReturnTicketPrice(adultGroup);
		totalCost += printTicketPerGroupAndReturnTicketPrice(seniorGroup);
		totalCost += printTicketPerGroupAndReturnTicketPrice(vipGroup);
		cout << "\n\tTotal = " << totalCost << endl;
		cout << endl;
		
		allDayTotalCost += totalCost;
		totalCost = 0;
		childGroup.numSoldTicket = 0;
		adultGroup.numSoldTicket = 0;
		seniorGroup.numSoldTicket = 0;
		vipGroup.numSoldTicket = 0;
		
		numDay += 1;
	}

	cout << "\n\nThe total for all days is " << allDayTotalCost << endl;
	return 0;
}