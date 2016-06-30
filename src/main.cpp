#include "menu.h"

#include <iostream>

using namespace std;

void loadData(string fileName) {
	ifstream ifs(fileName);
}

int main(int argc, char **argv) {
	loadData("input.txt");
	menu();
}
