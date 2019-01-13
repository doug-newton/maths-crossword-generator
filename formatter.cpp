#include "formatter.h"
#include <iostream>

Formatter::Formatter()
{
}

void Formatter::addQuestionLine(const std::string line) {
	questionLines.push_back(line);
}

void Formatter::addAnswerLine(const std::string line) {
	answerLines.push_back(line);
}

BodmasQuestionFormatter* Formatter::getBodmasQuestionFormatter() {
	return pBodmasQuestionFormatter;
}

ExpressionTreeFormatter* Formatter::getExpressionTreeFormatter() {
	return pExpressionTreeFormatter;
}

EquationQuestionFormatter* Formatter::getEquationQuestionFormatter() {
	return pEquationQuestionFormatter;
}

TreeFormatter* Formatter::getTreeFormatter() {
	return pTreeFormatter;
}

CrosswordFormatter* Formatter::getCrosswordFormatter() {
	return pCrosswordFormatter;
}

TableFormatter* Formatter::getTableFormatter() {
	return pTableFormatter;
}
