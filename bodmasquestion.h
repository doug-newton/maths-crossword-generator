#ifndef BODMASQUESTION
#define BODMASQUESTION

#include "question.h"
#include "bodmasquestionformatter.h"
#include "expressiontree.h"
#include "tree.h"
#include "swappingbuilder.h"

class BodmasQuestion: public Question {

	public:
		virtual void generate(std::vector<std::string>& args);
		virtual void format(Formatter* formatter);

		ExpressionTree& getExpressionTree();
		Tree* getTree();

		void setUseBrackets(bool b);
		bool getUseBrackets();
		bool findX;

	private:
		ExpressionTree expressionTree;
		Tree tree;
		std::string arguments;
		bool useBrackets;
};

#endif
