#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

class ExpressionTree;

class ExpressionNode {

	public:
		ExpressionNode();

		enum Operator {
			NONE = 0,	//	just the value, no subexpressions
			PLUS,
			MINUS,
			TIMES,
			DIVIDE,
			FRAC,
			EXP,
			ROOT
		};

		void setExpressionTree(ExpressionTree* expressionTree);
		void setParent(ExpressionNode* parent);
		void setLeft(ExpressionNode* left);
		void setRight(ExpressionNode* right);
		void setValue(int value);
		void setOperator(int op);
		void setLeftRight(ExpressionNode* left, ExpressionNode* right);
		void setIsVariable(bool b);
		void setVariable(char variable);

		ExpressionTree* getExpressionTree();
		ExpressionNode* getParent();
		ExpressionNode* getLeft();
		ExpressionNode* getRight();
		int getValue();
		int getOperator();
		bool getIsVariable();
		char getVariable();

		ExpressionNode* makeLeft();
		ExpressionNode* makeRight();
		void makeLeftRight(ExpressionNode*& left, ExpressionNode*& right);

		/*	Recursively calculate children using operator.
		 */
		void calculate();

		bool needsBrackets();

	private:
		ExpressionTree* expressionTree;
		ExpressionNode* parent;
		ExpressionNode* left;
		ExpressionNode* right;
		int value;
		int op;
		char variable;

		//	whether this node must be displayed as a variable (op must be NONE)
		bool isVariable;
};

#endif
