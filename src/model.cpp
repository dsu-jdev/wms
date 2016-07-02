#include "model.h"

list<Item> listOfItems;

void loadData(char *fileName) {
	try {
		ifstream ifs(fileName);
		int id;
		while (ifs >> id) {
			Item item;
			item.id = id;
			ifs >> item.name;
			ifs >> item.quantity;
			listOfItems.push_back(item);
		}
	}catch(const std::exception &exc) {
		cerr << exc.what();
	}
}

Item getItemById(int id) {
	list<Item>::iterator it;
	for (it = listOfItems.begin(); it != listOfItems.end(); it++) {
		Item i = *it;
		if (i.id == id) {
			return i;
		}
	}
	Item temp;
	return temp;
}

string replaceAll(string str, string s, string t) {
	int pos;
	while ((pos = str.find(s)) != -1) {
		str.replace(pos, 1, t);
	}
	return str;
}
