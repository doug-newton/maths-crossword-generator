#include "swapperplus.h"
#include <iostream>

bool SwapperPlus::canSwap(Node* node) {
	if (!enabled) return false;
	if (node->getValue() <= 3) return false;
	return true;
}

void SwapperPlus::swap(Node* node) {
	Node* plus = makePlusExpression(node);
	replace(node, plus);
}

Node* SwapperPlus::makePlusExpression(Node* node) {
	Node *left, *plus, *right;
	Tree* tree = node->getTree();

	left = tree->makeNode();
	plus = tree->makeNode();
	right = tree->makeNode();

	int a = random.randomInt(3, node->getValue()-1);
	int b = node->getValue() - a;

	left->setValue(a);
	right->setValue(b);

	plus->setLeft(left);
	plus->setRight(right);
	plus->setOperator(PLUS);

	return plus;
}
