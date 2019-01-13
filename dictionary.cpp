#include "dictionary.h"

Dictionary::Dictionary()
	:wordIndex(0)
{
	loadWords();
}

void Dictionary::loadWords() {
	FileReader fileReader;
	fileReader.readFileIntoVector("english2.txt",words);
}

std::string& Dictionary::nextWord(Random* random) {
	int range = words.size();
	int length = 0;

	int index = 0;

	while (length < 4 || length > 6) {
		index = random->randomInt(0,range);
		length = words[index].length();
	}

	return words[index];
}
