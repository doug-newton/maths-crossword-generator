#ifndef EQUATIONQUESTION_H
#define EQUATIONQUESTION_H

#include "question.h"
#include "expressiontree.h"
#include "equationquestionformatter.h"
#include "formula.h"

class EquationQuestion: public Question {

	public:
		virtual void generate(std::vector<std::string>& args);
		virtual void format(Formatter* formatter);
		ExpressionTree& getExpressionTree();
		Formula& getFormula();

	private:
		Formula formula;
};

#endif
