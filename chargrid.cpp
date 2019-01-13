#include "chargrid.h"

CharGrid::CharGrid() {
	width = height = 1;
	blank = " ";
	data.push_back(blank);
	ox = oy = 0;
	ex = ey = 0;
}

void CharGrid::setChar(int x,int y,char c) {
	ensureSizeFor(x-ox,y-oy);

	if ( x < ox ) {
		ox = x;
	} else if ( x > ex ) {
		ex = x;
	}

	if ( y < oy ) {
		oy = y;
	} else if ( y > ey ) {
		ey = y;
	}

	data[y-oy][x-ox] = c;
}

int CharGrid::offsetX(int x) {
	return x+ox;
}

int CharGrid::offsetY(int y) {
	return y+oy;
}

std::string CharGrid::strAscii() {
	std::string ret = "";
	for (auto& line: data) {
		ret += line + "\n";
	}
	return ret;
}

bool CharGrid::emptyBlock(int x, int y) {
	if ( x > ex ) return true;
	if ( x < ox ) return true;
	if ( y > ey ) return true;
	if ( y < oy ) return true;

	return data[y][x] == blank[0];
}

int CharGrid::getWidth() {
	return width;
}

int CharGrid::getHeight() {
	return height;
}

std::deque<std::string>& CharGrid::getData() {
	return data;
}

char CharGrid::getBlank() {
	return blank[0];
}

//	private:
void CharGrid::ensureSizeFor(int x, int y) {
	if (x<0) {
		addColumnsBefore(-x);
		x=0;
	} else if (x > width - 1) {
		addColumnsAfter(x + 1 - width);
	}

	if (y<0) {
		addRowsBefore(-y);
		y=0;
	} else if (y > height - 1) {
		addRowsAfter(y + 1 - height);
	}
}

void CharGrid::addRowsBefore(int n) {
	for (int i=0; i<n; i++) {
		std::string row = "";
		for (int j=0; j<width; j++) {
			row += blank;
		}
		data.push_front(row);
	}
	height = data.size();
}

void CharGrid::addRowsAfter(int n) {
	for (int i=0; i<n; i++) {
		std::string row = "";
		for (int j=0; j<width; j++) {
			row += blank;
		}
		data.push_back(row);
	}
	height = data.size();
}

void CharGrid::addColumnsBefore(int n) {
	for (int i=0; i<data.size(); i++) {
		std::string& line = data.at(i);
		for (int j=0; j<n; j++) {
			line = blank + line;
		}
	}

	width += n;
}

void CharGrid::addColumnsAfter(int n) {
	for (int i=0; i<data.size(); i++) {
		std::string& line = data.at(i);
		for (int j=0; j<n; j++) {
			line =  line + blank;
		}
	}

	width += n;
}
