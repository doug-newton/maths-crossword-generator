#ifndef QUESTIONFORMATTER_H
#define QUESTIONFORMATTER_H

#include "formatter.h"

class QuestionFormatter {

	public:
		QuestionFormatter(Formatter* formatter);

	protected:
		Formatter* formatter;
};

#endif
