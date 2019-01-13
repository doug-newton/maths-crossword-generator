#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include "filereader.h"
#include "random.h"

class Dictionary {

	public:
		Dictionary();
		std::string& nextWord(Random* random);

	private:
		std::vector<std::string> words;
		int wordIndex;

		void loadWords();
};

#endif
