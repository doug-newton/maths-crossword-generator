#include "latextableformatter.h"
#include <iostream>
#include <sstream>

LatexTableFormatter::LatexTableFormatter(Formatter* formatter)
	: TableFormatter(formatter)
{
}

void LatexTableFormatter::formatTable(Table* table) {
	std::stringstream stream;

	int tableSize = table->getSize();

	stream << "\\begin{center}" << std::endl;

	stream << "{\\footnotesize" << std::endl;

	stream << "\\begin{tabular}{|";
	for (int i=0; i<tableSize; i++) {
		stream << "c|";
	}
	stream << "}" << std::endl;

	stream << "\\hline" << std::endl;

	for (int i=0; i<tableSize; i++) {
		stream << table->elementInRow1(i) << " ";
		if (i < tableSize-1) {
			stream << "& ";
		}
	}
	stream << "\\\\" << std::endl;

	stream << "\\hline" << std::endl;

	for (int i=0; i<tableSize; i++) {
		stream << table->elementInRow2(i) << " ";
		if (i < tableSize-1) {
			stream << "& ";
		}
	}
	stream << "\\\\" << std::endl;

	stream << "\\hline" << std::endl;
	stream << "\\end{tabular}" << std::endl;

	stream << "}" << std::endl;

	stream << "\\end{center}";

	formatter->addQuestionLine(stream.str());
}
