#include "node.h"
#include <iostream>
#include "tree.h"

Node::Node():
	tree(nullptr),
	parent(nullptr),
	left(nullptr),
	right(nullptr),
	value(0),
	op(NONE)
{
}

bool Node::needsBrackets() {
	if (parent==nullptr) return false;
	if (op==NONE) return false;

	bool isLeft = parent->getLeft() == this;
	bool isRight = parent->getRight() == this;

	int parentOp = parent->getOperator();

	switch (parentOp) {
		case PLUS:
			return false;
		case MINUS:
			if (isRight && (op == PLUS || op == MINUS) ) 
				return true;
			break;
		case TIMES:
			if (op == PLUS || op == MINUS) 
				return true;
			break;
		case DIVIDE:
			if (isRight) return true;
			if (isLeft && (op == PLUS || op == MINUS))
				return true;
			break;
		default:
			break;
	}

	return false;
}

std::string Node::toString() {
	std::stringstream stream;

	switch (op) {
		case NONE:
			stream << value;
			break;

		case PLUS:
			stream << left->toString() << " + " << right->toString();
			break;

		case MINUS:
			stream << left->toString() << " - " << right->toString();
			break;

		case TIMES:
			stream << left->toString() << " * " << right->toString();
			break;

		case DIVIDE:
			stream << left->toString() << " / " << right->toString();
			break;

		default:
			break;
	}

	std::string str = stream.str();

	if (needsBrackets()) str = "(" + str + ")";
	return str;
}

void Node::calculate() {

	if (left != nullptr) left->calculate();
	if (right != nullptr) right->calculate();

	switch (op) {
		case NONE:
			break;

		case PLUS:
			value = left->value + right->value;
			break;

		case MINUS:
			value = left->value - right->value;
			break;

		case TIMES:
			value = left->value * right->value;
			break;

		case DIVIDE:
			value = left->value / right->value;
			break;

		default:
			break;
	}
}

void Node::setTree(Tree* tree) { this->tree = tree; } 
void Node::setParent(Node* parent) { this->parent = parent; } 
void Node::setLeft(Node* left) { 
	this->left = left; 
	left->setParent(this); 
	left->setTree(tree);
}
void Node::setRight(Node* right) { 
	this->right = right; 
	right->setParent(this); 
	right->setTree(tree);
}
void Node::setValue(int value) { this->value = value; }
void Node::setOperator(int op) { this->op = op; }

Tree* Node::getTree() { return tree; }
Node* Node::getParent() { return parent; }
Node* Node::getLeft() { return left; }
Node* Node::getRight() { return right; }
int Node::getValue() { return value; }
int Node::getOperator() { return op; }
