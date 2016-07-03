#include "../header/bill.h"

list<Bill> bills;

void viewBills() {
	list<Bill>::iterator it;
	for (it = bills.begin(); it != bills.end(); it++) {
		Bill b = *it;
		if (b.type == 1) {
			cout << "Nhap hang" << endl;
		}
		cout << b.id << endl;
		cout << b.date << endl;
	}
}
