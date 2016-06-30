#include "model.h"

using namespace std;

// mat hang
struct Item {
	int id; // ma mat hang
	string name; // ten mat hang
	int quantity; // so luong
};

// hoa don nhap, xuat hang
struct Bill {
	int type; // kieu hoa don, type = 1: hoa don nhap hang, type = 2: hoa don xuat hang
	Item items[]; // danh sach cac mat hang
	string date; // ngay thang nhap, xuat
};
