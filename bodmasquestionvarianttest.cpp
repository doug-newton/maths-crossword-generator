#include "bodmasquestionvariant.h"
#include <iostream>

BodmasQuestionVariantTest::BodmasQuestionVariantTest(
		BodmasQuestion* question,
		std::vector<std::string>& args) 
{
	Tree* tree = question->getTree();
	tree->getHead()->setValue(10);
	SwappingBuilder builder;
	builder.build(tree);
}
