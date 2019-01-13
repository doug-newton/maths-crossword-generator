#ifndef EXPRESSIONTREEFORMATTER_H
#define EXPRESSIONTREEFORMATTER_H

/*	A utility formatter that can be used by other classes to print expression trees.
 */

#include "questionformatter.h"

class ExpressionTree;
class ExpressionNode;

class ExpressionTreeFormatter: public QuestionFormatter {

	public:
		ExpressionTreeFormatter(Formatter* formatter);
		virtual void formatExpressionTree(ExpressionTree* expressionTree)=0;
		virtual std::string strExpressionTree(ExpressionTree* tree)=0;
};

#endif
