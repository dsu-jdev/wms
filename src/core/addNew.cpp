#include "../header/addNew.h"

Bill billImport;

void addNew() {
	Item item;

	if (items.empty()) {
		item.id = 1;
	} else {
		Item lastItem = items.back();
		item.id = lastItem.id + 1;
	}

	cout << "Ten mat hang: ";
	cin.ignore();
	getline(cin, item.name);
	cout << "So luong: ";
	cin >> item.quantity;

	items.push_back(item);

	fstream ofsItem;
	fstream temp;
	ofsItem.open("src//input.txt", fstream::in | fstream::out | fstream::app);
	temp.open("src//temp.txt", fstream::in | fstream::out | fstream::app);
	ofsItem << item.id << endl;
	temp << item.id << endl;
	ofsItem << item.name << endl;
	temp << item.name << endl;
	ofsItem << item.quantity << endl;
	temp << item.quantity << endl;
	ofsItem.close();
	temp.close();

	cout << "Da nhap " + item.quantity + " mat hang " + item.name << endl;

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
		fstream ofsBill;
		ofsBill.open("src//bills.txt", fstream::in | fstream::out | fstream::app);
		ofsBill << billImport.type;
		ofsBill << billImport.id;

		ifstream
		while ()
		ofsBill.close();
		billImport.date = currentDateTime();
		bills.push_back(billImport);
		return;
	}
}
