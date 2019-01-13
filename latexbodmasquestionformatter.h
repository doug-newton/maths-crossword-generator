#ifndef LATEXBODMASQUESTIONFORMATTER_H
#define LATEXBODMASQUESTIONFORMATTER_H

#include "bodmasquestionformatter.h"
#include "expressiontree.h"
#include "expressionnode.h"

class LatexBodmasQuestionFormatter: public BodmasQuestionFormatter {

	public:
		LatexBodmasQuestionFormatter(Formatter* formatter);
		virtual void formatBodmasQuestion(BodmasQuestion* question);

	private:
		void formatQuestion(BodmasQuestion* question);
		void formatAnswer(BodmasQuestion* question);
};

#endif
