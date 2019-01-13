#ifndef CHARGRID_H
#define CHARGRID_H

#include <iostream>
#include <string>
#include <deque>

class CharGrid {

	public:
		CharGrid();

		void setChar(int x,int y,char c);
		std::string strAscii();
		bool emptyBlock(int x, int y);

		int offsetX(int x);
		int offsetY(int y);

		int getWidth();
		int getHeight();

		std::deque<std::string>& getData();
		char getBlank();

	private:
		void ensureSizeFor(int x, int y);
		void addRowsBefore(int n);
		void addRowsAfter(int n);
		void addColumnsBefore(int n);
		void addColumnsAfter(int n);

		std::deque<std::string> data;
		int width,height,ox,oy,ex,ey;
		std::string blank;
};

#endif
