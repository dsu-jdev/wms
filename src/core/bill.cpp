#include "../header/bill.h"

list<Bill> bills;

void viewBills() {
	cout << "	1. Hoa don nhap hang" << endl;
	cout << "	2. Hoa don xuat hang" << endl;

	int input;
	cin >> input;

	list<Bill>::iterator iterBill;
	for (iterBill = bills.begin(); iterBill != bills.end(); iterBill++) {
		Bill bill = *iterBill;
		if (bill.type == input) {
			cout << "Nhap hang" << endl;
			cout << "Ma hoa don: " << bill.id << endl;
			cout << "Ngay nhap: " << bill.date << endl;
			printItem(bill.items);
		}
	}
}
