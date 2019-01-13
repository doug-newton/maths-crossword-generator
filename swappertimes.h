#ifndef SWAPPERTIMES_H
#define SWAPPERTIMES_H

#include "swapper.h"
#include "factorfinder.h"

class SwapperTimes: public Swapper {

	public:
		virtual bool canSwap(Node* node);
		virtual void swap(Node* node);

	private:
		Node* makeTimesExpression(Node* node);
		FactorFinder factorFinder;
};

#endif
