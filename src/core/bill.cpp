#include "../header/bill.h"

list<Bill> bills;

void viewBills() {
	list<Bill>::iterator it;
	for (it = bills.begin(); it != bills.end(); it++) {
		Bill b = *it;
		cout << b.type << endl;
		cout << b.date << endl;
	}
}
