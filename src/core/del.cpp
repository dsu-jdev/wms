#include "del.h"

void del() {
	search();
	cout << "Nhap ma mat hang can xoa ([0] - Huy bo): ";
	int input;
	cin >> input;
	if (input == 0) {
		return;
	}

	Item itemToDelete = getItemById(input);

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
		}
	}
	remove("src//input.txt");
	rename("src//temp.txt", "src//input.txt");
	cout << "Da xoa mat hang \"" + itemToDelete.name + "\" khoi danh sach" << endl;
	loadData("src//input.txt");

	cout << "Xoa tiep? (Y/N): ";
	cin.ignore();
	char c = cin.get();
	if (c == 'y' || c == 'Y') {
		del();
	} else {
		return;
	}
}
