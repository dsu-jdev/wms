#include "addNew.h"

void addNew() {
	cout << "Ten mat hang: ";
	string name;
	__fpurge(stdin);
	getline(cin, name);
	cout << "So luong: ";
	int quantity;
	cin >> quantity;

	Item lastItem = listOfItems.back();
	Item item;

	item.id = lastItem.id + 1;
	item.name = replaceAll(name, " ", "-");
	item.quantity = quantity;
	listOfItems.push_back(item);

	fstream ofs;
	ofs.open("src//input.txt", fstream::in | fstream::out | fstream::app);
	ofs << item.id << endl;
	ofs << item.name << endl;
	ofs << item.quantity << endl;
	ofs.close();
	cout << "Nhap tiep? (Y/N): ";
	__fpurge(stdin);
	char c = cin.get();
	if (c == 'y' || c == 'Y') {
		addNew();
	} else {
		return;
	}
}
