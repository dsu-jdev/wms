#include "model.h"

list<Item> items;

void loadItemData(char *fileName) {
	try {
		items.clear();
		ifstream ifs(fileName);
		int id;
		while (ifs >> id) {
			Item item;
			item.id = id;
			ifs.ignore();
			getline(ifs, item.name);
			ifs >> item.quantity;
			items.push_back(item);
		}
	} catch (const std::exception &exc) {
		cerr << exc.what();
	}
}

void loadBillData(char *fileName) {
	try {
		bills.clear();
		ifstream ifs(fileName);
		int type;
		while (ifs >> type) {
			Bill bill;
			bill.type = type;
			ifs >> bill.id;
			int itemId;
			ifs >> itemId;
			while (itemId != -1) {
				Item item;
				item.id = itemId;
				ifs.ignore();
				getline(ifs, item.name);
				ifs >> item.quantity;
				bill.items.push_back(item);
				ifs >> itemId;
			}
			ifs.ignore();
			getline(ifs, bill.date);
		}
	} catch (const exception &exc) {
		cerr << exc.what();
	}
}

Item getItemById(int id) {
	list<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		Item i = *it;
		if (i.id == id) {
			return i;
		}
	}
	Item temp;
	temp.id = -1;
	return temp;
}

void printItem(list<Item> items) {
	cout << "Ma MH |         Ten mat hang           | So luong" << endl;
	cout << "------+--------------------------------+---------" << endl;
	list<Item>::iterator iterItem;
	for (iterItem = items.begin(); iterItem != items.end(); iterItem++) {
		Item item = *iterItem;
		cout << setw(4) << right << item.id << "  | " << setw(30) << left << item.name << " | " << setw(7) << right << item.quantity << endl;
	}
}

const string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}
