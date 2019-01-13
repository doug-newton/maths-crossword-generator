#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include <fstream>

class FileReader {

	public:
		void readFileIntoVector(const std::string filename,
				std::vector<std::string>& stringVector);
};

#endif
