#include "swappingbuilder.h"
#include <iostream>

SwappingBuilder::SwappingBuilder() {
	swappers.push_back(&swapperPlus);
	swappers.push_back(&swapperMinus);
	swappers.push_back(&swapperTimes);
	swappers.push_back(&swapperDivide);

	swappersMap["PLUS"] = &swapperPlus;
	swappersMap["MINUS"] = &swapperMinus;
	swappersMap["TIMES"] = &swapperTimes;
	swappersMap["DIVIDE"] = &swapperDivide;
}

void SwappingBuilder::randomLeaf(Tree* tree) {
	std::vector<Node*> leaves;
	findLeaves(tree->getHead(), leaves);

	int leavesSize = leaves.size();
	Node* leaf = leaves[random.randomInt(0,leavesSize-1)];

	return leaf;
}

void SwappingBuilder::build(Tree* tree) {
	std::vector<Node*> leaves;
	findLeaves(tree->getHead(), leaves);

	int leavesSize = leaves.size();
	Node* leaf = leaves[random.randomInt(0,leavesSize-1)];

	std::vector<Swapper*> potSwappers;

	for (Swapper* swapper: swappers) {
		if (swapper->canSwap(leaf)) {
			potSwappers.push_back(swapper);
		}
	}

	int swappersSize = potSwappers.size();

	if (swappersSize < 1) return;

	Swapper* swapper = potSwappers[random.randomInt(0,swappersSize-1)];

	swapper->swap(leaf);
}

void SwappingBuilder::enableSwapper(std::string name) {
	if (swappersMap.find(name) == swappersMap.end()) return;
	swappersMap[name]->setEnabled(true);
}

void SwappingBuilder::findLeaves(Node* node, std::vector<Node*>& leaves) {
	if (node->getOperator() == NONE) {
		leaves.push_back(node);
	} else {
		findLeaves(node->getLeft(), leaves);
		findLeaves(node->getRight(), leaves);
	}
}
