#include "equationquestion.h"
#include "equationquestionvariant.h"

void EquationQuestion::generate(std::vector<std::string>& args) {
	EquationQuestionVariantCoeff(args, this);
}

void EquationQuestion::format(Formatter* formatter) {
	EquationQuestionFormatter* equationQuestionFormatter
		= formatter->getEquationQuestionFormatter();

	equationQuestionFormatter->formatEquationQuestion(this);
}

ExpressionTree& EquationQuestion::getExpressionTree() {
	return formula.getExpressionTree();
}

Formula& EquationQuestion::getFormula() {
	return formula;
}
