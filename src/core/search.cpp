#include "search.h"

using namespace std;

string replaceAll(string str, string s, string t) {
	int pos;
	while ((pos = str.find(s)) != -1) {
		str.replace(pos, 1, t);
	}
	return str;
}

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
			cout << "Ten mat hang:	" << item.name << endl;
			cout << "So luong:	" << item.quantity << endl << endl;
			count++;
		}
	}
	cout << "Tim duoc " << count << " mat hang voi tu khoa \"" << query << "\"" << endl << endl;
}
