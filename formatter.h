#ifndef FORMATTER_H
#define FORMATTER_H

#include <string>
#include <vector>
#include <ostream>

class BodmasQuestionFormatter;
class ExpressionTreeFormatter;
class EquationQuestionFormatter;
class TreeFormatter;
class CrosswordFormatter;
class TableFormatter;

class Formatter {

	public:
		Formatter();

		virtual void outputQuestions(std::ostream& stream)=0;
		virtual void outputAnswers(std::ostream& stream)=0;

		void addQuestionLine(const std::string line);
		void addAnswerLine(const std::string line);

		virtual void startSection(const std::string sectionName)=0;
		virtual void endSection()=0;

		virtual void startSubsection(const std::string sectionName)=0;
		virtual void endSubsection()=0;

		virtual void startEnumerate()=0;
		virtual void endEnumerate()=0;

		virtual void startMulticol(int numColumns)=0;
		virtual void endMulticol()=0;

		BodmasQuestionFormatter* getBodmasQuestionFormatter();
		ExpressionTreeFormatter* getExpressionTreeFormatter();
		EquationQuestionFormatter* getEquationQuestionFormatter();
		TreeFormatter* getTreeFormatter();
		CrosswordFormatter* getCrosswordFormatter();
		TableFormatter* getTableFormatter();

	protected:
		std::vector<std::string> questionLines;
		std::vector<std::string> answerLines;

		BodmasQuestionFormatter* pBodmasQuestionFormatter;
		ExpressionTreeFormatter* pExpressionTreeFormatter;
		EquationQuestionFormatter* pEquationQuestionFormatter;
		TreeFormatter* pTreeFormatter;
		CrosswordFormatter* pCrosswordFormatter;
		TableFormatter* pTableFormatter;
};

#endif
