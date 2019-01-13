#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <vector>
#include "expressionnode.h"

class ExpressionTree {

	public:
		ExpressionTree();

		ExpressionNode* getHead();
		ExpressionNode* getNextNode();

		void calculate();
		int getValue();
		int getSize();

		/*	Get the node at the index but first set it's expressionTree pointer.
		 */
		ExpressionNode* getNode(int index);

		/*	Whether the tree has run out of empty nodes.
		 */
		bool isFull();

	private:
		int totalNodes;
		int lastNodeIndex;
		int size;
		std::vector<ExpressionNode> expressionNodes;
};

#endif
