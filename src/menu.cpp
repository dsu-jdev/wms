#include "menu.h"

using namespace std;

void menu() {
	cout << "CHUONG TRINH QUAN LY KHO HANG" << endl;
	cout << "1. Tim kiem mat hang" << endl;
	cout << "2. Nhap them mat hang" << endl;
	cout << "3. Xoa mat hang" << endl;
	cout << "4. Xem thong tin cac mat hang" << endl;
	cout << "5. Sua thong tin mat hang" << endl;
	cout << "6. Cap nhat mat hang moi" << endl;
	cout << "7. Xem hoa don" << endl;
	cout << "8. Thoat chuong trinh" << endl;

	int input;
	cin >> input;

	switch (input) {
	case 1:
		search();
		cin.get();
		break;
	case 2:
		addNew();
		break;
	case 3:
		del();
		break;
	case 4:
		viewInfo();
		break;
	case 5:
		edit();
		break;
	case 6:
		update();
		break;
	case 7:
		viewBills();
		break;
	case 8:
		exit(0);
		break;
	}
	menu();
}
