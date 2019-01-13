#include "filereader.h"

void FileReader::readFileIntoVector(const std::string filename,
		std::vector<std::string>& stringVector) {

	std::string line;
	std::ifstream f (filename);
	if (!f.is_open())
		    perror("error while opening file");
	while(getline(f, line)) {
		stringVector.push_back(line);
			    }
	if (f.bad())
		    perror("error while reading file");

	f.close();

}
