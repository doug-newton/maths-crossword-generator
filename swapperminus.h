#ifndef SWAPPERMINUS_H
#define SWAPPERMINUS_H

#include "swapper.h"

class SwapperMinus: public Swapper {

	public:
		virtual bool canSwap(Node* node);
		virtual void swap(Node* node);

	private:
		Node* makeMinusExpression(Node* node);
};

#endif	//	SWAPPERMINUS_H
