#include "latextreeformatter.h"
#include "tree.h"
#include <sstream>

LatexTreeFormatter::LatexTreeFormatter(Formatter* formatter):TreeFormatter(formatter) 
{
}

void LatexTreeFormatter::formatTree(Tree* tree) {
}

std::string LatexTreeFormatter::strTree(Tree* tree) {
	Node* head = tree->getHead();
	return strNode(head);
}

std::string LatexTreeFormatter::strNode(Node* node) {
	std::stringstream stream;

	Node* left = node->getLeft();
	Node* right = node->getRight();

	switch (node->getOperator()) {
		case NONE:
			stream << node->getValue();
			if (node->isVariable)
				stream << 'x';
			break;

		case PLUS:
			stream << strNode(left) << " + " << strNode(right);
			break;

		case MINUS:
			stream << strNode(left) << " - " << strNode(right);
			break;

		case TIMES:
			if (right.isVariable)
			stream << strNode(left);
			if (!right.isVariable) stream << " \\times ";
			stream << strNode(right);
			break;

		case DIVIDE:
			stream << strNode(left) << " \\div " << strNode(right);
			break;

		default:
			break;
	}

	std::string str = stream.str();

	if (node->needsBrackets()) str = "\\left(" + str + "\\right)";
	return str;
}
