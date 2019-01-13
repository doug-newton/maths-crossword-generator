#ifndef LATEXEXPRESSIONTREEFORMATTER_H
#define LATEXEXPRESSIONTREEFORMATTER_H

#include "expressiontreeformatter.h"
#include "expressiontree.h"

class LatexExpressionTreeFormatter: public ExpressionTreeFormatter {

	public:
		LatexExpressionTreeFormatter(Formatter* formatter);
		virtual void formatExpressionTree(ExpressionTree* tree);

		/*	Recursively print an ExpressionTree
		 */
		std::string strExpressionTree(ExpressionTree* tree);

	private:
		std::string strExpressionNode(ExpressionNode* node);
};

#endif
