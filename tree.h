#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>

class Tree {

	public:
		Tree();
		Tree(int value);

		void setHead(Node* head);
		std::string toString();
		Node* makeNode();

		Node* getHead();

	private:
		Node* head;
		std::vector<Node> nodes;

		int nodeCounter;
};

#endif
