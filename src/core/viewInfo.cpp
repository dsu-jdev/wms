#include "../header/viewInfo.h"

void viewInfo() {
	cout << "Ma MH | Ten mat hang | So luong" << endl;
	cout << "-------------------------------" << endl;
	list<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		Item item = *it;
		cout << item.id << " | " << item.name << " | " << item.quantity << endl;
	}
	cin.ignore();
	cin.get();
	return;
}
