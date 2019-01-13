#include "latexformatter.h"
#include <sstream>

LatexFormatter::LatexFormatter():
	bodmasQuestionFormatter(this),
	expressionTreeFormatter(this),
	equationQuestionFormatter(this),
	treeFormatter(this),
	crosswordFormatter(this),
	tableFormatter(this)
{
	pBodmasQuestionFormatter = &bodmasQuestionFormatter;
	pExpressionTreeFormatter = &expressionTreeFormatter;
	pEquationQuestionFormatter = &equationQuestionFormatter;
	pTreeFormatter = &treeFormatter;
	pCrosswordFormatter = &crosswordFormatter;
	pTableFormatter = &tableFormatter;
}

void LatexFormatter::startSubsection(const std::string sectionName) {
	addAnswerLine("\\subsection*{" + sectionName + "}");
	addQuestionLine("\\subsection*{" + sectionName + "}");
}

void LatexFormatter::endSubsection() {
}

void LatexFormatter::startSection(const std::string sectionName) {
	addAnswerLine("\\section*{" + sectionName + "}");
	addQuestionLine("\\section*{" + sectionName + "}");
}

void LatexFormatter::endSection() {
}

void LatexFormatter::startEnumerate() {
	addAnswerLine("\\begin{enumerate}[1)]");
	addQuestionLine("\\begin{enumerate}[1)]");
}

void LatexFormatter::endEnumerate() {
	addAnswerLine("\\end{enumerate}");
	addQuestionLine("\\end{enumerate}");
}

void LatexFormatter::startMulticol(int numColumns) {
	std::stringstream stream;
	stream << "\\begin{multicols*}{" << numColumns << "}";
	addAnswerLine(stream.str());
	addQuestionLine(stream.str());
}

void LatexFormatter::endMulticol() {
	addAnswerLine("\\end{multicols*}");
	addQuestionLine("\\end{multicols*}");
}

void LatexFormatter::outputQuestions(std::ostream& stream) {
	stream <<
		"\\documentclass{exam}\n"
		"\\usepackage[unboxed]{cwpuzzle}\n"
		"\\usepackage{amsmath}\n"
		"\\usepackage{enumerate}\n"
		"\\usepackage{multicol}\n"
		"\\begin{document}"
		<< std::endl;
	for (std::string& line: questionLines) {
		stream << line << std::endl;
	}
	stream <<
		"\\end{document}"
		 << std::endl;
}

void LatexFormatter::outputAnswers(std::ostream& stream) {
	for (std::string& line: answerLines) {
		stream << line << std::endl;
	}
}
