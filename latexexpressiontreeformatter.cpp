#include "latexexpressiontreeformatter.h"
#include <iostream>
#include <sstream>

LatexExpressionTreeFormatter::LatexExpressionTreeFormatter(Formatter* formatter)
	: ExpressionTreeFormatter(formatter)
{
}

void LatexExpressionTreeFormatter::formatExpressionTree(ExpressionTree* expressionTree) {
	//	doesn't do anything yet - other classes use this class as a utility
}

std::string LatexExpressionTreeFormatter::strExpressionTree(ExpressionTree* tree) {
}

/*	Recursively print an ExpressionNode.
 */
std::string LatexExpressionTreeFormatter::strExpressionNode(ExpressionNode* node) {
}
