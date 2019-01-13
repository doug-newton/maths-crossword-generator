#ifndef LATEXTABLEFORMATTER_H
#define LATEXTABLEFORMATTER_H

#include "tableformatter.h"
#include "table.h"

class LatexTableFormatter: public TableFormatter {

	public:
		LatexTableFormatter(Formatter* formatter);
		virtual void formatTable(Table* table);
};

#endif
