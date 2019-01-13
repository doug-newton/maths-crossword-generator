#include "expressiontree.h"
#include <iostream>
#include "latexexpressiontreeformatter.h"
#include "latexformatter.h"

LatexFormatter latexFormatter;

void printTree(ExpressionTree& expressionTree) {
	expressionTree.calculate();
	ExpressionTreeFormatter* treeFormatter = latexFormatter.getExpressionTreeFormatter();
	std::cout << treeFormatter->strExpressionTree(&expressionTree) << std::endl;
	std::cout << expressionTree.getValue() << std::endl;
}

void test1() {
	ExpressionTree expressionTree;

	ExpressionNode* head = expressionTree.getHead();

	ExpressionNode *a, *b;
	head->makeLeftRight(a, b);
	head->setOperator(ExpressionNode::Operator::TIMES);

	ExpressionNode *c, *d;
	a->makeLeftRight(c,d);
	a->setOperator(ExpressionNode::Operator::MINUS);
	c->setValue(4);
	d->setValue(2);

	ExpressionNode *e, *f;
	b->makeLeftRight(e,f);
	b->setOperator(ExpressionNode::Operator::PLUS);
	e->setValue(4);
	f->setValue(2);

	for (int i=0; i<10; i++) {
		e->setValue(i);
		printTree(expressionTree);
	}
}

void test2() {
	ExpressionTreeFormatter* treeFormatter = latexFormatter.getExpressionTreeFormatter();
	ExpressionTree expressionTree;



	std::cout << treeFormatter->strExpressionTree(&expressionTree) << std::endl;
	std::cout << expressionTree.getValue() << std::endl;
}

void testExpressionTree() {
	test1();
}
