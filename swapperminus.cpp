#include "swapperminus.h"
#include <iostream>

bool SwapperMinus::canSwap(Node* node) {
	if (!enabled) return false;
	if (node->getValue()*3 > 150) return false;
	return true;
}

void SwapperMinus::swap(Node* node) {
	Node* minus = makeMinusExpression(node);
	replace(node, minus);
}

Node* SwapperMinus::makeMinusExpression(Node* node) {
	Node *left, *minus, *right;
	Tree* tree = node->getTree();

	left = tree->makeNode();
	minus = tree->makeNode();
	right = tree->makeNode();

	int a = random.randomInt(node->getValue()+1, node->getValue()*3);
	int b = a - node->getValue();

	left->setValue(a);
	right->setValue(b);

	minus->setLeft(left);
	minus->setRight(right);
	minus->setOperator(MINUS);

	return minus;
}
