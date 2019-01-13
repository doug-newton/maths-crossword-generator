#include "swapperdivide.h"

bool SwapperDivide::canSwap(Node* node) {
	if (!enabled) return false;
	if ((int)(200.f / node->getValue()) < 2) return false;
	return true;
}

void SwapperDivide::swap(Node* node) {
	Node* divide = makeDivideExpression(node);
	replace(node, divide);
}

Node* SwapperDivide::makeDivideExpression(Node* node) {
	Node *left, *divide, *right;
	Tree* tree = node->getTree();

	left = tree->makeNode();
	divide = tree->makeNode();
	right = tree->makeNode();

	int limit = (int)(200.f / node->getValue());
	int r = random.randomInt(2, limit);
	int a = r * node->getValue();
	int b = r;

	left->setValue(a);
	right->setValue(b);

	divide->setLeft(left);
	divide->setRight(right);
	divide->setOperator(DIVIDE);

	return divide;
}
