#ifndef TABLEFORMATTER_H
#define TABLEFORMATTER_H

#include "questionformatter.h"

class Table;

class TableFormatter: public QuestionFormatter {

	public:
		TableFormatter(Formatter* formatter);
		virtual void formatTable(Table* table)=0;
};

#endif
