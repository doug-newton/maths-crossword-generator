#include "worksheet.h"

Worksheet::Worksheet() 
	: formatter(&latexFormatter)
{
}

void Worksheet::command(std::vector<std::string> args) {
	const std::string& first = args[0];

	if (first == "BODMAS") {
		BodmasQuestion question;
		question.generate(args);
		question.format(formatter);
		std::cout << "worksheet command" << std::endl;
	}

	else if (first == "EQUATION") {
		EquationQuestion question;
		question.generate(args);
		question.format(formatter);
	}

	else if (first == "ENUMERATE") {
		formatter->startEnumerate();
	}

	else if (first == "ENDENUMERATE") {
		formatter->endEnumerate();
	}

	else if (first == "SECTION") {
		formatter->startSection(args[1]);
	}

	else if (first == "ENDSECTION") {
		formatter->endSection();
	}

	else if (first == "SUBSECTION") {
		formatter->startSubsection(args[1]);
	}

	else if (first == "ENDSUBSECTION") {
		formatter->endSubsection();
	}

	else if (first == "SEED") {
		int s = std::stoi(args[1]);
		setSeed(s);
	}
}

void Worksheet::outputQuestions(std::ostream& stream) {
	formatter->outputQuestions(stream);
}

void Worksheet::outputAnswers(std::ostream& stream) {
	formatter->outputAnswers(stream);
}

void Worksheet::setSeed(int s) {
	seed = s;
}
