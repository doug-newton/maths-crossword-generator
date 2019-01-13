#include "swappertimes.h"

bool SwapperTimes::canSwap(Node* node) {
	if (!enabled) return false;
	//	must check that the number is not prime
	if (factorFinder.isPrime(node->getValue())) return false;
	return true;
}

void SwapperTimes::swap(Node* node) {
	Node* times = makeTimesExpression(node);
	replace(node, times);
}

Node* SwapperTimes::makeTimesExpression(Node* node) {
	//	must choose 2 random factors of the number

	int a,b;
	factorFinder.findFactors(node->getValue(),a,b);

	Node *left, *times, *right;
	Tree* tree = node->getTree();

	left = tree->makeNode();
	times = tree->makeNode();
	right = tree->makeNode();

	left->setValue(a);
	right->setValue(b);

	times->setLeft(left);
	times->setRight(right);
	times->setOperator(TIMES);
}
