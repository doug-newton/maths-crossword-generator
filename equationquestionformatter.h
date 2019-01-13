#ifndef EQUATIONQUESTIONFORMATTER_H
#define EQUATIONQUESTIONFORMATTER_H

#include "questionformatter.h"

class EquationQuestion;

class EquationQuestionFormatter: public QuestionFormatter {

	public:
		EquationQuestionFormatter(Formatter* formatter);
		virtual void formatEquationQuestion(EquationQuestion* question)=0;
};

#endif
