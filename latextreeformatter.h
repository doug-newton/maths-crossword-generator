#ifndef LATEXTREEFORMATTER_H
#define LATEXTREEFORMATTER_H

#include "treeformatter.h"

class LatexTreeFormatter: public TreeFormatter {

	public:
		LatexTreeFormatter(Formatter* formatter);
		virtual void formatTree(Tree* tree);
		virtual std::string strTree(Tree* tree);

	private:
		std::string strNode(Node* node);
};

#endif	//	LATEXTREEFORMATTER_H
