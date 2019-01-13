#include "tree.h"

Tree::Tree() {
	nodes = std::vector<Node>(50);
	setHead(&nodes[0]);
	nodeCounter = 1;
}

Tree::Tree(int value) {
	nodes = std::vector<Node>(50);
	setHead(&nodes[0]);
	nodeCounter = 1;
	head->setValue(value);
}

void Tree::setHead(Node* head) {
	this->head = head;
	head->setTree(this);
}

std::string Tree::toString() {
	return head->toString();
}

Node* Tree::makeNode() {
	if (nodeCounter > 49) return nullptr;

	Node* node = &nodes[nodeCounter];
	node->setTree(this);
	nodeCounter++;

	return node;
}

Node* Tree::getHead() {
	return head;
}
