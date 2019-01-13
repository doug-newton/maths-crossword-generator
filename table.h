#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

/*	A table with only 2 rows.
 */

class Table {

	public:
		/*	Puts a string at the end of the row1 and the end of row2.
		 */
		void append(const std::string element1, const std::string element2);

		std::string& elementInRow1(int index);
		std::string& elementInRow2(int index);

		int getSize();

	protected:
		std::vector<std::string> row1;
		std::vector<std::string> row2;

		//	the length of the table (no. of columns)
		int size;
};

#endif
