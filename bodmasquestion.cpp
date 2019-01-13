#include "bodmasquestion.h"
#include <iostream>
#include "bodmasquestionvariant.h"

//	BODMAS [D][M][A][S] [answer] [complexity] 
void BodmasQuestion::generate(std::vector<std::string>& args) {
	std::string variant = args[1];
	std::string strAnswer = args[2];
	std::string strComplexity = args[3];


	int answer = std::stoi(strAnswer);
	int complexity = std::stoi(strComplexity);
	
	if (args.size() > 1) variant = args[1];


	//	for every variant, make an object which then processes the expressiontree

	SwappingBuilder builder;

	for (int i=0; i<variant.length(); i++) {
		switch (variant[i]) {
			case 'D':
				builder.enableSwapper("DIVIDE");
				break;
			case 'M':
				builder.enableSwapper("TIMES");
				break;
			case 'A':
				builder.enableSwapper("PLUS");
				break;
			case 'S':
				builder.enableSwapper("MINUS");
				break;
		}
	}

	for(int i=0; i<args.size(); i++) {

		if (args[i] == "NOBRACKETS")
		{
			setUseBrackets(false);
		}

		else if (args[i] == "FINDX")
		{
			setUseBrackets(false);
		}
	}

	tree.getHead()->setValue(answer);

	for (int i=0; i<complexity; i++) {
		builder.build(&tree);
	}
	//	BodmasQuestionVariantTest(this, args);
}

void BodmasQuestion::setUseBrackets(bool b) {
	useBrackets = b;
}

void BodmasQuestion::format(Formatter* formatter) {
	BodmasQuestionFormatter* bodmasQuestionFormatter
		= formatter->getBodmasQuestionFormatter();
	bodmasQuestionFormatter->formatBodmasQuestion(this);
}

ExpressionTree& BodmasQuestion::getExpressionTree() {
	return expressionTree;
}

Tree* BodmasQuestion::getTree() {
	return &tree;
}
