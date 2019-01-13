#include "latexbodmasquestionformatter.h"
#include "latexexpressiontreeformatter.h"
#include "latextreeformatter.h"
#include "bodmasquestion.h"
#include <iostream>
#include <sstream>

LatexBodmasQuestionFormatter::LatexBodmasQuestionFormatter(Formatter* formatter)
	: BodmasQuestionFormatter(formatter)
{
}

void LatexBodmasQuestionFormatter::formatBodmasQuestion(BodmasQuestion* question) {
	formatQuestion(question);
	formatAnswer(question);
}

void LatexBodmasQuestionFormatter::formatQuestion(BodmasQuestion* question) {
	std::stringstream ss;
	Tree* tree = question->getTree();
	ExpressionTreeFormatter* expressionTreeFormatter
		= formatter->getExpressionTreeFormatter();
	TreeFormatter* treeFormatter = formatter->getTreeFormatter();

	if (question->getUseBrackets

	ss << "\\item $" 
		<< treeFormatter->strTree(tree)
		<< "$";

	formatter->addQuestionLine(ss.str());
}

void LatexBodmasQuestionFormatter::formatAnswer(BodmasQuestion* question) {
	std::stringstream ss;
	Tree* tree = question->getTree();

	ss << "\\item $" 
		<< "$";

	formatter->addAnswerLine(ss.str());
}
