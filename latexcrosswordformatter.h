#ifndef LATEXCROSSWORDFORMATTER_H
#define LATEXCROSSWORDFORMATTER_H

#include "crosswordformatter.h"

class LatexCrosswordFormatter: public CrosswordFormatter {

	public:
		LatexCrosswordFormatter(Formatter* formatter);
		virtual void formatCrossword(Crossword* crossword);
};

#endif
