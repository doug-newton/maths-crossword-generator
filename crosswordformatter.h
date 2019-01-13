#ifndef CROSSWORDFORMATTER_H
#define CROSSWORDFORMATTER_H

#include "questionformatter.h"

class Crossword;

class CrosswordFormatter: public QuestionFormatter {

	public:
		CrosswordFormatter(Formatter* formatter);
		virtual void formatCrossword(Crossword* crossword)=0;
};

#endif	//	CROSSWORD
