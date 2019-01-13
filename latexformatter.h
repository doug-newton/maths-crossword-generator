#ifndef LATEXFORMATTER_H
#define LATEXFORMATTER_H

#include "formatter.h"
#include "latexbodmasquestionformatter.h"
#include "latexexpressiontreeformatter.h"
#include "latexequationquestionformatter.h"
#include "latextreeformatter.h"
#include "latexcrosswordformatter.h"
#include "latextableformatter.h"

class LatexFormatter: public Formatter {

	public:
		LatexFormatter();

		virtual void outputQuestions(std::ostream& stream);
		virtual void outputAnswers(std::ostream& stream);

		virtual void startSubsection(const std::string name);
		virtual void endSubsection();

		virtual void startSection(const std::string name);
		virtual void endSection();

		virtual void startEnumerate();
		virtual void endEnumerate();

		virtual void startMulticol(int numColumns);
		virtual void endMulticol();

	private:
		LatexBodmasQuestionFormatter bodmasQuestionFormatter;
		LatexExpressionTreeFormatter expressionTreeFormatter;
		LatexEquationQuestionFormatter equationQuestionFormatter;
		LatexTreeFormatter treeFormatter;
		LatexCrosswordFormatter crosswordFormatter;
		LatexTableFormatter tableFormatter;
};

#endif
