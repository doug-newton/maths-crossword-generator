#ifndef CROSSWORDWORKSHEET_H
#define CROSSWORDWORKSHEET_H

#include "worksheet.h"
#include "crossword.h"
#include "dictionary.h"
#include "alphabettable.h"

class CrosswordWorksheet: public Worksheet {

	public:
		CrosswordWorksheet();
		void makeCrossword();
		void buildCrosswordOnly();
		void addWordCommandCluster(std::string& command);

		void setDisplayAnswers(bool b);
		bool getDisplayAnswers();

	protected:
		int seed;
		std::string charToStrInt(char c);
		Dictionary dictionary;
		Crossword crossword;
		AlphabetTable alphabetTable;
		std::vector<std::string> wordCommandClusters;

		bool displayAnswers;
};

#endif
