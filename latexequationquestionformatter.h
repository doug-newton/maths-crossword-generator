#ifndef LATEXEQUATIONQUESTIONFORMATTER_H
#define LATEXEQUATIONQUESTIONFORMATTER_H

#include "equationquestionformatter.h"

class LatexEquationQuestionFormatter: public EquationQuestionFormatter {

	public:
		LatexEquationQuestionFormatter(Formatter* formatter);
		virtual void formatEquationQuestion(EquationQuestion* question);
};

#endif
