#include "../header/addNew.h"

Bill billImport;

void addNew() {
	cout << "Ten mat hang: ";
	string name;
	cin.ignore();
	getline(cin, name);
	cout << "So luong: ";
	int quantity;
	cin >> quantity;

	Item item;

	if (items.empty()) {
		item.id = 1;
	} else {
		Item lastItem = items.back();
		item.id = lastItem.id + 1;
	}

	item.name = name;
	item.quantity = quantity;
	items.push_back(item);

	fstream ofs;
	ofs.open("src//input.txt", fstream::in | fstream::out | fstream::app);
	ofs << item.id << endl;
	ofs << item.name << endl;
	ofs << item.quantity << endl;
	ofs.close();

	if (bills.empty()) {
		billImport.id = 1;
	} else {
		Bill lastBill = bills.back();
		billImport.id = lastBill.id + 1;
	}

	billImport.type = 1;
	billImport.items.push_back(item);

	cout << "Nhap tiep? (Y/N): ";
	cin.ignore();
	char c = cin.get();
	if (c == 'y' || c == 'Y') {
		addNew();
	} else {
		billImport.date = currentDateTime();
		bills.push_back(billImport);
		return;
	}
}
