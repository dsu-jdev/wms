#include "../header/edit.h"

void edit() {
//	search();
	cout << "Nhap ma mat hang can sua ([0] - Huy bo): ";
	int input;
	cin >> input;
	if (input == 0) {
		return;
	}

	Item itemToEdit = getItemById(input);

	cout << "Ten mat hang: \"" << itemToEdit.name << "\" > ";
	string nameToEdit;
	__fpurge(stdin);
	getline(cin, nameToEdit);

	cout << "So luong: \"" << itemToEdit.quantity << "\" > ";
	int quantityToEdit;
	cin >> quantityToEdit;

	ifstream ifs("src//input.txt");
	ofstream temp("src//temp.txt");
	int id;
	while (ifs >> id) {
		string name;
		int quantity;

		ifs.ignore();
		getline(ifs, name);
		ifs >> quantity;

		temp << id << endl;
		if (id != input) {
			temp << name << endl;
			temp << quantity << endl;
		} else {
			temp << nameToEdit << endl;
			temp << quantityToEdit << endl;
		}
	}
	remove("src//input.txt");
	rename("src//temp.txt", "src//input.txt");
	cout << "Sua thong tin mat hang thanh cong" << endl;
	loadItem("src//input.txt");

	cout << "Sua tiep? (Y/N): ";
	__fpurge(stdin);
	char c = cin.get();
	if (c == 'y' || c == 'Y') {
		edit();
	} else {
		return;
	}
}
