#ifndef SWAPPERDIVIDE_H
#define SWAPPERDIVIDE_H

#include "swapper.h"

class SwapperDivide: public Swapper {

	public:
		virtual bool canSwap(Node* node);
		virtual void swap(Node* node);

	private:
		Node* makeDivideExpression(Node* node);
};

#endif
