#include "table.h"

void Table::append(const std::string element1, const std::string element2) {
	row1.push_back(element1);
	row2.push_back(element2);
	size = row1.size();
}

std::string& Table::elementInRow1(int index) {
	return row1[index];
}

std::string& Table::elementInRow2(int index) {
	return row2[index];
}

int Table::getSize() {
	return size;
}
