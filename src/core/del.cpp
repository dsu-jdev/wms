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

	cout << "So luong (trong kho con " << itemToDelete.quantity << "): ";
	int qttToDel;
	cin >> qttToDel;

	ifstream ifs("src//input.txt");
	ofstream temp("src//temp");
	ofstream tempBill("src//tempBill");
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
			tempBill << id << endl;
			tempBill << name << endl;

			if (qttToDel < itemToDelete.quantity) {
				temp << id << endl;
				temp << name << endl;
				temp << quantity - qttToDel << endl;
				cout << "Da xoa " << qttToDel << " mat hang " << itemToDelete.name << endl;

				tempBill << qttToDel << endl;
			} else {
				cout << "Da xoa mat hang \"" << itemToDelete.name << "\" khoi danh sach" << endl;

				tempBill << quantity << endl;
			}
		}
	}
	remove("src//input.txt");
	rename("src//temp", "src//input.txt");
	loadItem("src//input.txt");

	if (bills.empty()) {
		billExport.id = 1;
	} else {
		Bill lastBill = bills.back();
		billExport.id = lastBill.id + 1;
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
		billExport.items.clear();

		fstream ofsBill;
		ofsBill.open("src//bills.txt", fstream::in | fstream::out | fstream::app);
		ofsBill << billExport.type << endl;
		ofsBill << billExport.id << endl;

		ifstream ifs("src//tempBill");
		string str;
		while (getline(ifs, str)) {
			ofsBill << str << endl;
		}

		remove("src//tempBill");
		ofsBill << -1 << endl;
		ofsBill << billExport.date << endl;
		ofsBill.close();
		return;
	}
}
