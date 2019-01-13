#ifndef NODE_H
#define NODE_H

#include <sstream>

class Tree;

enum Operator {
	NONE = 0,
	PLUS,
	MINUS,
	TIMES,
	DIVIDE
};

class Node {

	public:
		Node();

		bool needsBrackets();
		std::string toString();
		void calculate();

		void setTree(Tree* tree);
		void setParent(Node* parent);
		void setLeft(Node* left);
		void setRight(Node* right);
		void setValue(int value);
		void setOperator(int op);

		Tree* getTree();
		Node* getParent();
		Node* getLeft();
		Node* getRight();
		int getValue();
		int getOperator();

		bool isVariable;

	private:
		Tree* tree;
		Node* parent;
		Node* left;
		Node* right;
		int value;
		int op;
};

#endif
