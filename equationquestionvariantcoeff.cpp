#include "equationquestionvariant.h"

EquationQuestionVariantCoeff::EquationQuestionVariantCoeff(
		std::vector<std::string>& args,
		EquationQuestion* question)
{
	Formula& formula = question->getFormula();
	ExpressionTree& expressionTree = formula.getExpressionTree();
	Random& random = question->getRandom();

	int coefficient = random.randomInt(2,10);
	int constant = random.randomInt(2,10);
	int xValue = random.randomInt(-10,10);

	ExpressionNode* head = expressionTree.getHead();
	head->setOperator(ExpressionNode::Operator::PLUS);

	ExpressionNode *a, *b;
	head->makeLeftRight(a,b);
	b->setValue(constant);

	a->setOperator(ExpressionNode::Operator::TIMES);
	ExpressionNode *c, *x;
	a->makeLeftRight(c,x);

	c->setValue(coefficient);
	x->setValue(xValue);

	formula.setVariableNode(x, 'x');

	formula.calculate();
}
