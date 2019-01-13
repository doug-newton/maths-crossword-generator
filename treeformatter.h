#ifndef TREEFORMATTER_H
#define TREEFORMATTER_H

#include "questionformatter.h"

class Tree;
class Node;

class TreeFormatter: public QuestionFormatter {

	public:
		TreeFormatter(Formatter* formatter);
		virtual void formatTree(Tree* tree)=0;
		virtual std::string strTree(Tree* tree)=0;
};

#endif
