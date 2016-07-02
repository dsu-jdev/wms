#include "search.h"

using namespace std;

void search() {
	cout << "Nhap chuoi tim kiem: ";
	string query;
	__fpurge(stdin);
	getline(cin, query);
	string qr = replaceAll(query, " ", "-");
	int count = 0;
	list<Item>::iterator it;
	for (it = listOfItems.begin(); it != listOfItems.end(); it++) {
		Item item = *it;
		if ((int) item.name.find(qr) != -1) {
			cout << "Ma mat hang:	" << item.id << endl;
			cout << "Ten mat hang:	" << replaceAll(item.name, "-", " ") << endl;
			cout << "So luong:	" << item.quantity << endl << endl;
			count++;
		}
	}
	cout << "Tim duoc " << count << " mat hang voi tu khoa \"" << query << "\"" << endl;
	__fpurge(stdin);
	cin.get();
	return;
}
