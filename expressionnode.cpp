#include "expressionnode.h"
#include "expressiontree.h"
#include <cmath>

ExpressionNode::ExpressionNode()
	: expressionTree(nullptr),
	parent(nullptr),
	left(nullptr),
	right(nullptr),
	value(0),
	op(NONE),
	isVariable(false),
	variable('x')
{
}

void ExpressionNode::setExpressionTree(ExpressionTree* expressionTree) {
	this->expressionTree = expressionTree; 
}
void ExpressionNode::setParent(ExpressionNode* parent) {
	this->parent = parent; 
}
void ExpressionNode::setLeft(ExpressionNode* left) {
	left->setParent(this);
	this->left = left; 
}
void ExpressionNode::setRight(ExpressionNode* right) {
	right->setParent(this);
	this->right = right; 
}
void ExpressionNode::setValue(int value) {
	this->value = value; 
}
void ExpressionNode::setOperator(int op) {
	this->op = op; 
}

void ExpressionNode::setLeftRight(ExpressionNode* left, ExpressionNode* right) {
	setLeft(left);
	setRight(right);
}

void ExpressionNode::setIsVariable(bool b) {
	this->isVariable = b;
}

void ExpressionNode::setVariable(char variable) {
	this->variable = variable;
}

ExpressionTree* ExpressionNode::getExpressionTree() { return expressionTree; }
ExpressionNode* ExpressionNode::getParent() { return parent; }
ExpressionNode* ExpressionNode::getLeft() { return left; }
ExpressionNode* ExpressionNode::getRight() { return right; }
int ExpressionNode::getValue() { return value; }
int ExpressionNode::getOperator() { return op; }

bool ExpressionNode::getIsVariable() {
	return isVariable;
}

char ExpressionNode::getVariable() {
	return variable;
}

ExpressionNode* ExpressionNode::makeLeft() {
	ExpressionNode* left = expressionTree->getNextNode();
	setLeft(left);
	return left;
}

ExpressionNode* ExpressionNode::makeRight() {
	ExpressionNode* right = expressionTree->getNextNode();
	setRight(right);
	return right;
}

void ExpressionNode::makeLeftRight(ExpressionNode*& left, ExpressionNode*& right) {
	left = makeLeft();
	right = makeRight();
}

void ExpressionNode::calculate() {
	if (left!=nullptr) left->calculate();
	if (right!=nullptr) right->calculate();

	switch (op) {
		case NONE:
			//	nothing to be done
			break;
		case PLUS:
			value = left->getValue() + right->getValue();
			break;
		case MINUS:
			value = left->getValue() - right->getValue();
			break;
		case TIMES:
			value = left->getValue() * right->getValue();
			break;
		case DIVIDE:
			value = left->getValue() / right->getValue();
			break;
		case FRAC:
			value = left->getValue() / right->getValue();
			break;
		case EXP:
			value = pow(left->getValue(), right->getValue());
			break;
		case ROOT:
			break;
		default:
			break;
	}
}

bool ExpressionNode::needsBrackets() {
	return false;
}
