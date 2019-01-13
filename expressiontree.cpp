#include "expressiontree.h"

ExpressionTree::ExpressionTree()
{
	size = 1;
	totalNodes = 30;
	lastNodeIndex = 0;
	expressionNodes = std::vector<ExpressionNode>(totalNodes);
}

ExpressionNode* ExpressionTree::getHead() {
	return getNode(0);
}

ExpressionNode* ExpressionTree::getNextNode() {
	ExpressionNode* node = getNode(++lastNodeIndex);
	if (node!=nullptr) size++;
	return node;
}

int ExpressionTree::getSize() {
	return size;
}

void ExpressionTree::calculate() {
	getHead()->calculate();
}

int ExpressionTree::getValue() {
	return getHead()->getValue();
}

ExpressionNode* ExpressionTree::getNode(int index) {
	if (index > totalNodes-1)
		return nullptr;
	ExpressionNode& node = expressionNodes[index];
	node.setExpressionTree(this);
	return &node;
}

bool ExpressionTree::isFull() {
	return size >= totalNodes;
}
