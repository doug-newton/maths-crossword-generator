#ifndef FORMULA_H
#define FORMULA_H

/*	A formula is used in equations and sequences.
 *	It allows for subsitution within an expression tree.
 */

#include "expressiontree.h"
#include <vector>
#include <string>
#include <map>

class Formula {

	public:
		Formula();

		/*	Doesn't generate by itself yet. (Or doesn't need to)
		 */
		void generate(std::vector<std::string>& args);
		void setVariableNode(ExpressionNode* node, char variable);
		void setVariableValue(char variable, int value);
		void calculate();
		int getValue();

		ExpressionTree& getExpressionTree();

	private:
		ExpressionTree expressionTree;
		ExpressionNode* variableNode;

		std::map<char, std::vector<ExpressionNode*> > variablesMap;

		void addVariable(char variable, ExpressionNode* expressionNode);
};

#endif
