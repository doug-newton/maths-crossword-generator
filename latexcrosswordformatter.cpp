#include "latexcrosswordformatter.h"
#include "crossword.h"

LatexCrosswordFormatter::LatexCrosswordFormatter(Formatter* formatter)
	: CrosswordFormatter(formatter)
{
}

void LatexCrosswordFormatter::formatCrossword(Crossword* crossword) {
	CharGrid& grid = crossword->getGrid();
	std::deque<std::string>& data = grid.getData();

	std::stringstream ss;

	if (crossword->getDisplayAnswers())
		ss << "\\PuzzleSolution\n";

	ss << "\\begin{Puzzle}{" << grid.getWidth() << "}{" << grid.getHeight() << "}\n";

	for (int y = 0; y < data.size(); y++ ) {
		std::string& line = data[y];

		for (int x=0; x < line.length(); x++) {
			char c = line[x];
			if (c == grid.getBlank()) {
				ss << "|{}";
			} else {
				ss << "|";
				if (crossword->hasIndexAt(x,y)) {
					int index = crossword->indexAt(x,y);
					ss << "[" << index << "]";
				}
				ss << c;
			}
		}
		ss << "|.\n";

	}

	ss <<
"\\end{Puzzle}";

	formatter->addQuestionLine(ss.str());
}
