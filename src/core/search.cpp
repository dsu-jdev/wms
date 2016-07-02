#include "search.h"

using namespace std;

void search() {
	cout << "Nhap chuoi tim kiem: ";
	string query;
	cin.ignore();
	getline(cin, query);
	int count = 0;
	list<Item>::iterator it;
	for (it = listOfItems.begin(); it != listOfItems.end(); it++) {
		Item item = *it;
		if ((int) item.name.find(query) != -1) {
			cout << "Ma mat hang:	" << item.id << endl;
			cout << "Ten mat hang:	" << item.name << endl;
			cout << "So luong:	" << item.quantity << endl << endl;
			count++;
		}
	}
	cout << "Tim duoc " << count << " mat hang voi tu khoa \"" << query << "\"" << endl;
	return;
}
