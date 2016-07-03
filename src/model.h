#ifndef MODEL_H_
#define MODEL_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdio_ext.h>
#include <string>

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
	int id; // ma hoa don
	list<Item> items; // danh sach cac mat hang
	string date; // ngay thang nhap, xuat
};

extern list<Item> items;
extern list<Bill> bills;

void loadItem(char *);
void loadBill(char *);
void loadData();
Item getItemById(int);
void printItem(list<Item>);
const string currentDateTime();

#endif /* MODEL_H_ */
