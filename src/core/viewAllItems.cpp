#include "../header/viewAllItems.h"

void viewAllItems() {
	printItem(items);
	__fpurge(stdin);
	cin.get();
	return;
}
