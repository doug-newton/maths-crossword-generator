#include "formula.h"

Formula::Formula():
	variableNode(nullptr)
{
}

void Formula::generate(std::vector<std::string>& args) {
}

void Formula::setVariableNode(ExpressionNode* node, char variable) {
	this->variableNode = node;
	node->setIsVariable(true);
	node->setVariable(variable);
	addVariable(variable, node);
}

void Formula::setVariableValue(char variable, int value) {
	if (variablesMap.find(variable) == variablesMap.end()) return;
	std::vector<ExpressionNode*>& variableNodeList = variablesMap[variable];
	for (ExpressionNode* expressionNode: variableNodeList) {
		expressionNode->setValue(value);
	}
}

void Formula::calculate() {
	expressionTree.getHead()->calculate();
}

int Formula::getValue() {
	return expressionTree.getHead()->getValue();
}

ExpressionTree& Formula::getExpressionTree() {
	return expressionTree;
}

void Formula::addVariable(char variable, ExpressionNode* expressionNode) {
	std::vector<ExpressionNode*>* variableNodeList = nullptr;

	if (variablesMap.find(variable) == variablesMap.end()) {
		variablesMap[variable] = std::vector<ExpressionNode*>();
	}

	variableNodeList = &variablesMap[variable];
	variableNodeList->push_back(expressionNode);
}
