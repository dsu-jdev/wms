#include "model.h"

list<Item> items;

void loadData(char *fileName) {
	try {
		items.clear();
		ifstream ifs(fileName);
		int id;
		while (ifs >> id) {
			Item item;
			item.id = id;
			ifs.ignore();
			getline(ifs, item.name);
			ifs >> item.quantity;
			items.push_back(item);
		}
	}catch(const std::exception &exc) {
		cerr << exc.what();
	}
}

Item getItemById(int id) {
	list<Item>::iterator it;
	for (it = items.begin(); it != items.end(); it++) {
		Item i = *it;
		if (i.id == id) {
			return i;
		}
	}
	Item temp;
	temp.id = -1;
	return temp;
}

const string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}
