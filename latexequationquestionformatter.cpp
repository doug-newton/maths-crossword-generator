#include "latexequationquestionformatter.h"
#include "latexexpressiontreeformatter.h"
#include "equationquestion.h"
#include <iostream>
#include <sstream>

LatexEquationQuestionFormatter::LatexEquationQuestionFormatter(Formatter* formatter)
	: EquationQuestionFormatter(formatter)
{
}

void LatexEquationQuestionFormatter::formatEquationQuestion(EquationQuestion* question) {
	std::stringstream ss;
	ExpressionTree& expressionTree = question->getExpressionTree();
	ExpressionTreeFormatter* expressionTreeFormatter = 
		formatter->getExpressionTreeFormatter();

	ss << "\\item $" <<
		expressionTreeFormatter->strExpressionTree(&expressionTree)
		<< " = " <<
		question->getFormula().getValue()
		<< "$";

	formatter->addQuestionLine(ss.str());
	formatter->addAnswerLine(ss.str());
}
