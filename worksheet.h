#ifndef WORKSHEET_H
#define WORKSHEET_H

#include <string>
#include <iostream>
#include "bodmasquestion.h"
#include "equationquestion.h"
#include "latexformatter.h"
#include <vector>
#include "random.h"

class Worksheet {

	public:
		Worksheet();
		void command(std::vector<std::string> args);

		void outputQuestions(std::ostream& stream);
		void outputAnswers(std::ostream& stream);

		void setSeed(int s);

	protected:
		Formatter* formatter;
		LatexFormatter latexFormatter;
		Random random;

	private:
		int seed;
};

#endif
