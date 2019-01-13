#ifndef QUESTION_H
#define QUESTION_H

#include "formatter.h"
#include "random.h"
#include <vector>
#include <string>

class Question {

	public:
		virtual void generate(std::vector<std::string>& args)=0;
		virtual void format(Formatter* formatter)=0;
		Random& getRandom();

	protected:
		Random random;
};

#endif
