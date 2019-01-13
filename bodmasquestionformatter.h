#ifndef BODMASQUESTIONFORMATTER_H
#define BODMASQUESTIONFORMATTER_H

#include "questionformatter.h"

class BodmasQuestion;

class BodmasQuestionFormatter: public QuestionFormatter {

	public:
		BodmasQuestionFormatter(Formatter* formatter);
		virtual void formatBodmasQuestion(BodmasQuestion* question)=0;
};

#endif
