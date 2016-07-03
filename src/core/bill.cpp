#include "../header/bill.h"

list<Bill> bills;

void viewBills() {
	cout << "	1. Hoa don nhap hang" << endl;
	cout << "	2. Hoa don xuat hang" << endl;

	int input;
	cin >> input;

	string type;
	if (input == 1) {
		type = "nhap";
	}
	if (input == 2) {
		type = "xuat";
	}

	bool isHaveBill = false;

	list<Bill>::iterator iterBill;
	for (iterBill = bills.begin(); iterBill != bills.end(); iterBill++) {
		Bill bill = *iterBill;
		if (bill.type == input) {
			isHaveBill = true;
			cout << "Ma hoa don: " << bill.id << endl;
			cout << "Ngay " + type + ": " << bill.date << endl;
			printItem(bill.items);
		}
		cout << endl;
	}

	if (!isHaveBill) {
		cout << "Khong co hoa don " + type + " hang";
	}
	cin.ignore();
	cin.get();
	return;
}
