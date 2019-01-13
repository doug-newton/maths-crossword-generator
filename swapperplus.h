#ifndef SWAPPERPLUS_H
#define SWAPPERPLUS_H

#include "swapper.h"

class SwapperPlus: public Swapper {

	public:
		virtual bool canSwap(Node* node);
		virtual void swap(Node* node);

	private:
		Node* makePlusExpression(Node* node);
};

#endif	//	SWAPPERPLUS_H
