#include "crosswordworksheet.h"
#include <iostream>
#include <sstream>


void parseCommand(const std::string& command, std::vector<std::string>& args);

CrosswordWorksheet::CrosswordWorksheet() :
	seed(28)
{
}

void CrosswordWorksheet::setDisplayAnswers(bool b) {
	displayAnswers = b;
	crossword.setDisplayAnswers(b);
}

bool CrosswordWorksheet::getDisplayAnswers() {
	return displayAnswers;
}

void CrosswordWorksheet::buildCrosswordOnly() {
	srand(seed);
	CrosswordFormatter* crosswordFormatter = formatter->getCrosswordFormatter();

	for (int i=0; i<5; i++) {
		std::string& word = dictionary.nextWord(&random);
		if (crossword.addWord(word)) {
		}
	}

	crossword.makeNames();
	crosswordFormatter->formatCrossword(&crossword);
}

void CrosswordWorksheet::makeCrossword() {
	std::cout << "SEED: " << seed << std::endl;
	random.setSeed(seed);
	std::vector<std::string> words;
	CrosswordFormatter* crosswordFormatter = formatter->getCrosswordFormatter();

	int j = 0;

	while (j < 6) {
		std::string& word = dictionary.nextWord(&random);
		std::cout << word << std::endl;
		if (crossword.addWord(word)) {
			j ++;
		}
	}

	formatter->startSection("Bodmas Crossword");

	crossword.makeNames();
	crosswordFormatter->formatCrossword(&crossword);

	TableFormatter* tableFormatter = formatter->getTableFormatter();
	tableFormatter->formatTable(&alphabetTable);

	formatter->startMulticol(2);

	int index = 0;

	for (std::string& word: crossword.getWordsInOrder()) {
		std::string wordName = crossword.getNameOf(word);
		command({"SUBSECTION",wordName});
		command({"ENUMERATE"});
		for (int i = 0; i < word.length(); i ++) {
			command({"BODMAS","DMAS",charToStrInt(word[i]),"3"});
		}
		command({"ENDENUMERATE"});
		command({"ENDSUBSECTION"});

		index ++;
	}	

	formatter->endMulticol();
}

std::string CrosswordWorksheet::charToStrInt(char c) {
	int n = 0;

	if (97 <= c && c <= 122) {
		n = (int)c - 96;
	}
	else if (65 <= c && c <= 90) {
		n = (int)c - 64;
	}

	std::stringstream stream;
	stream << n;

	return stream.str();
}
