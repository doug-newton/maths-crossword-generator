#include "swapper.h"

Swapper::Swapper():
	enabled(false)
{
}

void Swapper::replace(Node* node, Node* other) {
	Node* parent = node->getParent();
	Tree* tree = node->getTree();

	if (parent != nullptr) {
		if (node == parent->getLeft()) {
			parent->setLeft(other);
		} else if (node == parent->getRight()) {
			parent->setRight(other);
		}
	} else if (tree != nullptr) {
		if (tree->getHead() == node) {
			tree->setHead(other);
		}
	}
}

void Swapper::setEnabled(bool b) {
	this->enabled = b;
}
