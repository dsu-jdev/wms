#include "../header/del.h"

Bill billExport;

void del() {
	search();
	cout << "Nhap ma mat hang can xoa ([0] - Huy bo): ";
	int input;
	cin >> input;
	if (input == 0) {
		return;
	}

	Item itemToDelete = getItemById(input);

	cout << "So luong (trong kho con " + itemToDelete.quantity + "): ";
	int qttToDel;
	cin >> qttToDel;

	ifstream ifs("src//input.txt");
	ofstream temp("src//temp.txt");
	int id;
	while (ifs >> id) {
		string name;
		int quantity;

		ifs.ignore();
		getline(ifs, name);
		ifs >> quantity;

		if (id != input) {
			temp << id << endl;
			temp << name << endl;
			temp << quantity << endl;
		} else {
			if (qttToDel < itemToDelete.quantity) {
				temp << id << endl;
				temp << name << endl;
				temp << quantity - qttToDel << endl;
				cout << "Da xoa " + qttToDel + " mat hang " + itemToDelete.name << endl;
			} else {
				cout << "Da xoa mat hang \"" + itemToDelete.name + "\" khoi danh sach" << endl;
			}
		}
	}
	remove("src//input.txt");
	rename("src//temp.txt", "src//input.txt");
	loadItemData("src//input.txt");

	if (bills.empty()) {
		billImport.id = 1;
	} else {
		Bill lastBill = bills.back();
		billImport.id = lastBill.id + 1;
	}

	billExport.type = 2;
	billExport.items.push_back(itemToDelete);

	cout << "Xoa tiep? (Y/N): ";
	cin.ignore();
	char c = cin.get();
	if (c == 'y' || c == 'Y') {
		del();
	} else {
		billExport.date = currentDateTime();
		bills.push_back(billExport);
		return;
	}
}
